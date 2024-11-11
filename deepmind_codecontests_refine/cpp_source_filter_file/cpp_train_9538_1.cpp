#include <bits/stdc++.h>
using namespace std;
int n, rt, num = 0, tot = 0, h[500010], fa[500010], g[500010], d[500010],
           top[500010], id[500010], f[500010], son[500010];
long long sz[500010 << 2], tag[500010 << 2], ans[500010];
struct edge {
  int to, next;
} mp[500010];
inline char gc() {
  static char *S, *T, buf[1 << 16];
  if (T == S) {
    T = (S = buf) + fread(buf, 1, 1 << 16, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
inline int read() {
  int x = 0, f = 1;
  char ch = gc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
  return x * f;
}
inline void ins(int x, int y) {
  mp[++num].to = y;
  mp[num].next = h[x];
  h[x] = num;
}
inline void dfs1(int x) {
  g[x] = 1;
  for (int i = h[x]; i; i = mp[i].next) {
    int y = mp[i].to;
    d[y] = d[x] + 1;
    dfs1(y);
    g[x] += g[y];
    if (g[y] > g[son[x]]) son[x] = y;
  }
}
inline void dfs2(int x, int tp) {
  top[x] = tp;
  id[x] = ++tot;
  if (son[x]) dfs2(son[x], tp);
  for (int i = h[x]; i; i = mp[i].next) {
    int y = mp[i].to;
    if (y != son[x]) dfs2(y, y);
  }
}
inline bool cmp(int x, int y) { return d[x] < d[y]; }
inline void add(int v, int l, int r, int x, int y) {
  sz[v] += y - x + 1;
  if (x == l && r == y) {
    tag[v]++;
    return;
  }
  int mid = l + r >> 1;
  if (y <= mid)
    add(v << 1, l, mid, x, y);
  else if (x > mid)
    add(v << 1 | 1, mid + 1, r, x, y);
  else
    add(v << 1, l, mid, x, mid), add(v << 1 | 1, mid + 1, r, mid + 1, y);
}
inline void solveadd(int x) {
  while (x) {
    add(1, 1, n, id[top[x]], id[x]);
    x = fa[top[x]];
  }
}
inline long long query(int v, int l, int r, int x, int y) {
  if (x == l && r == y) return sz[v];
  int mid = l + r >> 1;
  if (y <= mid)
    return query(v << 1, l, mid, x, y) + tag[v] * (y - x + 1);
  else if (x > mid)
    return query(v << 1 | 1, mid + 1, r, x, y) + tag[v] * (y - x + 1);
  else
    return query(v << 1, l, mid, x, mid) +
           query(v << 1 | 1, mid + 1, r, mid + 1, y) + tag[v] * (y - x + 1);
}
inline long long solvequery(int x) {
  long long sum = 0;
  while (x) {
    sum += query(1, 1, n, id[top[x]], id[x]);
    x = fa[top[x]];
  }
  return sum;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    fa[i] = read();
    if (fa[i])
      ins(fa[i], i);
    else
      rt = i;
    f[i] = i;
  }
  d[rt] = 1;
  dfs1(rt);
  dfs2(rt, rt);
  sort(f + 1, f + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    int j = i - 1;
    while (d[f[j + 1]] == d[f[i]]) {
      j++;
      int x = f[j];
      solveadd(x);
    }
    for (int k = i; k <= j; k++) {
      int x = f[k];
      ans[x] = solvequery(x) - d[x];
    }
    i = j;
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
