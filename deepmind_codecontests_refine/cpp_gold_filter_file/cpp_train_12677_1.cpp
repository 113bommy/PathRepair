#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],b[200010],sa[200010],sb[200010];
signed main()
{
	int n,m,k,i,maxv=0;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sa[i]=sa[i-1]+a[i];
	}
	for(i=1;i<=m;i++)
	{
		cin>>b[i];
		sb[i]=sb[i-1]+b[i];
	}
	for(i=0;i<=n;i++)
	{
		if(sa[i]>k)
			break;
		maxv=max(maxv,(int)(i+(upper_bound(sb+1,sb+m+1,k-sa[i])-sb)-1));
	}
	cout<<maxv;
	return 0;
}