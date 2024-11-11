#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n,x[N+9],y[N+9];
int ox[N+9],oy[N+9];

void into(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i){
	scanf("%d%d",&x[i],&y[i]);
	ox[i]=x[i];oy[i]=y[i];
  }
}

int id[N+9],p[N+9];

void Get_id(){
  sort(ox+1,ox+n+1);
  sort(oy+1,oy+n+1);
  for (int i=1;i<=n;++i){
	x[i]=lower_bound(ox+1,ox+n+1,x[i])-ox;
	y[i]=lower_bound(oy+1,oy+n+1,y[i])-oy;
	id[x[i]]=i;p[x[i]]=y[i];
  }
}

int le[N+9],ri[N+9];

void Get_le_ri(){
  le[1]=1;ri[n]=n;
  for (int i=2;i<=n;++i) le[i]=abs(p[i]-p[i-1])==1?le[i-1]:i;
  for (int i=n-1;i>=1;--i) ri[i]=abs(p[i]-p[i+1])==1?ri[i+1]:i;
}

map<int,LL>dp[2][N+9];

int Get_dis(int a,int b){
  a=id[a];b=id[b];
  return abs(ox[x[a]]-ox[x[b]])+abs(oy[y[a]]-oy[y[b]]);
}

LL Dfs_dp(int l,int r,int t,int mn,int mx){
  if (dp[t][l].find(r)!=dp[t][l].end()) return dp[t][l][r];
  LL res=l-r;
  int flag=0;
  if (l>1&&(p[l-1]==mn-1||p[l-1]==mx+1))
	res=Dfs_dp(le[l-1],r,0,min(mn,p[le[l-1]]),max(mx,p[le[l-1]]))+Get_dis(le[l-1],t?r:l),flag=1;
  if (r<n&&(p[r+1]==mn-1||p[r+1]==mx+1)){
	LL now=Dfs_dp(l,ri[r+1],1,min(mn,p[ri[r+1]]),max(mx,p[ri[r+1]]))+Get_dis(ri[r+1],t?r:l);
	res=flag?min(res,now):now;
  }
  return dp[t][l][r]=res;
}

LL ans[N+9];

void Get_dp(){
  for (int i=1;i<=n;++i) ans[id[i]]=Dfs_dp(i,i,0,p[i],p[i]);
}

void work(){
  Get_id();
  Get_le_ri();
  Get_dp();
}

void outo(){
  for (int i=1;i<=n;++i)
	printf("%lld\n",ans[i]);
}

int main(){
  into();
  work();
  outo();
  return 0;
}