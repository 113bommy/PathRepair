#include <bits/stdc++.h>
using namespace std;

int main(){
	double a, b, c, C;
	double S,L,h;

	cin>>a>>b>>C;

	h = b*sin(C/180*M_PI);
	S = a * h / 2;
	c = sqrt((pow(a,2)+pow(b,2) - 2 * a * b * cos(C/180*M_PI)));
	L = a+b+c;

	printf("%10lf\n", S);
	printf("%10lf\n", L);
	printf("%10lf\n", h);
}