#include <bits/stdc++.h>
using namespace std;
void init() {}
long long int INF = 2000000000;
vector<long long int> dijkstra(
    vector<vector<pair<long long int, long long int> > >& adj,
    long long int ini) {
  long long int N = adj.size();
  priority_queue<pair<long long int, long long int>,
                 vector<pair<long long int, long long int> >,
                 greater<pair<long long int, long long int> > >
      Q;
  vector<long long int> dist(N, INF);
  vector<long long int> pred(N, -1);
  Q.push(pair<long long int, long long int>(0, ini));
  dist[ini] = 0;
  pred[ini] = ini;
  vector<bool> done(N, false);
  while (((long long int)(Q).size())) {
    long long int u = Q.top().second;
    Q.pop();
    if (done[u]) continue;
    done[u] = true;
    for (long long int i = 0;
         i < (long long int)(((long long int)(adj[u]).size())); i++) {
      long long int v = adj[u][i].first;
      long long int d = dist[u] + adj[u][i].second;
      if (dist[v] > d) {
        dist[v] = d;
        pred[v] = u;
        Q.push(pair<long long int, long long int>(d, v));
      }
    }
  }
  return dist;
}
int main() {
  INF *= 100;
  long long int n, m;
  long long int x, y;
  cin >> n >> m;
  cin >> x >> y;
  x--;
  y--;
  vector<vector<pair<long long int, long long int> > > adj(n);
  long long int u, v, w;
  for (long long int i = 0; i < (long long int)(m); i++) {
    cin >> u >> v >> w;
    u--;
    v--;
    long long int esta = -1;
    for (long long int kk = 0;
         kk < (long long int)(((long long int)(adj[u]).size())); kk++)
      if (adj[u][kk].first == v) esta = kk;
    if (esta == -1) {
      adj[u].push_back(make_pair(v, w));
      adj[v].push_back(make_pair(u, w));
    } else {
      adj[u][esta].second = min(adj[u][esta].second, w);
      for (long long int kk = 0;
           kk < (long long int)(((long long int)(adj[v]).size())); kk++)
        if (adj[v][kk].first == u)
          adj[v][kk].second = min(adj[u][esta].second, w);
    }
  }
  vector<pair<long long int, long long int> > taxis;
  long long int c, t;
  for (long long int i = 0; i < (long long int)(n); i++) {
    cin >> t >> c;
    taxis.push_back(make_pair(t, c));
  }
  vector<vector<pair<long long int, long long int> > > adj2(n);
  for (long long int i = 0; i < (long long int)(n); i++) {
    vector<long long int> disti = dijkstra(adj, i);
    for (long long int j = 0;
         j < (long long int)(((long long int)(disti).size())); j++)
      if (j != i && disti[j] <= taxis[i].first)
        adj2[i].push_back(make_pair(j, taxis[i].second));
  }
  vector<long long int> res = dijkstra(adj2, x);
  res[y] != INF ? cout << res[y] << endl : cout << -1 << endl;
  return 0;
}
