#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 5;
const int logn = 20;
const int inf = 0x3f3f3f3f;
int n, m;
struct edge {
  int u, v, w, i;
  inline void read() {
    scanf("%d%d%d", &u, &v, &w);
    u--, v--;
  }
  inline bool operator<(const edge &rhs) const { return w < rhs.w; }
};
class dsu {
  vector<int> p;

 public:
  dsu(int n) : p(n, -1) {}
  int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }
  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u != v) {
      if (p[u] > p[v]) {
        swap(u, v);
      }
      p[u] += p[v];
      p[v] = u;
      return true;
    }
    return false;
  }
};
vector<pair<int, int>> adj[maxn];
int lev[maxn];
int par[maxn][logn];
int best[maxn][logn];
int lazy[maxn][logn];
void dfs(int u, int p) {
  lev[u] = lev[p] + 1;
  par[u][0] = p;
  for (int i = 1; i < logn; ++i) {
    par[u][i] = par[par[u][i - 1]][i - 1];
    best[u][i] = max(best[u][i - 1], best[par[u][i - 1]][i - 1]);
  }
  for (pair<int, int> &it : adj[u]) {
    int v = it.first;
    int w = it.second;
    if (v != p) {
      best[v][0] = w;
      dfs(v, u);
    }
  }
}
int lca(int u, int v) {
  if (lev[u] < lev[v]) {
    swap(u, v);
  }
  for (int i = logn - 1; i >= 0; --i) {
    if (lev[u] - (1 << i) >= lev[v]) {
      u = par[u][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = logn - 1; i >= 0; --i) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}
int jump(int u, int v) {
  int res = 0;
  for (int i = logn - 1; i >= 0; --i) {
    if (lev[u] - (1 << i) >= lev[v]) {
      res = max(res, best[u][i]);
      u = par[u][i];
    }
  }
  return res;
}
int query(int u, int v) {
  int w = lca(u, v);
  return max(jump(u, w), jump(v, w));
}
void update_limit(int u, int v, int w) {
  for (int i = logn - 1; i >= 0; --i) {
    if (lev[u] - (1 << i) >= lev[v]) {
      lazy[u][i] = min(lazy[u][i], w);
      u = par[u][i];
    }
  }
}
void update(int u, int v, int weight) {
  int w = lca(u, v);
  update_limit(u, w, weight);
  update_limit(v, w, weight);
}
void propagate() {
  for (int i = logn - 1; i >= 1; --i) {
    for (int u = 1; u <= n; ++u) {
      int v = par[u][i - 1];
      lazy[u][i - 1] = min(lazy[u][i - 1], lazy[u][i]);
      lazy[v][i - 1] = min(lazy[v][i - 1], lazy[u][i]);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  vector<edge> edges(m);
  for (int i = 0; i < m; ++i) {
    edges[i].read();
    edges[i].i = i;
  }
  sort(edges.begin(), edges.end());
  dsu d(n);
  for (int i = 0; i < m; ++i) {
    int u = edges[i].u;
    int v = edges[i].v;
    int w = edges[i].w;
    if (d.unite(u, v)) {
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
  }
  memset(lazy, inf, sizeof(lazy));
  dfs(0, 0);
  for (int i = 0; i < m; ++i) {
    int &u = edges[i].u;
    int &v = edges[i].v;
    int w = edges[i].w;
    if (lev[u] > lev[v]) {
      swap(u, v);
    }
    if (u != par[v][0]) {
      update(u, v, w);
    }
  }
  propagate();
  vector<int> ans(m);
  for (int i = 0; i < m; ++i) {
    int u = edges[i].u;
    int v = edges[i].v;
    int w = edges[i].w;
    int id = edges[i].i;
    if (u == par[v][0]) {
      ans[id] = lazy[v][0] == inf ? -1 : lazy[v][0] - 1;
    } else {
      ans[id] = query(u, v) - 1;
    }
  }
  for (int i = 0; i < m; ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}
