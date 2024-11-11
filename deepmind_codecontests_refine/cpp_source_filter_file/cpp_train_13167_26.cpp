#include <bits/stdc++.h>
using namespace std;
int pai[300300];
vector<pair<long long int, long long int> > adj[300300], edge;
long long int dist[300300], in[300300];
void dijkstra(int u) {
  int v, d;
  for (int i = 0; i < 300300; ++i) in[i] = dist[i] = (1LL << 50), pai[i] = i;
  dist[u] = in[u] = 0;
  priority_queue<pair<long long int, long long int>,
                 vector<pair<long long int, long long int> >,
                 greater<pair<long long int, long long int> > >
      pq;
  pq.push(pair<long long int, long long int>(0, u));
  while (pq.size()) {
    while (pq.size()) {
      u = pq.top().second, d = pq.top().first, pq.pop();
      if (dist[u] != d) continue;
      break;
    }
    for (int i = 0; i < adj[u].size(); ++i) {
      v = adj[u][i].second;
      if (dist[v] > dist[u] + adj[u][i].first) {
        pai[v] = u;
        in[v] = adj[u][i].first;
        dist[v] = dist[u] + adj[u][i].first;
        pq.push(pair<long long int, long long int>(dist[v], v));
      } else if (dist[v] == dist[u] + adj[u][i].first) {
        if (in[v] > adj[u][i].first) {
          in[v] = adj[u][i].first;
          pai[v] = u;
        }
      }
    }
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  pair<long long int, long long int> ed;
  long long int ans = 0;
  long long int n, m, a, b, c;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    edge.push_back(pair<long long int, long long int>(a, b));
    adj[a].push_back(pair<long long int, long long int>(c, b));
    adj[b].push_back(pair<long long int, long long int>(c, a));
  }
  cin >> a;
  dijkstra(a);
  for (int i = 1; i <= n; ++i) ans += in[i];
  cout << ans << "\n";
  for (int i = 0; i < m; ++i) {
    ed = edge[i];
    if (pai[ed.first] == ed.second || pai[ed.second] == ed.first)
      cout << i + 1 << " ";
  }
  cout << "\n";
  return 0;
}
