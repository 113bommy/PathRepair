#include <bits/stdc++.h>
#define ll long long
#define INF 999999999
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 15;
const int MAX_M = 225;

int n,m;
ll dp[1 << MAX_N][MAX_N];
ll d[MAX_N][MAX_N];
int s[MAX_M];
int t[MAX_M];
int D[MAX_M];

ll solve()
{
	rep(S,1<<n){
		fill(dp[S],dp[S]+n,INF);
	}
	dp[(1<<n)-1][0] = 0;
	for(int S=(1<<n)-2;S>=0;S--){
		rep(v,n){
			rep(u,n){
				if(!(S>>u&1)){
					dp[S][v] = min(dp[S][v],dp[S|1<<u][u] + d[v][u]);
				}
			}
		}
	}
	return dp[0][0];
}

int main()
{
	ll ans=INF-1;
	cin >> n >> m;
	rep(i,m){
		cin >> s[i] >> t[i] >> D[i];
	}
	rep(i,n){
		fill(d[0],d[n],INF);
		rep(j,m){
			d[(s[j]+n-i)%n][(t[j]+n-i)%n] = D[j];
		} 
		ans = min(ans,solve());
	}
	if(ans > 16000){
		cout << "-1\n";
	}else{
		cout << ans << "\n";
	}
}