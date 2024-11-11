#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf=100000000;
ll px[]=  { 1, 0, -1, 0 };
ll py[]=  { 0, 1, 0, -1 };
int main() {
    ios::sync_with_stdio(0);cin.tie(NULL); cout.tie(NULL);
    ll n,m,i,j,x,y,k,sx,sy;
    cin>>n>>m>>k;
    cin>>x>>y>>sx>>sy;
    
    ll dist[n+5][m+5];
    char arr[n+5][m+5];
    bool vis[n+5][m+5];
    memset(vis,false,sizeof(vis));
    
    for(i=0;i<=n;i++)
     for(j=0;j<=m;j++)
      dist[i][j]=inf;
      
    dist[x][y]=0;vis[x][y]=true;
    
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
      cin>>arr[i][j];
    
    queue< pair<ll,ll> > pq;
    
    pq.push(make_pair(x,y));
    
    while(!pq.empty()){
       pair<ll,ll> p=pq.top(); pq.pop();
       x=p.first, y=p.second;
       
       for(i=0;i<4;i++){
            for(j=1;j<=k;j++){
                ll dx= x +px[i]*j    , dy= y+ py[i]*j ;
                if(dx<1||dy<1||dx>n||dy>m)break;
                if(arr[dx][dy]=='@')break;
                if(vis[dx][dy] && dist[dx][dy]<=dist[x][y])break;
                if(vis[dx][dy])continue;
                vis[dx][dy]=true;
                dist[dx][dy]= 1 + dist[x][y];
                pq.push( make_pair(dx,dy));
            }    
       }
    }
    
    if(!vis[sx][sy])cout<<"-1";
    else cout<<dist[sx][sy];
}