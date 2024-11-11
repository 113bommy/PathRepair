#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

#define int long long 

using namespace std;

int a[20],n;

int f(int l,int r,int xl,int xr)
{
	int i,j;
	if(r-l<=1) return 0;
	int ans=0x3f3f3f3f3f3f3f3f;
	for(i=l+1;i<r;i++)
	{
		ans=min(ans,f(l,i,xl,xl+xr)+f(i,r,xl+xr,xR)+a[i]*(xl+xr));
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	register int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	cout<<a[1]+a[n]+f(1,n,1,1);
}
