#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define rep(i,n) for(int i=0;i<(n);i++)

	vector<vector<int>>rate(2,vector<int>(3,0));

	int solve(int n,int pre,int post){
		vector<int>dp(n+1,0);
		rep(i,n)dp[i]=i;
		rep(i,n+1)rep(j,m)if(i>=rate[pre][j]&&rate[pre][j]<rate[post][j])dp[i]=max(dp[i],dp[i-rate[pre][j]]+rate[post][j]);
		return dp[n];
	}

signed main(){
	int n;cin>>n;
	rep(i,2)rep(j,3)cin>>rate[i][j];
	cout<<solve(solve(n,0,1),1,0)<<endl;

	
}