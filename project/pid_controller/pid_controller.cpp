/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  Kp =Kpi;
  Kd = Kdi;
  Ki = Kii;
  output_lim_max =output_lim_maxi;
  output_lim_min = output_lim_mini;
  
  ctep =0.0;
  cted =0.0;
  ctei =0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  cted = cte - ctep;
  ctei += cte;
  ctep=cte;
  
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control;
  	control = Kp*cte +Kd*cted +Ki*ctei;
  	control =max(min(control,output_lim_max),output_lim_min);
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  dt =new_delta_time;
}