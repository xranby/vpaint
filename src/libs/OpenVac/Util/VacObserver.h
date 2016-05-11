// Copyright (C) 2012-2016 The VPaint Developers.
// See the COPYRIGHT file at the top-level directory of this distribution
// and at https://github.com/dalboris/vpaint/blob/master/COPYRIGHT
//
// This file is part of VPaint, a vector graphics editor. It is subject to the
// license terms and conditions in the LICENSE.MIT file found in the top-level
// directory of this distribution and at http://opensource.org/licenses/MIT

#ifndef VACOBSERVER_H
#define VACOBSERVER_H

#include <OpenVac/Core/CellId.h>

#include <unordered_set>

namespace OpenVac
{

class Vac;

/// \class VacObserver
/// \brief Implementation of the observer pattern for the Vac class.
///
class VacObserver
{
public:
    /// Notifies whenever the topology has changed.
    ///
    /// You must not attempt to modify the topology in this callback method.
    ///
    /// Note that this topologyChanged returns IDs, while geometryChanged
    /// returns handles. Ideally, returning handles is better, but it cannot
    /// be done for topologyChanged since the handles of destroyed cells
    /// wouldn't be valid. It would be possible to return handles for
    /// created and affected cells, but for consistency we return IDs
    /// for all.
    ///
    virtual void topologyChanged(
            const std::unordered_set<OpenVac::CellId> & /*created*/,
            const std::unordered_set<OpenVac::CellId> & /*destroyed*/,
            const std::unordered_set<OpenVac::CellId> & /*affected*/)
    {
        // Empty implementation
    }

    /// Notifies whenever the geometry has changed. Note that changing
    /// the geometry of a cell often affects the geometry of incident cells as
    /// well. For instance, sculpting a key edge affects the geometry of all
    /// inbetween edges that interpolate it, and of all key faces that it
    /// supports.
    ///
    /// The topologyChanged() notification is always followed by the
    /// geometryChanged() notification, but geometryChanged() may be sent
    /// individually.
    ///
    /// You must not attempt to modify the geometry in this callback method.
    ///
    virtual void geometryChanged(
            const std::unordered_set<CellHandle> & /*affected*/)
    {
        // Empty implementation
    }
};

}

#endif // VACOBSERVER_H