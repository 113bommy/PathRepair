#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pli pair<ll,int>
const int N=100;
 
struct Edge{
  int to,nxt,val;
}edge[3000000];
int head[N*N],tot;
void add(int u,int v,int w){
  edge[++tot]={v,head[u],w};
  head[u]=tot;
}
 
char s[N][25];
int l[N][25],r[N][25],c[N],id=0;
int len[N],n,st,ed;
 
bool check(int i,int l,int r){
  while(l<r){
    if(s[i][l]!=s[i][r])return 0;
    l++,r--;
  }
  return 1;
}
 
ll dis[N*N],inf=1e18;
void dijkstra(){
  for(int i=0;i<N*N;i++)dis[i]=inf;
  priority_queue<pli,vector<pli>,greater<pli>>pq;
  pq.push({0,st}),dis[st]=0;
  while(!pq.empty()){
    pli fir=pq.top();pq.pop();
    int u=fir.second;
    if(fir.first>dis[u])continue;
    for(register int i=head[u];i;i=edge[i].nxt){
      int v=edge[i].to;
      if(dis[v]>dis[u]+edge[i].val){
        dis[v]=dis[u]+edge[i].val;
        pq.push({dis[v],v});
      }
    }
  }
}
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%s%d",s[i]+1,&c[i]);
    len[i]=strlen(s[i]+1);
    for(int j=1;j<=len[i];j++)
      l[i][j]=++id,r[i][j]=++id;
  }
  st=++id,ed=++id;
  for(int i=1;i<=n;i++){
    add(st,l[i][1],c[i]);
    for(int j=1;j<=len[i];j++){
      if(check(i,j,len[i]))add(l[i][j],ed,0);
      for(int k=1;k<=n;k++){
        if(len[k]<=len[i]-j+1){
          bool flag=1;
          int a=j,b=len[k];
          for(;b>=1;a++,b--)
            if(s[i][a]!=s[k][b]){
              flag=0;break;
            } 
          if(flag){
            if(check(i,a,len[i]))add(l[i][j],ed,c[k]);
            else add(l[i][j],l[i][a],c[k]);
          }
        }else{
          bool flag=1;
          int a=j,b=len[k];
          for(;a<=len[i];a++,b--)
            if(s[i][a]!=s[k][b]){
              flag=0;break;
            }
          if(flag){
            if(check(k,1,b))add(l[i][j],ed,c[k]);
            else add(l[i][j],r[k][b],c[k]);
          }
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    add(st,r[i][len[i]],c[i]);
    for(int j=1;j<=len[i];j++){
      if(check(i,1,j))add(r[i][j],ed,0);
      for(int k=1;k<=n;k++){
        if(len[k]<=j){
          bool flag=1;
          int a=j,b=1;
          for(;b<=len[k];b++,a--)
            if(s[i][a]!=s[k][b]){
              flag=0;break;
            }
          if(flag){
            if(check(i,1,a))add(r[i][j],ed,c[k]);
            else add(r[i][j],r[i][a],c[k]);
          }
        }else{
          bool flag=1;
          int a=j,b=1;
          for(;a>=1;a--,b++)
            if(s[i][a]!=s[k][b]){
              flag=0;break;
            }
          if(flag){
            if(check(k,b,len[k]))add(r[i][j],ed,c[k]);
            else add(r[i][j],l[k][b],c[k]);
          }
        }
      }
    }
  }
  dijkstra();
  if(dis[ed]>=inf)puts("-1");
  else printf("%lld\n",dis[ed]);
  return 0;
}