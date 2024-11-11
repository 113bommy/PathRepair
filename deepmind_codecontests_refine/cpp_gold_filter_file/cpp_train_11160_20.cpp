#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 500005;
int n;
vector<int> adj[maxn];
int a[maxn];
int dad[maxn];
int h[maxn];
vector<pair<int, int> > conditions[maxn];
int nxt[maxn], prv[maxn], seen[maxn];
void no(int ncase) {
  cerr << ncase << endl;
  if (ncase == 1)
    cout << -1 << endl;
  else
    cout << 0 << endl;
  exit(0);
}
void dfs(int u) {
  for (auto v : adj[u])
    if (v != dad[u]) {
      dad[v] = u;
      h[v] = h[u] + 1;
      dfs(v);
    }
}
int cnt;
void go(int u, int v) {
  if (u == v) no(0);
  vector<int> from_u, to_v;
  from_u.push_back(n + 1);
  to_v.push_back(n + 2);
  while (h[u] > h[v]) {
    from_u.push_back(u);
    u = dad[u];
  }
  while (h[v] > h[u]) {
    to_v.push_back(v);
    v = dad[v];
  }
  while (u != v) {
    from_u.push_back(u);
    u = dad[u];
    to_v.push_back(v);
    v = dad[v];
  }
  from_u.push_back(u);
  from_u.insert(from_u.end(), to_v.rbegin(), to_v.rend());
  for (int i = 1; i + 1 < from_u.size(); ++i)
    conditions[from_u[i]].push_back({from_u[i - 1], from_u[i + 1]});
  cnt += from_u.size() - 3;
  if (cnt > 2 * n - 2) no(0);
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    adj[i].push_back(n + 1);
    adj[i].push_back(n + 2);
  }
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (n == 1) {
    cout << 1 << endl;
    exit(0);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i)
    if (a[i] != 0) go(i, a[i]);
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    for (auto edge : conditions[i]) {
      int u = edge.first, v = edge.second;
      if (nxt[u] && nxt[u] != v) no(1);
      if (prv[v] && prv[v] != u) no(1);
      nxt[u] = v;
      prv[v] = u;
    }
    for (auto u : adj[i])
      if (!seen[u]) {
        seen[u] = 1;
        int cur = nxt[u];
        while (cur) {
          if (cur == u) no(2);
          if (seen[cur]) break;
          seen[cur] = 1;
          cur = nxt[cur];
        }
      }
    if (nxt[n + 1]) {
      int cur = n + 1, all = 1;
      while (cur) {
        if (cur == n + 2) break;
        ++all;
        cur = nxt[cur];
      }
      if (cur == n + 2 && all < adj[i].size()) no(3);
    }
    int free = 0;
    for (auto u : adj[i])
      if (u <= n && !prv[u]) ++free;
    if (prv[n + 2]) --free;
    for (int j = 1; j <= free; ++j) ans = 1ll * ans * j % mod;
    for (auto u : adj[i]) nxt[u] = prv[u] = seen[u] = 0;
  }
  cout << ans << endl;
  return 0;
}
