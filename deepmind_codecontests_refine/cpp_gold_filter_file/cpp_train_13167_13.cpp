#include <bits/stdc++.h>
using namespace std;
const long long dx[] = {1, 0, -1, 0};
const long long dy[] = {0, 1, 0, -1};
long long ans;
int a[300005], b[300005];
long long c[300005];
vector<vector<pair<int, long long>>> adj(300005);
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    adj[a[i]].push_back({b[i], c[i]});
    adj[b[i]].push_back({a[i], c[i]});
  }
  int src;
  cin >> src;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      pq;
  vector<long long> dist(300005, 1000000000000000148);
  pq.push({0, src});
  dist[src] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (auto i : adj[u]) {
      int v = i.first;
      long long w = i.second;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  int best[300005];
  for (int i = 0; i <= n; i++) best[i] = -1;
  for (int i = 0; i < m; i++) {
    if (dist[a[i]] + c[i] == dist[b[i]]) {
      if (best[b[i]] == -1 or c[best[b[i]]] > c[i]) best[b[i]] = i;
    }
  }
  for (int i = 0; i < m; i++) {
    if (dist[a[i]] == dist[b[i]] + c[i]) {
      if (best[a[i]] == -1 or c[best[a[i]]] > c[i]) best[a[i]] = i;
    }
  }
  int visited[300005];
  memset(visited, 0, sizeof visited);
  for (int i = 1; i <= n; i++) {
    if (i == src) continue;
    visited[best[i]] = 1;
  }
  for (int i = 0; i < m; i++) {
    if (visited[i]) ans += c[i];
  }
  cout << ans << endl;
  for (int i = 0; i < m; i++) {
    if (visited[i]) cout << i + 1 << " ";
  }
  return 0;
}
