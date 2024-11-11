#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using Graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

vector<ll> dijkstra(int s,WeightedGraph  & G){
  using P = pair<ll, int>;
  int n=G.size();
  vector<ll> ds(n,INF);
  vector<int> bs(n,-1);
  priority_queue<P, vector<P>, greater<P> > pq;
  ds[s]=0;
  pq.emplace(ds[s],s);
  while(!pq.empty()){
    P p=pq.top();pq.pop();
    int v=p.second;
    if(ds[v]<p.first) continue;
    for(auto& e:G[v]){
      int u=e.first;
      ll c=e.second;
      if(ds[u]>ds[v]+c){
        ds[u]=ds[v]+c;
        bs[u]=v;
        pq.emplace(ds[u],u);
      }
    }
  }
  return ds;
}


int main(){
  int n,m,s,t;
  cin >> n >> m >> s >> t;
  --s;--t;
  
  WeightedGraph G(n), G2(n);
  for(int i = 0; i < m; ++i){
    ll u,v,a,b;
    cin >> u >> v >> a >> b;
    --u;--v;
    G[u].push_back({v,a});
    G[v].push_back({u,a});
    G2[u].push_back({v,b});
    G2[v].push_back({u,b});
  }
  auto d = dijkstra(s,G);
  auto d2 = dijkstra(t,G2);
  vector<ll> ans(n+1,INF);
  for(int i = n-1; i >= 0; --i){
    ans[i]= min(ans[i+1], d[i]+ d2[i]);
  }
  ll tmp = 1e15;
  for(int i = 0; i < n; ++i){
    cout << tmp-ans[i] << endl;
  }
}
