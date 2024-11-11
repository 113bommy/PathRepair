#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 6010;
struct edge {
  int v, nxt;
} e[N << 1];
int head[N], cnt, ans, n, len, a[N], lsh[N], tot, d[N << 6][2], ls[N << 6],
    rs[N << 6], rt[N];
inline void add(int u, int v) {
  e[++cnt].v = v;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}
inline void pushup(int p) {
  d[p][0] = max(d[ls[p]][0], d[rs[p]][0]);
  d[p][1] = max(d[ls[p]][1], d[rs[p]][1]);
}
inline void change(int &p, int o, int l, int r, int x, int y) {
  if (!p) p = ++tot;
  if (l == r) {
    d[p][o] = max(d[p][o], y);
    return;
  }
  int mid = l + r >> 1;
  if (x <= mid)
    change(ls[p], o, l, mid, x, y);
  else
    change(rs[p], o, mid + 1, r, x, y);
  pushup(p);
}
inline int Union(int x, int y, int l, int r) {
  if (!x || !y) return x | y;
  if (l == r) {
    d[x][0] = max(d[x][0], d[y][0]);
    d[x][1] = max(d[x][0], d[y][1]);
    return x;
  }
  ans = max(ans, max(d[ls[x]][0] + d[rs[y]][1], d[ls[y]][0] + d[rs[x]][0]));
  int mid = l + r >> 1;
  ls[x] = Union(ls[x], ls[y], l, mid);
  rs[x] = Union(rs[x], rs[y], mid + 1, r);
  pushup(x);
  return x;
}
inline int query(int p, int o, int l, int r, int x, int y) {
  if (!p || x > y) return 0;
  if (x <= l && r <= y) return d[p][o];
  int mid = l + r >> 1, ans = 0;
  if (x <= mid) ans = max(ans, query(ls[p], o, l, mid, x, y));
  if (y > mid) ans = max(ans, query(rs[p], o, mid + 1, r, x, y));
  return ans;
}
inline void dfs(int u, int fa) {
  rt[u] = ++tot;
  int d1 = 0, d2 = 0;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, u);
    int ans1 = query(rt[v], 0, 1, len, 1, a[u] - 1);
    int ans2 = query(rt[v], 1, 1, len, a[u] + 1, len);
    Union(rt[u], rt[v], 1, len);
    ans = max(ans, max(d1 + ans2, d2 + ans1) + 1);
    d1 = max(d1, ans1);
    d2 = max(d2, ans2);
  }
  change(rt[u], 0, 1, len, a[u], d1 + 1);
  change(rt[u], 1, 1, len, a[u], d2 + 1);
}
inline void mian() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = lsh[i] = read();
  sort(lsh + 1, lsh + n + 1);
  len = unique(lsh + 1, lsh + n + 1) - lsh - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(lsh + 1, lsh + len + 1, a[i]) - lsh;
  for (int i = 1; i <= n - 1; ++i) {
    int x = read(), y = read();
    add(x, y);
    add(y, x);
  }
  dfs(1, 0);
  printf("%d\n", ans);
}
int main() {
  int qwq = 1;
  while (qwq--) mian();
  return 0;
}
