#include<bits/stdc++.h>
using namespace std;
long long k,n,m,ans,s,d;
int main()
{
	cin>>k>>n>>m;
	if(k<=n)
	{
		cout<<'1'<<endl;
		goto A;
	}
	if(n<=m)
	{
		cout<<"-1"<<endl;
		goto A;
	}
	s=n-m;
	d=k-n;
	if(d%s==0)
	{
		ans=d/s;
	}
	else
	{
		ans=d/s+1;
	}
	ans*=2;
	cout<<ans+1;
	A: return 0;
}
