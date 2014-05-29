/*************************************************************************
This software allows for filtering in high-dimensional measurement and
state spaces, as described in

M. Wuthrich, P. Pastor, M. Kalakrishnan, J. Bohg, and S. Schaal.
Probabilistic Object Tracking using a Range Camera
IEEE/RSJ Intl Conf on Intelligent Robots and Systems, 2013

In a publication based on this software pleace cite the above reference.


Copyright (C) 2014  Manuel Wuthrich

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*************************************************************************/

#ifndef DIRINI_MACROS_HPP_
#define DIRINI_MACROS_HPP_

#include <sys/time.h>
#include <iostream>
#include <boost/current_function.hpp>
#include <time.h>

#define PROFILING_ON

#ifdef PROFILING_ON
	#define INIT_PROFILING struct timeval profiling_start_time, profiling_end_time; gettimeofday(&profiling_start_time, NULL);
	#define RESET gettimeofday(&profiling_start_time, NULL);
	#define MEASURE(text) 	gettimeofday(&profiling_end_time, NULL); std::cout << "time for " << text << " " \
	<< ((profiling_end_time.tv_sec - profiling_start_time.tv_sec) * 1000000u + profiling_end_time.tv_usec - profiling_start_time.tv_usec) /1000000. \
	<< " s" << endl; gettimeofday(&profiling_start_time, NULL);
#else
	#define INIT_PROFILING
	#define RESET
	#define MEASURE(text)
#endif

#define PRINT_VARIABLE(variable) std::cout << "--------------------------------------" << std::endl << \
#variable  << ": " << std::endl << variable << std::endl \
<< "--------------------------------------" << std::endl;

#define TO_BE_IMPLEMENTED  std::cout << "The function " << BOOST_CURRENT_FUNCTION << \
	" has not been implemented yet." << std::endl; exit(-1);

#ifndef USE_UNTESTED_FUNCTIONS
#define TO_BE_TESTED  std::cout << "The function " << BOOST_CURRENT_FUNCTION << \
	" has not been tested yet." << std::endl; exit(-1);
#else
#define TO_BE_TESTED
#endif


#define RANDOM_SEED 1
//(unsigned)time(0)


#endif
