#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
int n, m, g[MAXN], deg[MAXN], c[MAXN], d[MAXN], pre[MAXN];
vector<int> adj[MAXN];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v >> c[i];
    g[i] = u + v, d[i] = -1;
    adj[u].push_back(i);
    adj[v].push_back(i);
    deg[u] += c[i], deg[v] += c[i], pre[i] = u;
  }
  for (int i = 2; i < n; ++i) deg[i] >>= 1;
  queue<int> q;
  q.push(1);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (auto it : adj[u])
      if (d[it] == -1) {
        int v = g[it] - u;
        deg[v] -= c[it], d[it] = u;
        if (deg[v] == 0 && v < n) q.push(v);
      }
  }
  for (int i = 1; i <= m; ++i) cout << (d[i] != pre[i]) << '\n';
  return 0;
}
