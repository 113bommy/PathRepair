#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
vector<vector<pair<long long, long long>>> adj;
vector<long long> dist;
vector<bool> visited;
void djikstra(long long src) {
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      s;
  s.push({0, src});
  while (!s.empty()) {
    long long u = s.top().second;
    long long d_u = dist[u];
    s.pop();
    if (visited[u])
      continue;
    else
      visited[u] = true;
    for (auto x : adj[u]) {
      long long v = x.first;
      long long w = x.second;
      if (dist[v] > (dist[u] + w)) {
        dist[v] = dist[u] + w;
        s.push({dist[v], v});
      }
    }
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  adj.resize(n + 1);
  dist.resize(n + 1, LONG_MAX);
  visited.resize(n + 1, false);
  for (long long i = 0; i < m; ++i) {
    long long u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, 2 * w});
    adj[v].push_back({u, 2 * w});
  }
  for (long long i = 0; i < n; ++i) {
    long long temp;
    cin >> temp;
    adj[0].push_back({i + 1, temp});
  }
  dist[0] = 0;
  djikstra(0);
  for (long long i = 1; i <= n; ++i) {
    cout << dist[i] << " ";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  long long i, j;
  while (t--) {
    solve();
  }
  return 0;
}
