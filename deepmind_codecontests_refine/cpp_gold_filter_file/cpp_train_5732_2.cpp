#include<stdio.h>
int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%d %d %.8f\n",(int)a/(int)b,(int)a%(int)b,a/b);
}