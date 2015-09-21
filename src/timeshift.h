/*
 *  TV headend - Timeshift
 *  Copyright (C) 2012 Adam Sutton
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __TVH_TIMESHIFT_H__
#define __TVH_TIMESHIFT_H__

#include "idnode.h"

typedef struct timeshift_conf {
  idnode_t  idnode;
  int       enabled;
  int       ondemand;
  char     *path;
  int       unlimited_period;
  uint32_t  max_period;
  int       unlimited_size;
  uint64_t  max_size;
  uint64_t  total_size;
  uint64_t  ram_size;
  uint64_t  ram_segment_size;
  uint64_t  total_ram_size;
  int       ram_only;
} timeshift_conf_t;

extern struct timeshift_conf timeshift_conf;
extern const idclass_t timeshift_conf_class;

typedef struct timeshift_status
{
  int     full;
  int64_t shift;
  int64_t pts_start;
  int64_t pts_end;
} timeshift_status_t;

void timeshift_init ( void );
void timeshift_term ( void );

streaming_target_t *timeshift_create
  (streaming_target_t *out, time_t max_period);

void timeshift_destroy(streaming_target_t *pad);

#endif /* __TVH_TIMESHIFT_H__ */
