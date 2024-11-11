#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
int dfs(const vector<vector<int> >& E, const vector<int>& T, int u, int p) {
  int c = 0;
  for (auto v : E[u])
    if (v != p) c += dfs(E, T, v, u);
  if (T[u] || c)
    return c + 1;
  else
    return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int> > E(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> T(n, 0);
  int t = INF;
  for (int j = 0; j < m; ++j) {
    int u;
    cin >> u;
    --u;
    T[u] = 1;
    t = min(t, u);
  }
  vector<int> p(n, t);
  vector<int> d(n, 0);
  queue<int> q;
  q.push(t);
  while (not q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : E[u])
      if (v != p[u]) {
        p[v] = u;
        d[v] = d[u] + 1;
        if (T[v] && (d[v] > d[t] || (d[v] == d[t] && v < t))) t = v;
        q.push(v);
      }
  }
  q.push(t);
  p.assign(n, t);
  d.assign(n, 0);
  int o = 0;
  while (not q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : E[u])
      if (v != p[u]) {
        p[v] = u;
        d[v] = d[u] + 1;
        o = max(o, d[v] * T[v]);
        q.push(v);
      }
  }
  for (int u = 0; u < n; ++u)
    if (T[u] && d[u] == o) t = min(t, u);
  int x = 0;
  for (int u = 0; u < n; ++u) x = max(x, d[u] * T[u]);
  int ans = 2 * (dfs(E, T, t, t) - 1) - x;
  cout << t + 1 << '\n' << ans << '\n';
  exit(0);
}
