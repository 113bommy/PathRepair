#include<bits/stdc++.h>
using namespace std;

template<typename t>void chkmin(t&a,t b){if(a>b)a=b;}

typedef long long ll;
const int maxn=1e5+10;
int n,t,e,x[maxn],end=0;
ll dp[maxn],val=1e18;

int main(){
	cin>>n>>e>>t;
	for(int i=1;i<=n;++i){
		dp[i]=1e18;
		cin>>x[i];
		while(end<i&&2*(x[i]-x[end+1])>=t)
			chkmin(val,dp[end]-2*x[end+1]),++end;
		chkmin(dp[i],val+2*x[i]);
		if(end<i)
			chkmin(dp[i],dp[end]+t);
	}
	printf("%lld\n",dp[n]+e);
	return 0;
}