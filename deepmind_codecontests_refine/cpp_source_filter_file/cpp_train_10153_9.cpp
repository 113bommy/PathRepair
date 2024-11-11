#include <bits/stdc++.h>
const int N = 1e5 + 10;
const int LOGN = 20;
long long ans;
int n;
int pre[N << 1], to[N << 1], head[N], wcnt;
long long dis[N];
int val[N], fa[N];
int dep[N];
int table[LOGN][N << 1];
int LOG2[N << 1];
int idcnt;
int st[N];
inline int minp(int x, int y) { return (dep[x] < dep[y]) ? x : y; }
inline void swap(int &x, int &y) {
  int t = x;
  x = y;
  y = t;
}
template <class T>
inline T max(const T &x, const T &y) {
  return (x < y) ? y : x;
}
inline void addedge(int u, int v) {
  wcnt++;
  pre[wcnt] = head[u];
  head[u] = wcnt;
  to[wcnt] = v;
}
inline void add2edge(int u, int v) {
  addedge(u, v);
  addedge(v, u);
}
void init() {
  int i, j, k;
  for (i = int(2); i <= int(idcnt); i++) LOG2[i] = LOG2[i >> 1] + 1;
  for (i = k = 1; k <= idcnt; i++, k <<= 1)
    for (j = 1; j <= int(idcnt - k); j++)
      table[i][j] = minp(table[i - 1][j], table[i - 1][j + k]);
}
inline long long getdis(int x, int y) {
  int l, r, k, z;
  l = st[x];
  r = st[y];
  if (l > r) swap(l, r);
  k = LOG2[r - l + 1];
  z = minp(table[k][l], table[k][r - (1 << k) + 1]);
  return dis[x] + dis[y] - 2 * dis[z] + val[z];
}
struct Node {
  int x, y;
  long long d;
  Node() {
    x = y = 0;
    d = -1;
  }
  Node(int x, int y) : x(x), y(y) { d = getdis(x, y); }
  bool operator<(const Node &b) const { return d < b.d; }
  Node operator+(const Node &b) const {
    if (d == -1)
      return b;
    else if (b.d == -1)
      return *this;
    Node res = max(*this, b);
    res = max(res, Node(x, b.x));
    res = max(res, Node(x, b.y));
    res = max(res, Node(y, b.x));
    res = max(res, Node(y, b.y));
    return res;
  }
};
Node sum[N], g[N];
void predfs(int u) {
  int i;
  table[0][st[u] = ++idcnt] = u;
  dis[u] = dis[fa[u]] + val[u];
  for (i = head[u]; i; i = pre[i])
    if (fa[u] ^ to[i]) {
      fa[to[i]] = u;
      dep[to[i]] = dep[u] + 1;
      predfs(to[i]);
      table[0][++idcnt] = u;
    }
}
void dfs1(int u) {
  int i;
  sum[u] = Node(u, u);
  for (i = head[u]; i; i = pre[i])
    if (fa[u] ^ to[i]) {
      dfs1(to[i]);
      sum[u] = sum[u] + sum[to[i]];
    }
}
void dfs2(int u) {
  static Node pref[N], suff[N];
  static int son[N];
  int i, sn = 0;
  for (i = head[u]; i; i = pre[i])
    if (fa[u] ^ to[i]) son[++sn] = to[i];
  pref[0] = suff[sn + 1] = g[fa[u]] + Node(u, u);
  for (i = 1; i <= int(sn); i++) pref[i] = pref[i - 1] + sum[son[i]];
  for (i = int(sn); i; i--) suff[i] = suff[i + 1] + sum[son[i]];
  for (i = 1; i <= int(sn); i++) g[son[i]] = pref[i - 1] + suff[i + 1];
  for (i = int(0); i <= int(sn + 1); i++) pref[i] = suff[i] = Node();
  if (u > 1) ans = max(ans, sum[u].d + g[u].d);
  for (i = head[u]; i; i = pre[i])
    if (fa[u] ^ to[i]) dfs2(to[i]);
}
int main() {
  int i;
  int u, v;
  scanf("%d", &n);
  for (i = 1; i <= int(n); i++) scanf("%d", &val[i]);
  for (i = 1; i <= int(n - 1); i++) {
    scanf("%d %d", &u, &v);
    add2edge(u, v);
  }
  predfs(1);
  init();
  dfs1(1);
  ans = sum[1].d;
  dfs2(1);
  printf("%lld\n", ans);
  return 0;
}
