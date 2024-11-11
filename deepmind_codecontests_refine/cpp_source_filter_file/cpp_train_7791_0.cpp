#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct aaa{
	int x,y,w;
}a[1010];
const int p=1e9+7;
vector<int>zh[1010];
int n,m,i,j,x,sz,k,l,ans,f[302][302][302];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
		zh[a[i].y].push_back(i);
	}
	f[1][0][0]=3;
	for(i=1;i<=n;i++){
	 for(j=1;j<i;j++)
	  for(k=0;k<j;k++){
	  	for(l=0;l<zh[i].size();l++){
	  		x=zh[i][l];
	  		sz=1;
	  		if(a[x].x<=j)sz++;
	  		if(a[x].x<=k)sz++;
	  		if(sz!=a[x].w)f[i][j][k]=0;
	  	}
	  	if(!f[i][j][k])continue;
	  	(f[i+1][j][k]+=f[i][j][k])%=p;
	  	(f[i+1][i][k]+=f[i][j][k])%=p;
	  	(f[i+1][i][j]+=f[i][j][k])%=p;
	  }
	  for(l=0;l<zh[i].size();l++){
	  	x=zh[i][l];
	  	if(a[x].w!=1)f[i][0][0]=0;
	  }
	(f[i+1][0][0]+=f[i][0][0])%=p;
	 (f[i+1][i][0]+=f[i][0][0]*2%p)%=p;
  }
  for(j=0;j<n;j++)
   for(k=0;k<=j;k++)ans=(ans+f[n][j][k])%=p;
  printf("%d",ans);
}