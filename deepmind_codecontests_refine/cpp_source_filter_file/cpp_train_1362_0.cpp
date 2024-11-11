#include<iostream>
using namespace std;
typedef unsigned long long ullong;

ullong(ullong x,ullong n,ullong M)
{
	if(n==0)return 1;
	ullong res=power(m*m%M,n/2,M);
	if(n%2==1)res=res*x%M;
	return res;
}

int main()
{
	ullong x,n;
	cin>>x>>n;
	cout<<power(x,n,1000000007)<<endl;
	return 0;
}