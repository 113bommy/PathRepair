#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
 
const int INF=1000000000;
 
using namespace std;
 
struct edge{int to,cost;};
typedef pair<int,int>P;
 
int V,d[101];
vector<edge>G[101];
 
void dijkstra(int s){
  priority_queue<P,vector<P>,greater<P> >que;
  fill(d,d+V,INF);
  d[s]=0;
  que.push(P(0,s));
 
  while(!que.empty()){
    P p=que.top();
    que.pop();
    int v=p.second;
    if(d[v]<p.first)continue;
 
    for(int i=0;i<G[v].size();i++){
      edge e=G[v][i];
      if(d[e.to]>d[v]+e.cost){
    d[e.to]=d[v]+e.cost;
    que.push(P(d[e.to],e.to));
      }
    }
  }
}
 
int main(void){
 
  int n,m,c,s,g,x,y,D,C;
  int p[21],q[21][51],r[21][51];
  int graph[21][101][101],Cost[21][20001];
   
  while(cin >> n >> m >> c >> s >> g,n|m|c|s|g){
   
    for(int i=0;i<101;i++)G[i].clear();
 
    for(int i=0;i<21;i++)
      for(int j=0;j<101;j++)
    for(int k=0;k<101;k++)
      graph[i][j][k]=INF;
 
    for(int i=0;i<21;i++)
      for(int j=0;j<101;j++)
    graph[i][j][j]=0;
     
    for(int i=0;i<m;i++){
      cin >> x >> y >> D >> C;
      graph[C][x][y]=graph[C][y][x]=min(graph[C][x][y],D);
    }
  
    for(int i=1;i<=c;i++)cin >> p[i];
 
    for(int i=1;i<=c;i++){
      for(int j=1;j<p[i];j++)cin >> q[i][j];
      for(int j=1;j<=p[i];j++)cin >> r[i][j];
    }
     
    for(int i=0;i<21;i++)
      for(int j=0;j<20001;j++)
    Cost[i][j]=0;
   
    for(int i=1;i<=c;i++){
      for(int j=1,k=1;j<20001;j++){
    if(k<p[i] && q[i][k]<j)k++;
    Cost[i][j]=Cost[i][j-1]+r[i][k];
      }
    }
     
    for(int l=1;l<=c;l++){
      for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        graph[l][i][j]=min(graph[l][i][j],graph[l][i][k]+graph[l][k][j]);
      }
    }
      }
    }
     
    for(int k=1;k<=c;k++)
      for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if(graph[k][i][j]!=INF)
        graph[0][i][j]=min(graph[0][i][j],Cost[k][graph[k][i][j]]);
     
 
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
    if(graph[0][i][j]==INF)continue;
    edge e;
    e.to=j;
    e.cost=graph[0][i][j];
    G[i].push_back(e);
      }
    }
     
     
    V=n+1;
    dijkstra(s);
 
    if(d[g]==INF)cout << -1 << endl;
    else cout << d[g] << endl;
  }
 
  return 0;
}