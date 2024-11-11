#include "bits/stdc++.h"
using namespace std;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
#define P pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define print(n) cout<<n<<endl
const int M=100010;
const int MOD=1000000007;
const int inf=1000000007;
const long long INF=1000000000000000007;
using ll=long long;


int main(){
	ll n,m,a,b,c;
	ll dp[1010][1010]={};
	cin>>n>>m;
	rep(i,1,n+1)rep(j,1,n+1){
		if(i!=j)dp[i][j]=-INF;
	}
	rep(i,0,m)cin>>a>>b>>c,dp[a][b]=c;
	rep(k,1,n+1)rep(i,1,n+1){
		if(dp[i][k]==-INF)continue;
		rep(j,1,n+1)if(dp[i][k]+dp[k][j]>dp[i][j])
			dp[i][j]=dp[i][k]+dp[k][j];
	}
	dp[1][1]>0?print("inf"):print(dp[1][n]);
	return 0;
}