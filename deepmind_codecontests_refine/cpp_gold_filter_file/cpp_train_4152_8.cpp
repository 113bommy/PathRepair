#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	double x[20], y[20], a, b, c, s = 0.0, z;
	int i;
	for (i = 0; i < 20; i++){
		if (scanf("%lf,%lf", &x[i], &y[i]) == EOF) break;
	}
	for (int j = 1; j < i - 1; j++){
		a = sqrt((x[j] - x[0]) * (x[j] - x[0]) + (y[j] - y[0]) * (y[j] - y[0]));
		b = sqrt((x[j + 1] - x[0]) * (x[j + 1] - x[0]) + (y[j + 1] - y[0]) * (y[j + 1] - y[0]));
		c = sqrt((x[j + 1] - x[j]) * (x[j + 1] - x[j]) + (y[j + 1] - y[j]) * (y[j + 1] - y[j]));
		z = (a + b + c) / 2.0;
		s += sqrt(z * (z - a) * (z - b) * (z - c));
	}
	printf("%.5f\n",s);
	return 0;
}