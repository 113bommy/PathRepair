#include<bits/stdc++.h>
using namespace std;

int main()
{
	double a,b,h,m;
	cin>>a>>b>>h>>m;

	double k = abs(h*30+(double)(m/2)-m*6);
	k = min(k,360-k);
	double pi = acos(-1.0);
	cout<<fixed<<setprecision(15)<<sqrt(abs(a*a+b*b-a*b*2*cos(k/180.0*pi)));
	return 0;
}