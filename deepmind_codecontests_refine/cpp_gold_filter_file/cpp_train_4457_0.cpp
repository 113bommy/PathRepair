#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 100000000

int dp[2][51][5001];

int main() {
	
	int N,K;
	cin>>N>>K;
	
	dp[0][0][2500] = 1;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<=N;j++){
			for(int v=0;v<=5000;v++){
				if(dp[0][j][v]==0)continue;
				
				dp[1][j][v] = mod(dp[0][j][v] + dp[1][j][v]);
				
				if(j!=N){
					dp[1][j+1][v-2*(i+1)] = mod(dp[1][j+1][v-2*(i+1)] + dp[0][j][v]);
				}
				
				if(j!=0){
					dp[1][j-1][v+2*(i+1)] = mod(dp[1][j-1][v+2*(i+1)] + mod(j*j*dp[0][j][v]));
				}
				
				dp[1][j][v] = mod(dp[1][j][v] + mod(dp[0][j][v] * j*2));
			}
		}
		swap(dp[0],dp[1]);
		for(int j=0;j<=N;j++){
				for(int v=0;v<=5000;v++){
					dp[1][j][v]=0;
				}
		}
	}
	
	cout<<dp[0][0][K+2500]<<endl;
	
    return 0;
}
