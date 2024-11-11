#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int l=2,r=2;
	for(int i=n;i>=1;i--)
	{
		int mn,mx;
		if(l%a[i]==0)mn=l/a[i];
		else mn=l/a[i]+1;
		mx=r/a[i];
		if(l>r)return puts("-1"),0;
		l=mn*a[i];r=(mx+1)*a[i]-1;
	}
	cout<<l<<' '<<r<<endl;
	return 0;
}