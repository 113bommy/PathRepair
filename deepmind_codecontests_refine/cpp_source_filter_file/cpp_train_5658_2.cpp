#include <bits/stdc++.h>
using namespace std;
int n, m, k, s, t;
vector<vector<int>> adj;
vector<int> vis, d, p, sz;
bool bfs(int dist) {
  queue<int> q;
  vis.clear();
  vis.resize(n);
  d.clear();
  d.resize(n);
  q.push(s);
  vis[s] = true;
  for (int i = 0; i < n; ++i) d[i] = 1e9;
  d[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
      if (d[v] + 1 < d[u]) {
        d[u] = d[v] + 1;
        if (d[u] > dist) continue;
        if (p[u]) d[u] = 0;
        if (d[u] < dist) q.push(u);
        if (u == t) return 1;
      }
    }
  }
  return (d[t] > dist) ? 0 : 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  adj.resize(n);
  p.resize(n);
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    --c;
    p[c] = 1;
  }
  int xvc = m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> s >> t;
  --s;
  --t;
  int l = 0, r = xvc;
  while (l < r) {
    int mid = (l + r) / 2;
    bool verdict = bfs(mid);
    if (verdict)
      r = mid;
    else
      l = mid + 1;
  }
  if (r != l)
    cout << "-1\n";
  else
    cout << r << '\n';
  return 0;
}
