#include <iostream>
#include <cstdio>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;

typedef complex<double> P; /* ツ点 */

int main(){
	int n;
	cin>>n;
	double x1, y1, x2, y2, x3, y3;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
		double a1 = 2*(x2-x1);
		double b1 = 2*(y2-y1);
		double c1 = x1*x1-x2*x2+y1*y1-y2*y2;
		double a2 = 2*(x3-x1);
		double b2 = 2*(y3-y1);
		double c2 = x1*x1-x3*x3+y1*y1-y3*y3;
		double cx = (b1*c2-b2*c1)/(a1*b2-a2*b1);
		double cy = (c1*a2-c2*a1)/(a1*b2-a2*b1);
		P cen2 = P(cx, cy);
		double r2 = abs(p1-cen2);

		printf("%.3f %.3f %.3f\n", real(cen2), imag(cen2), r2);
	}
	return 0;
}