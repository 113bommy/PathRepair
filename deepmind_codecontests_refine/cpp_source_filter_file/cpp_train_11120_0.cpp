#include <bits/stdc++.h>
using namespace std;
int n,d,x,y,t,mx,v[2005][2005],s[2][2005][2005];
int S(int a1,int b1,int a2,int b2,int t){return s[t][a2][b2]-s[t][a1-1][b2]-s[t][a2][b1-1]+s[t][a1-1][b1-1];}
int chk(int x)
{
	int r=x%d;
	for(int i=1;i<=d;i++) for(int j=1;j<=d;j++)
	{
		int a1=i,b1=j,a2=a1+r,b2=b1+r,x3=a1+d-1,y3=b1+d-1;
		if(!S(a1,b2+1,x3,y3,1)&&!S(a2+1,b1,x3,y3,1)&&!S(a2+1,b2+1,x3,y3,0)) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d%d",&x,&y),v[x%d+1][y%d+1]++;
	for(int i=1;i<=d;i++) for(int j=1;j<=d;j++) v[i+d][j]=v[i][j+d]=v[i+d][j+d]=v[i][j],mx=max(mx,v[i][j]);
	for(t=0;(t+1)*(t+1)<mx;t++);int l[3]={t*t+1,t*t+t+1,1e9};
	for(int i=1;i<=d*2;i++) for(int j=1;j<=d*2;j++) for(int k=0;k<2;k++)
		s[k][i][j]=(l[k]<=v[i][j])+s[k][i-1][j]+s[k][i][j-1]-s[k][i-1][j-1];
	int L=t*d,R=t*d+d,ans=R,mid;
	for(mid=(L+R)>>1;L<=R;mid=(L+R)>>1) if(chk(mid)) R=mid-1,ans=mid;else L=mid+1;
	printf("%d\n",ans);
}