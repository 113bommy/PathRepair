#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>
int main() {
	double a;
	scanf_s("%lf",&a);
	printf("%f %f\n", a*a*M_PI, a * 2 * M_PI);
}