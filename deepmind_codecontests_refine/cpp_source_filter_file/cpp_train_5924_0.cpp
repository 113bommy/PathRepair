#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

int h,w,n,c[1000][1000];
int dp[1001][1001];
int d[1000][1000];

int main(){
	while(scanf("%d%d%d",&h,&w,&n),h){
		for(int i=0;i<h;i++) for(int j=0;j<w;j++) scanf("%d",&c[i][j]);
		for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++) dp[i][j]=0;
		dp[1][1]=n-1;
		for(int i=1;i<=h;i++) for(int j=1;j<=w;j++){
			if(i!=1){
				if(c[i-2][j-1]==0) dp[i][j]+=(dp[i-1][j]+1)/2;
				else dp[i][j]+=dp[i-1][j]/2;
			}
			if(j!=1){
				if(c[i-1][j-2]==1) dp[i][j]+=(dp[i][j-1]+1)/2;
				else dp[i][j]+=dp[i][j]/2;
			}
		}
		for(int i=0;i<h;i++) for(int j=0;j<w;j++)
			d[i][j]=(c[i][j]+dp[i+1][j+1])%2;
		int i=1,j=1;
		while(i<=h&&j<=w){
			if(d[i-1][j-1]) j++;
			else i++;
		}
		printf("%d %d\n",i,j);
	}