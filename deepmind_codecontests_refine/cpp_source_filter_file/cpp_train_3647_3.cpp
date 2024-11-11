#include<stdio.h>
#define PI 3.14159265359u
  
int main(void){
  double r;
  
  scanf("%lf",&r);
  printf("%lf %lf",r*r*PI,2*r*PI);
  return 0;
}