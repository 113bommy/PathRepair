#include<stdio.h>
#include<math.h>

double r;

int main(){
  scanf("%lf", &r);
  printf("%lf %lf\n", r*r*M_PI, 2.*r*M_PI);
  return 0;
}