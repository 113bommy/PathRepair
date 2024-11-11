#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 100010, LOG = 20;
int n, k, tin[N], par[LOG][N], dep[N];
vector<int> adj[N];
int dfst = 0, sz = 0;
set<pii> s;
set<pii>::iterator ite;
inline void dfs(int v, int p = -1, int d = 0) {
  par[0][v] = p;
  dep[v] = d;
  tin[v] = ++dfst;
  for (int u : adj[v])
    if (u != p) dfs(u, v, d + 1);
}
inline int lca(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int j = LOG - 1; j >= 0; j--)
    if (par[j][v] != -1 && dep[par[j][v]] >= dep[u]) v = par[j][v];
  if (u == v) return u;
  for (int j = LOG - 1; j >= 0; j--)
    if (par[j][v] != par[j][u]) v = par[j][v], u = par[j][u];
  return par[0][v];
}
inline void add(const int v) {
  ite = s.lower_bound({tin[v], v});
  int u, w;
  if (ite != s.end()) {
    u = ite->second;
    if (ite != s.begin())
      w = (--ite)->second;
    else
      w = s.rbegin()->second;
    sz -= dep[u] + dep[w] - 2 * dep[lca(u, w)];
    sz += dep[u] + dep[v] - 2 * dep[lca(u, v)];
    sz += dep[w] + dep[v] - 2 * dep[lca(w, v)];
  } else {
    if (ite != s.begin()) {
      u = (--ite)->second;
      w = s.begin()->second;
      sz -= dep[u] + dep[w] - 2 * dep[lca(u, w)];
      sz += dep[u] + dep[v] - 2 * dep[lca(u, v)];
      sz += dep[w] + dep[v] - 2 * dep[lca(w, v)];
    }
  }
  s.insert({tin[v], v});
}
inline void del(const int v) {
  ite = s.lower_bound({tin[v], v});
  ++ite;
  int u, w;
  if (ite != s.end())
    u = ite->second;
  else
    u = s.begin()->second;
  sz -= dep[u] + dep[v] - 2 * dep[lca(u, v)];
  --ite;
  if (ite != s.begin())
    w = (--ite)->second;
  else
    w = s.rbegin()->second;
  sz -= dep[w] + dep[v] - 2 * dep[lca(w, v)];
  sz += dep[w] + dep[u] - 2 * dep[lca(w, u)];
  s.erase({tin[v], v});
}
int main() {
  scanf("%d%d", &n, &k);
  int u, v;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1);
  for (int j = 1; j < LOG; j++)
    for (int i = 1; i <= n; i++)
      par[j][i] = (par[j - 1][i] == -1) ? -1 : par[j - 1][par[j - 1][i]];
  int ans = 0;
  for (int fi = 1, se = 1; fi < n; fi++) {
    if (se < fi) se = fi;
    while (se <= n && sz / 2 + 1 <= k) add(se++);
    if (sz / 2 + 1 > k) del(--se);
    ans = max(ans, se - fi);
    del(fi);
  }
  printf("%d\n", ans);
  return 0;
}
