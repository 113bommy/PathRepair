#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,M;cin>>N>>M;
    const int mod 1e9+7;
	int A[M];
	for(int i=0;i<M;i++){
		cin>>A[i];
	}
	int dp[N+1];dp[0]=1;
	int j;
	if(A[0]==1){
		j=1;
		dp[1]=0;
	}else{
		j=0;
		dp[1]=1;
	}for(int i=2;i<=N;i++){
		if(i==A[j]){
			dp[i]=0;
			if(j<M-1) j++;
		}else{
			dp[i]=(dp[i-1]+dp[i-2])%mod;
		}
	}cout<<dp[N]<<endl;
}