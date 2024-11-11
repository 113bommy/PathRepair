#include <bits/stdc++.h>
using namespace std;
const int logsize = 18;
int n, m, q, rt = 1, t, sc, vis[100005], dfn[100005], low[100005], sid[100005],
             sz[100005], dep[100005], pr[100005][logsize], w[100005],
             mod = 1e9 + 7;
stack<int> s;
vector<int> g[100005], ng[100005];
int inline read() {
  int res = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    ;
  for (; isdigit(c); res *= 10, res += c ^ 48, c = getchar())
    ;
  return res;
}
void tarjan(int u, int p) {
  dfn[u] = low[u] = ++t;
  vis[u] = 1;
  s.push(u);
  for (int v : g[u]) {
    if (v == p || vis[v] == 2) continue;
    if (!vis[v]) {
      tarjan(v, u);
    }
    low[u] = min(low[u], low[v]);
  }
  if (dfn[u] == low[u]) {
    ++sc;
    for (;;) {
      int v = s.top();
      s.pop();
      vis[v] = 2;
      sid[v] = sc;
      ++sz[sc];
      if (u == v) break;
    }
  }
}
void dfs(int u, int p) {
  dep[u] = u == rt ? 0 : dep[p] + 1;
  w[u] = u == rt ? sz[u] > 1 : w[p] + (sz[u] > 1);
  pr[u][0] = p;
  for (int v : ng[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}
void inline init() {
  dfs(rt, -1);
  for (int i = 1; i <= logsize - 1; ++i) {
    for (int u = 1; u <= sc; ++u) {
      int p = pr[u][i - 1];
      if (p == -1) {
        pr[u][i] = -1;
      } else {
        pr[u][i] = pr[p][i - 1];
      }
    }
  }
}
int inline lca(int u, int v) {
  if (dep[u] > dep[v]) {
    swap(u, v);
  }
  for (int i = 0; i < logsize; ++i) {
    if ((dep[v] - dep[u]) >> i & 1) {
      v = pr[v][i];
    }
  }
  if (u == v) return u;
  for (int i = logsize - 1; i > 0; --i) {
    if (pr[u][i] != pr[v][i]) {
      u = pr[u][i];
      v = pr[v][i];
    }
  }
  return pr[u][0];
}
int qpow(long long a, int p) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      res *= a;
      res %= mod;
    }
    a *= a;
    a %= mod;
    p >>= 1;
  }
  return res % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  n = read();
  m = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int u = 1; u <= n; ++u) {
    if (!vis[u]) {
      tarjan(u, -1);
    }
  }
  for (int u = 1; u <= n; ++u) {
    for (int v : g[u]) {
      int su = sid[u], sv = sid[v];
      if (su == sv) continue;
      ng[su].push_back(sv);
    }
  }
  init();
  q = read();
  for (int i = 1; i <= q; ++i) {
    int u = read(), v = read(), su = sid[u], sv = sid[v], sp = lca(su, sv);
    int d = w[su] + w[sv] - w[sp] * 2 + (sz[sp] > 1);
    cout << qpow(2, d) << '\n';
  }
}
