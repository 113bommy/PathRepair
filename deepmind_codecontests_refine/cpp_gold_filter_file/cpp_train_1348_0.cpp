#include<stdio.h>
#include<algorithm>
using namespace std;
int b[100];
int d[110];
int dp[110][31];
int main(){
	int a;
	while(scanf("%d",&a),a){
		for(int i=0;i<a;i++)scanf("%d",b+i);
		int c;scanf("%d",&c);
		for(int i=0;i<110;i++)d[i]=-1;
		for(int i=0;i<c;i++){
			int p,q;scanf("%d%d",&p,&q);
			p--;
			if(!~d[p]||d[p]>q)d[p]=q;
		}
		for(int i=0;i<110;i++)for(int j=0;j<31;j++)dp[i][j]=999999999;
		dp[0][0]=0;
		for(int i=0;i<100;i++){
			for(int j=0;j<a;j++){
		//		printf("%d %d: %d\n",i,j,dp[i][j]);
				if(!~d[i]||b[j]<=d[i])dp[i+1][(j+1)%a]=min(dp[i+1][(j+1)%a],dp[i][j]);
				dp[i+1][1%a]=min(dp[i+1][1%a],dp[i][j]+1);
			}
		}
		int ret=999999999;
		for(int i=0;i<a;i++)ret=min(ret,dp[100][i]);
		printf("%d\n",ret);
	}
}