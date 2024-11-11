#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int n, m, q, dfs_clock, dep[600050], fa[600050], sz[600050], son[600050],
    top[600050], ide[600050], R, vis1[600050], p[600050];
stack<int> P;
vector<int> G[600050];
map<pair<int, int>, bool> M;
inline int rotate(int element) {
  element = (element + R) % n;
  if (element == 0) element = n;
  return element;
}
struct Graph {
  int dfn[600050], low[600050], scc[600050], scc_cnt, vis[600050], dfs_clock;
  vector<int> G[600050], id[600050];
  stack<int> s;
  inline void Init(int n) {
    dfs_clock = 0;
    for (int i = 0; i <= n; i++) {
      dfn[i] = 0;
      low[i] = 0;
      scc[i] = 0;
      vis[i] = 0;
      G[i].clear();
      id[i].clear();
    }
    scc_cnt = 0;
    while (!s.empty()) s.pop();
  }
  inline void Tarjan(int u) {
    dfn[u] = low[u] = ++dfs_clock;
    s.push(u);
    for (int i = 0; i < G[u].size(); i++) {
      int id1 = id[u][i];
      if (!vis[id1]) {
        vis[id1] = true;
        int v = G[u][i];
        if (!dfn[v]) {
          Tarjan(v);
          low[u] = min(low[u], low[v]);
        } else if (!scc[v])
          low[u] = min(low[u], dfn[v]);
      }
    }
    if (low[u] == dfn[u]) {
      int t;
      scc_cnt++;
      do {
        t = s.top();
        s.pop();
        scc[t] = scc_cnt;
      } while (t != u);
    }
  }
} G1, G2;
inline void dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  ::fa[u] = fa;
  sz[u] = 1;
  ide[u] = ++dfs_clock;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa) {
      dfs1(v, u);
      sz[u] += sz[v];
      if (sz[v] > sz[son[u]]) son[u] = v;
    }
  }
}
inline void dfs2(int u, int fir) {
  top[u] = fir;
  if (son[u]) dfs2(son[u], fir);
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v != fa[u] && v != son[u]) dfs2(v, v);
  }
}
inline int LCA(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    u = fa[top[u]];
  }
  if (u == 0 || v == 0) return 0;
  return dep[u] <= dep[v] ? u : v;
}
inline int read1() {
  int x = read();
  return G1.scc[rotate(x)];
}
inline bool comp(int x, int y) { return ide[x] < ide[y]; }
int main() {
  n = read(), m = read(), q = read();
  G1.Init(n);
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read();
    G1.G[u].push_back(v);
    G1.G[v].push_back(u);
    G1.id[u].push_back(i);
    G1.id[v].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!G1.dfn[i]) G1.Tarjan(i);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < G1.G[i].size(); j++) {
      int v = G1.G[i][j];
      if (G1.scc[v] != G1.scc[i]) {
        int x = min(G1.scc[v], G1.scc[i]), y = max(G1.scc[v], G1.scc[i]);
        pair<int, int> e = make_pair(x, y);
        if (!M[e]) {
          G[x].push_back(y);
          G[y].push_back(x);
          M[e] = true;
        }
      }
    }
  }
  dfs_clock = 0;
  for (int i = 1; i <= n; i++) {
    if (!dep[i]) {
      dfs1(i, 0);
      dfs2(i, i);
    }
  }
  G2.Init(600000);
  for (int T = 1; T <= q; T++) {
    int N = read(), M = read();
    int pcnt = 0, id1 = 0;
    for (int i = 1; i <= N; i++) {
      int x = read1();
      p[++pcnt] = x;
      vis1[x] = 1;
    }
    for (int i = 1; i <= M; i++) {
      int x = read1(), y = read1();
      if (x != y) {
        p[++pcnt] = x;
        p[++pcnt] = y;
        id1++;
        G2.G[x].push_back(y);
        G2.G[y].push_back(x);
        G2.id[x].push_back(id1);
        G2.id[y].push_back(id1);
      }
    }
    sort(p + 1, p + pcnt + 1, comp);
    pcnt = unique(p + 1, p + pcnt + 1) - p - 1;
    for (int i = pcnt - 1; i; i--) {
      int x = LCA(p[i], p[i + 1]);
      if (x) p[++pcnt] = x;
    }
    sort(p + 1, p + pcnt + 1, comp);
    pcnt = unique(p + 1, p + pcnt + 1) - p - 1;
    for (int i = 1; i <= pcnt; i++) {
      while (!P.empty() && ide[P.top()] + sz[P.top()] <= ide[p[i]]) P.pop();
      if (!P.empty()) {
        int x = P.top(), y = p[i];
        id1++;
        G2.G[x].push_back(y);
        G2.G[y].push_back(x);
        G2.id[x].push_back(id1);
        G2.id[y].push_back(id1);
      }
      P.push(p[i]);
    }
    for (int i = 1; i <= pcnt; i++) {
      if (!G2.dfn[p[i]]) G2.Tarjan(p[i]);
    }
    int pid = 0, flag = 1;
    for (int i = 1; i <= pcnt; i++) {
      if (vis1[p[i]]) {
        if (!pid)
          pid = G2.scc[p[i]];
        else if (pid != G2.scc[p[i]]) {
          flag = false;
          break;
        }
      }
    }
    R = (R + flag * T) % n;
    puts(flag ? "YES" : "NO");
    for (int i = 1; i <= pcnt; i++) {
      int res = p[i];
      G2.G[res].clear();
      G2.id[res].clear();
      G2.dfn[res] = 0;
      G2.low[res] = 0;
      G2.scc[res] = 0;
      vis1[res] = 0;
    }
    G2.scc_cnt = 0;
    G2.dfs_clock = 0;
    while (!G2.s.empty()) G2.s.pop();
    for (int i = 1; i <= id1; i++) G2.vis[i] = 0;
    while (!P.empty()) P.pop();
  }
  return 0;
}
