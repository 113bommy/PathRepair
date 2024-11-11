#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint MOD=1000000007;

int main(){
	int n,m; cin>>n>>m;
	vector<int> s(n),t(m);
	rep(i,n) cin>>s[i];
	rep(i,m) cin>>t[i];

	vector<vector<lint>> dp(n+1,vector<int>(m+1));
	dp[0][0]=1;
	rep(i,n) dp[i+1][0]=1;
	rep(j,m) dp[0][j+1]=1;
	rep(i,n) rep(j,m) {
		dp[i+1][j+1]=(dp[i][j+1]+dp[i+1][j]-dp[i][j]+MOD)%MOD;
		if(s[i]==t[j]) dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%MOD;
	}
	cout<<dp[n][m]<<endl;

	return 0;
}
