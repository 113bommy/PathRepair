#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
inline int read() {
  int sum = 0, p = 1;
  char ch = getchar();
  while (!(('0' <= ch && ch <= '9') || ch == '-')) ch = getchar();
  if (ch == '-') p = -1, ch = getchar();
  while ('0' <= ch && ch <= '9') sum = sum * 10 + ch - 48, ch = getchar();
  return sum * p;
}
const int maxn = 1e5 + 20;
struct node {
  int v, next;
};
node e[maxn << 1];
int cnt = 1, start[maxn], del[maxn << 1], odd[maxn << 1];
inline void addedge(int u, int v) {
  e[++cnt] = (node){v, start[u]};
  start[u] = cnt;
}
int n, m;
map<int, int> mp[maxn];
inline void init() {
  n = read();
  m = read();
  for (int i = (1), _end_ = (m); i <= _end_; i++) {
    int u = read(), v = read();
    addedge(u, v);
    addedge(v, u);
    mp[u][v] = mp[v][u] = i;
  }
}
int dfn[maxn], low[maxn], times, st[maxn], top, ste[maxn], tpe, vis[maxn];
vector<int> N[maxn];
vector<int> E[maxn];
vector<int> to[maxn];
int id[maxn], tot;
void dfs(int u, int fa) {
  dfn[u] = low[u] = ++times;
  st[++top] = u;
  for (int i = start[(u)]; i; i = e[i].next) {
    int v = e[i].v;
    if (v == fa) continue;
    if (!vis[i >> 1]) ste[++tpe] = i >> 1;
    vis[i >> 1] = 1;
    if (!dfn[v]) {
      dfs(v, u);
      chkmin(low[u], low[v]);
      if (low[v] >= dfn[u]) {
        int x;
        ++tot;
        do {
          x = st[top--];
          N[tot].push_back(x);
        } while (x != v);
        N[tot].push_back(u);
        do {
          x = ste[tpe--];
          E[tot].push_back(x);
        } while (x != (i >> 1));
      }
    } else
      chkmin(low[u], dfn[v]);
  }
}
int fa[maxn];
int fin(int x) { return x == fa[x] ? x : fa[x] = fin(fa[x]); }
inline void merge(int x, int y) {
  x = fin(x);
  y = fin(y);
  fa[y] = x;
}
int col;
int dis[maxn];
int flg;
void dfs1(int u) {
  vis[u] = 1;
  for (int v : to[u]) {
    if (vis[v]) {
      if (dis[u] ^ dis[v])
        ;
      else {
        flg = 1;
        return;
      }
      continue;
    }
    dis[v] = dis[u] ^ 1;
    dfs1(v);
  }
}
int ff[maxn], p[maxn][20], cf[maxn], deep[maxn];
inline int lca(int u, int v) {
  if (deep[u] < deep[v]) swap(u, v);
  int dis = deep[u] - deep[v];
  for (int i = (16), _end_ = (0); i >= _end_; i--)
    if (dis >> i & 1) u = p[u][i];
  if (u == v) return u;
  for (int i = (16), _end_ = (0); i >= _end_; i--)
    if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
  return p[u][0];
}
void dfs2(int u, int fa) {
  for (int i = start[(u)]; i; i = e[i].next)
    if (del[i >> 1]) {
      int v = e[i].v;
      if (v == fa) continue;
      cf[v] = cf[u] + odd[i >> 1];
      p[v][0] = ff[v] = fa;
      deep[v] = deep[u] + 1;
      dfs2(v, u);
    }
}
inline void doing() {
  for (int i = (1), _end_ = (n); i <= _end_; i++)
    if (!dfn[i]) dfs(i, 0);
  for (int i = (1), _end_ = (n); i <= _end_; i++) fa[i] = i;
  for (int i = (1), _end_ = (m); i <= _end_; i++) {
    int u = e[i << 1].v, v = e[i << 1 | 1].v;
    if (fin(u) == fin(v)) continue;
    merge(u, v);
    del[i] = 1;
  }
  memset(vis, 0, sizeof(vis));
  for (int i = (1), _end_ = (tot); i <= _end_; i++) {
    col = i;
    flg = 0;
    for (int j : E[col])
      to[e[j << 1].v].push_back(e[j << 1 | 1].v),
          to[e[j << 1 | 1].v].push_back(e[j << 1].v);
    dfs1(N[col].front());
    for (int v : N[col]) vis[v] = 0, dis[v] = 0, to[v].clear();
    for (int j : E[col]) odd[j] = flg;
  }
  for (int i = (1), _end_ = (n); i <= _end_; i++)
    if (i == fin(i)) deep[i] = 1, dfs2(i, 0);
  for (int j = (1), _end_ = (16); j <= _end_; j++)
    for (int i = (1), _end_ = (n); i <= _end_; i++)
      p[i][j] = p[p[i][j - 1]][j - 1];
  int m = read();
  for (int i = (1), _end_ = (m); i <= _end_; i++) {
    int u = read(), v = read();
    if (fin(u) != fin(v))
      puts("No");
    else {
      int t = lca(u, v);
      if (cf[u] + cf[v] - cf[t] * 2 || ((deep[u] + deep[v] - deep[t] * 2) & 1))
        puts("Yes");
      else
        puts("No");
    }
  }
}
int main() {
  init();
  doing();
  return 0;
}
