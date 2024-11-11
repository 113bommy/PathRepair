#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main()
{
	long long n,ba=1;
	cin>>n;
	for(int t=0;t<n;t++)
	{
		cin>>a[t];
		if(a[t]==0)
		{
			cout<<0;
			return 0;
		}
	}
	for(int t=0;t<n;t++)
	{
		if((long double)(ba)>1000000000000000000.0/(long double)(a[t]))
		{
			cout<<"-1";
			return 0;
		}

		ba*=a[t];
	}
	cout<<ba;
	return 0;
}