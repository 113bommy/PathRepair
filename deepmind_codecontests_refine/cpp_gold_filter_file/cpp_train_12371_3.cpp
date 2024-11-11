#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int cnt[N],v[N],dp[N];
int dfs(int s)
{
	if(s==0) return 0;
	if(dp[s]!=-1) return dp[s];
	dp[s]=0x3f3f3f3f;
	for(int i=0;i<16;i++)
	{
		if(s>>i&1)
		{
			for(int j=0;j<16;j++)
			{
				if(s>>j&1)
				{
					int x=i^j;int ns=s^(1<<i)^(1<<j)^(1<<x);
					if(__builtin_popcount(ns)<__builtin_popcount(s))
					 dp[s]=min(dp[s],dfs(ns)+1+((s&(1<<x))==(1<<x)));
				}
			} 
	    }
	}
	return dp[s];
}
int main()
{
	int n;
	cin>>n;
	for(int i=1,x,y,z;i<n;i++)
	{
		cin>>x>>y>>z;
		v[x]^=z;
		v[y]^=z;
	}
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++)
	 if(v[i]) cnt[v[i]]++;
	int st=0,ans=0;
	for(int i=1;i<16;i++)
	{
		ans+=cnt[i]/2;
		st|=(cnt[i]&1)*(1<<i);
	} 
	ans+=dfs(st);
	cout<<ans<<endl;
	return 0;
}