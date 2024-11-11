//https://atcoder.jp/contests/nomura2020/tasks/nomura2020_d
#include<bits/stdc++.h>
using namespace std;
#define nn 5008
#define mod 1000000007
#define int long long 
vector<int> v[nn];int n,pa[nn];
int unknown[nn];int og[nn];
int find(int x){
	if(pa[x]==x) return x;
	return pa[x]=find(pa[x]);	
}
void link(int x,int y){
	pa[find(x)]=find(y);
}
int qpow(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;y=y/2;
	}
	return res;
}
void add(int&x,int y){
	x=(x+y)%mod;
}

int dp[nn],sze[nn],ans,f[nn];;
signed main(){
	f[0]=1;for(int i=1;i<nn;i++) f[i]=f[i-1]*i%mod;
	scanf("%lld",&n);for(int i=1;i<=n;i++) pa[i]=i;int uk=0;
	for(int i=1;i<=n;i++){
		int pp;scanf("%lld",&pp);
		if(pp==-1) og[i]=1,uk++;
		else link(pp,i);
	}
	for(int i=1;i<=n;i++) unknown[find(i)]+=og[i],sze[find(i)]++;
	for(int i=1;i<=n;i++) if(i==find(i) and !unknown[i]) ans+=qpow(n-1,uk),ans%=mod;
	vector<int> dope;
	for(int i=1;i<=n;i++) if(find(i)==i and unknown[i]) dope.push_back(sze[i]),add(ans,(sze[i]-1)*qpow(n-1,uk-1));
	
	
	dp[0]=1;for(int i=0;i<dope.size();i++) for(int j=nn-2;j>=0;j--) add(dp[j+1],dp[j]*dope[i]);
	
	for(int i=2;i<nn;i++) add(ans,dp[i]*f[i-1]%mod*qpow(n-1,uk-i));
			
		
	ans=qpow(n-1,uk)*n-ans;ans%=mod;ans+=mod;ans%=mod;cout<<ans;
	return 0;
} 