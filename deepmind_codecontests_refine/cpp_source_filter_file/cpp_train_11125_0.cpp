#include <bits/stdc++.h>
#define y1 __zzd001
using namespace std;
const int N=105;
int n,m,ax,ay,bx,by;
char s[N][N];
short g[N][N],dp[N][N][N][N];
short Get(int x1,int y1,int x2,int y2){
	return g[x2][y2]-g[x2][y1-1]-g[x1-1][y2]+g[x1-1][y1-1];
}
short max(short a,short b){
	return a>b?a:b;
}
short DP(int x1,int y1,int x2,int y2){
//	printf("DP %d %d %d %d\n",(int)x1,(int)y1,(int)x2,(int)y2);
	short &v=dp[x1][y1][x2][y2];
	if (~v)
		return v;
	if (x1>x2||y1>y2)
		return v=0;
	short xL=max(x2-bx+1,x1),xR=min(x1+ax-1,x2);
	short yL=max(y2-by+1,y1),yR=min(y1+ay-1,y2);
	return v=max(
			max(DP(x1,y1,x2,y2-1)+((yR==y2)?Get(xL,y2,xR,y2):0),
				DP(x1,y1+1,x2,y2)+((yL==y1)?Get(xL,y1,xR,y1):0),
			max(DP(x1,y1,x2-1,y2)+((xR==x2)?Get(x2,yL,x2,yR):0),
				DP(x1+1,y1,x2,y2)+((xL==x1)?Get(x1,yL,x1,yR):0)));
}
int main(){
	memset(g,0,sizeof g);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='o')
				g[i][j]++;
			else if (s[i][j]=='E')
				ax=i,bx=n-i+1,ay=j,by=m-j+1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			g[i][j]=g[i][j]+g[i][j-1]+g[i-1][j]-g[i-1][j-1];
	memset(dp,-1,sizeof dp);
	printf("%d",(int)DP(1,1,n,m));
	return 0;
}