#include<iostream>
using namespace std;
long long n,a,b;
int main()
{
	cin>>n>>a>>b;
	long long mn=a*(n-1)+b,mx=b*(n-1)+a;
	cout<<((a>b||(n==1&&a!=b))?0:mx-mn+1);
return 0；
}