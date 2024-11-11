#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct edge{int to;ll cost;};

vector<edge> tree[100010];
ll dist[100010];

void dfs(int v, int p, ll d){
  dist[v]=d;
  for (auto& e:tree[v]){
    if(e.to==p) continue;
    dfs(e.to, e, d+e.cost);
  }
}

int main(){
  int N;cin>>N;
  for (int i=0;i<N-1;++i){
    int a, b;ll c;cin>> a>>b >> c; a--,b--;
    tree[a].push_back({b,c});tree[b].push_back({a,c});
  }

  int Q, K;cin>>Q>>K;
  dfs(K, -1, 0);

  for (int i=0;i<Q;++i){
    int x, y;cin>>x>>y;x--,y--;
    cout << dist[x]+dist[y] << endl;
  }

  return 0;
}