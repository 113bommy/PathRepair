#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <LL,LL>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,t,x,y,dp[200010][40],ans=0;
vector <pii> v;
vector <LL> vv;

bool cmp(pii a,pii b)
{
	return b.fi*(a.se+1)<a.fi*(b.se+1);
}

int main()
{
	cin>>n>>t;
	rep(i,n)
	{
		cin>>x>>y;
		if(x>0) v.pb(mpr(x,y));
		else vv.pb(y);
	}
	sort(v.begin(),v.end(),cmp);
	sort(vv.begin(),vv.end());
	for(int i=1;i<vv.size();i++) vv[i]=vv[i-1]+vv[i]+1;
	rep(i,200005) rep(j,38) dp[i][j]=1e18;
	dp[0][0]=0;
	rep(i,v.size())
	{
		rep(j,35)
		{
			if(dp[i][j]==1e18) continue;
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			if(dp[i][j]+1+v[i].fi*(dp[i][j]+1)+v[i].se<=t)
			dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1+v[i].fi*(dp[i][j]+1)+v[i].se);
		}
	}
	rep(i,35)
	{
		if(dp[v.size()][i]==1e18) continue;
		ans=max(ans,i+upper_bound(vv.begin(),vv.end(),t-dp[v.size()][i]-1)-vv.begin()-1+1);
	}
	cout<<ans<<endl;
	return 0;
}