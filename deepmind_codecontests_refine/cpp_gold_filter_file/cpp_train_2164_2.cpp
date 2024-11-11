#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=55;
const int maxm=2466;
const ll inf=0x3f3f3f3f3f3f3f3f;
#define tp tuple<ll,ll,ll>

vector<tp> G[maxn];
ll c[maxn],d[maxn];
ll dp[maxn][maxm];

int main(){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	s=min(2450,s);
	for(int i=1;i<=m;i++){
		ll u,v,a,b;
		scanf("%lld%lld%lld%lld",&u,&v,&a,&b);
		G[u].push_back(tp(v,a,b)); //钱 时间 
		G[v].push_back(tp(u,a,b));
	}
	for(int i=1;i<=n;i++)
		scanf("%d%d",&c[i],&d[i]);
	fill(dp[0],dp[0]+54*2465,inf);
	dp[1][s]=0;
	
	priority_queue<tp,vector<tp>,greater<tp>> pq;
	pq.push(tp(0,1,s));
	while(!pq.empty()){
		tp cur;
		cur=pq.top();
		pq.pop();
		ll t=get<0>(cur),u=get<1>(cur),w=get<2>(cur);
		for(auto i:G[u]){
			ll v=get<0>(i),toa=get<1>(i),tob=get<2>(i);
			if(dp[v][w-toa]>t+tob&&w>=toa){
				dp[v][w-toa]=t+tob;
				pq.push(tp(t+tob,v,w-toa));
			}
		}
		if(dp[u][min(2450LL,w+c[u])]>t+d[u]){
			dp[u][min(2450LL,w+c[u])]=t+d[u];
			pq.push(tp(t+d[u],u,min(2450LL,w+c[u])));
		}
	}
	for(int i=2;i<=n;i++){
		ll ans=inf;
		for(int j=0;j<=2450;j++){
			ans=min(ans,dp[i][j]);
		}
		printf("%lld\n",ans);
	}
}