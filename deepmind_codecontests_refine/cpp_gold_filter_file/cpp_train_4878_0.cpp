#include<bits/stdc++.h>
using namespace std;
const int N=105,M=1e9+7;
int n,m,a[N],dp[N][N][N];
int main(){
	scanf("%d",&n);
	m=(n<<1)-1;
	for (int i=1;i<=m;i++)scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	dp[1][1][1]=1;
	for (int i=1;i<n;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<=j;k++){
				int x=j,y=k;
				if (a[n-i]!=a[n-i+1])x++,y++;
				if (a[n+i]!=a[n+i-1])x++;
				for (int l=1;l<y;l++)(dp[i+1][x-(y-l-1)][l]+=dp[i][j][k])%=M;
				(dp[i+1][x][y]+=dp[i][j][k])%=M;
				for (int l=y+1;l<=x;l++)(dp[i+1][x-(l-y-1)][y+1]+=dp[i][j][k])%=M;
			}
	int ans=0;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=i;j++)(ans+=dp[n][i][j])%=M;
	printf("%d\n",ans);
	return 0;
}
