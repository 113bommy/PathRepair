#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m;
int P[maxn], pos[maxn];
int head[maxn], tot;
struct edge {
  int to, nex;
} E[maxn];
void addedge(int a, int b) {
  E[++tot].to = b;
  E[tot].nex = head[a];
  head[a] = tot;
}
int dep[maxn];
int st[maxn << 1][25], lg2[maxn << 1];
int dfn[maxn], p[maxn << 1], cnt;
void dfs(int now) {
  p[++cnt] = now, dfn[now] = cnt;
  for (int i = head[now]; i; i = E[i].nex) {
    int v = E[i].to;
    dep[v] = dep[now] + 1;
    dfs(v);
    p[++cnt] = now;
  }
}
void init() {
  dfs(1);
  for (int i = 1; i <= cnt; ++i) st[i][0] = p[i];
  for (int j = 1; j <= 20; ++j)
    for (int i = 1; i <= cnt - (1 << j) + 1; ++i)
      st[i][j] = (dep[st[i][j - 1]] < dep[st[i + (1 << (j - 1))][j - 1]]
                      ? st[i][j - 1]
                      : st[i + (1 << (j - 1))][j - 1]);
  lg2[1] = 0;
  for (int i = 2; i <= cnt; i++) lg2[i] = lg2[i >> 1] + 1;
}
int qqquery(int l, int r) {
  int len = lg2[r - l + 1];
  return (dep[st[l][len]] < dep[st[r - (1 << len) + 1][len]]
              ? st[l][len]
              : st[r - (1 << len) + 1][len]);
}
int lca(int x, int y) {
  x = dfn[x], y = dfn[y];
  if (x > y) swap(x, y);
  return qqquery(x, y);
}
bool online(int x, int s, int t) {
  int y = lca(s, t);
  return (lca(x, s) == x || lca(x, t) == x) && lca(x, y) == y;
}
struct semetree {
  pair<int, int> tr[maxn << 2];
  pair<int, int> merge(int x, int y, int u, int v) {
    if (x == -1 || y == -1 || u == -1 || v == -1) return make_pair(-1, -1);
    if (online(u, x, y) && online(v, x, y)) return make_pair(x, y);
    if (online(y, x, u) && online(v, x, u)) return make_pair(x, u);
    if (online(y, x, v) && online(u, x, v)) return make_pair(x, v);
    if (online(x, y, u) && online(v, y, u)) return make_pair(y, u);
    if (online(x, y, v) && online(u, y, v)) return make_pair(y, v);
    if (online(x, u, v) && online(y, u, v)) return make_pair(u, v);
    return make_pair(-1, -1);
  }
  pair<int, int> merge(pair<int, int> x, pair<int, int> y) {
    return merge(x.first, x.second, y.first, y.second);
  }
  void push(int rt) { tr[rt] = merge(tr[rt << 1], tr[rt << 1 | 1]); }
  void build(int rt, int l, int r) {
    if (l == r) return (void)(tr[rt] = make_pair(pos[l], pos[l]));
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push(rt);
  }
  int query(int rt, int l, int r, pair<int, int> pre) {
    pair<int, int> t;
    if (l == r) {
      t = merge(pre, tr[rt]);
      return (t.first == -1) ? l - 1 : l;
    }
    int mid = (l + r) >> 1;
    t = merge(pre, tr[rt << 1]);
    if (t.first != -1) return query(rt << 1 | 1, mid + 1, r, t);
    return query(rt << 1, l, mid, pre);
  }
  void modify(int rt, int l, int r, int x) {
    if (l == r) return (void)(tr[rt] = make_pair(pos[l], pos[l]));
    int mid = (l + r) >> 1;
    if (x <= mid)
      modify(rt << 1, l, mid, x);
    else
      modify(rt << 1 | 1, mid + 1, r, x);
    push(rt);
  }
} tmp;
template <typename T>
inline void read(T& t) {
  t = 0;
  char f = 0, ch = getchar();
  double d = 0.1;
  while (ch > '9' || ch < '0') f |= (ch == '-'), ch = getchar();
  while (ch <= '9' && ch >= '0') t = t * 10 + ch - 48, ch = getchar();
  if (ch == '.') {
    ch = getchar();
    while (ch <= '9' && ch >= '0') t += d * (ch ^ 48), d *= 0.1, ch = getchar();
  }
  t = (f ? -t : t);
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(P[i]), ++P[i], pos[P[i]] = i;
  int x, y;
  for (int i = 2; i <= n; i++) read(x), addedge(x, i);
  init();
  tmp.build(1, 1, n);
  read(m);
  while (m--) {
    read(x);
    if (x == 1) {
      read(x);
      read(y);
      swap(P[x], P[y]);
      swap(pos[P[x]], pos[P[y]]);
      tmp.modify(1, 1, n, P[x]);
      tmp.modify(1, 1, n, P[y]);
    } else
      printf("%d\n", tmp.query(1, 1, n, make_pair(pos[1], pos[1])));
  }
  return 0;
}
