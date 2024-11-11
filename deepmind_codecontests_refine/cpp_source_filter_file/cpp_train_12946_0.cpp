#include <bits/stdc++.h>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ') {
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
const int N = 1e5 + 5;
struct Node {
  int ls, rs, s;
} t[N << 5];
struct Edge {
  int next, to;
  Edge(int next = 0, int to = 0) : next(next), to(to){};
} edge[N << 1];
int tot, head[N];
void add(int x, int y) { edge[++tot] = Edge(head[x], y), head[x] = tot; }
int n, m, o, all, fa[N], dt, ac[20][N], d[N], dfn[N], root[N], s[N], vis[N];
void add(int &x, int pre, int l, int r, int p, int d) {
  x = ++all, t[x] = t[pre], t[x].s += d;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (p <= mid)
    add(t[x].ls, t[pre].ls, l, mid, p, d);
  else
    add(t[x].rs, t[pre].rs, mid + 1, r, p, d);
}
int ask(int x, int y, int l, int r, int p) {
  if (!x || r <= p) return t[x].s - t[y].s;
  int mid = (l + r) >> 1;
  if (p <= mid)
    return ask(t[x].ls, t[y].ls, l, mid, p);
  else
    return t[t[x].ls].s - t[t[y].ls].s + ask(t[x].rs, t[y].rs, mid + 1, r, p);
}
void dfs(int x) {
  dfn[x] = ++dt, s[x] = 1, ac[0][x] = fa[x], d[x] = d[fa[x]] + 1;
  for (int i = 1; i < 20; ++i) ac[i][x] = ac[i - 1][ac[i - 1][x]];
  for (int i = head[x]; i; i = edge[i].next)
    dfs(edge[i].to), s[x] += s[edge[i].to];
}
int ask(int l, int r, int x, int y) {
  return d[x] + ask(root[r], root[l - 1], 1, n, dfn[x]) - d[y] -
         ask(root[r], root[l - 1], 1, n, dfn[y]);
}
void add(int i, int p, int d) {
  if (p <= n) add(root[i], root[i], 1, n, p, d);
}
int ask(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  for (int i = 19; ~i; --i)
    if (d[ac[i][x]] >= d[y]) x = ac[i][x];
  if (x == y) return x;
  for (int i = 19; ~i; --i)
    if (ac[i][x] != ac[i][y]) x = ac[i][x], y = ac[i][y];
  return fa[x];
}
int query(int l, int r, int x, int t, int k) {
  int y = x;
  if (d[x] < t) return 0;
  for (int i = 19; ~i; --i)
    if (d[ac[i][y]] <= t && ask(l, r, x, ac[i][y]) < k) y = ac[i][y];
  return y;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    if (!(fa[i] = read()))
      o = i;
    else
      add(fa[i], i);
  dfs(o), m = read();
  for (int i = 1; i <= m; ++i) {
    int t = read(), c, a, b, k, y;
    root[i] = root[i - 1];
    if (t == 1)
      c = read(), vis[c] = 1, add(i, dfn[c], -1), add(i, dfn[c] + s[c], 1);
    else {
      a = read(), b = read(), k = read(), y = read();
      int lca = ask(a, b), up = ask(y + 1, i, fa[a], lca ^ b ? fa[lca] : lca),
          down = max(ask(y + 1, i, fa[b], lca), 0);
      if (k > up + down || fa[a] == b || fa[b] == a)
        puts("-1");
      else if (k <= up)
        printf("%d\n", query(y + 1, i, fa[a], d[lca], k));
      else
        printf("%d\n", query(y + 1, i, fa[b], d[lca] + 1, up + down - k + 1));
    }
  }
  return 0;
}
