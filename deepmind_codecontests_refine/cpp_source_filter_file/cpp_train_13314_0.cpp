#include<bits/stdc++.h>
using namespace std;
int dp[2200][3200],_prev[2200][3200],n,m,s;
int main(){
	while(true){
		cin>>n>>s>>m;if(n==0)return 0;n*=n;
		for(int i=0;i<2200;i++){fill(dp[i],dp[i]+3180);fill(_prev[i],_prev[i]+3180);}
		for(int i=0;i<=s;i++)_prev[i][0]=1;
		for(int i=0;i<n;i++){
			for(int j=1;j<=s;j++){
				for(int k=j;k<=m;k++){
					dp[j][k]+=_prev[j-1][k-j];dp[j][k]%=100000;
				}
			}
			for(int j=0;j<=s;j++){
				for(int k=0;k<=m;k++){
					_prev[j][k]=dp[j][k];dp[j][k]=0;
				}
			}
			for(int j=1;j<=s;j++){
				for(int k=1;k<=m;k++){
					_prev[j][k]+=_prev[j-1][k];
				}
			}
		}
		cout<<_prev[s][m]%100000<<endl;
	}
}