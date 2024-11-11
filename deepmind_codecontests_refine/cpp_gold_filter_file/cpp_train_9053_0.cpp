#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
typedef long long ll;

int n;
ll dp[21][51][51][28];
string str[51];

ll solve(int v,int f,int t,int lb){
	if(dp[v][f][t][lb]!=-1)return dp[v][f][t][lb];
	if(f==t)return 1;
	if(str[f].size()==v){
		if(lb==0){
			return solve(v,f+1,t,lb+1);
		}
		else return 0;
	}
	for(int i=f+1;i<t;i++){
		if(str[i].size()==v)return 0;
	}
	ll ans=0;
	for(int i=max(lb,1);i<27;i++){
		for(int j=f;j<t;j++){
			if(str[j][v]!='?' && (str[j][v]-'a')!=(i-1))break;
			ans+=solve(v+1,f,j+1,0)*solve(v,j+1,t,i+1)%MOD;
			ans%=MOD;
		}
	}
	dp[v][f][t][lb]=ans;
	return ans;
}

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin >> str[i];
	}
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",solve(0,0,n,0));
	return 0;
}