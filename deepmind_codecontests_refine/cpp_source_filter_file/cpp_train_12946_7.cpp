#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
const int maxn = 1e5 + 5;
struct tree {
  int c[2], siz;
} t[maxn * 40];
struct edge {
  int next, to;
} e[maxn * 2];
struct node {
  int l, r;
  node() {}
  node(int L, int R) { l = L, r = R; }
} zc[114][2];
struct quest {
  int u, v, k, y;
} w[maxn];
int rt[maxn], top[maxn], siz[maxn], f[maxn], son[maxn], p[maxn], d[maxn], pos,
    n, m, cnt, tot, h[maxn], ti[maxn], fp[maxn], zcnt[2];
void addedge(int x, int y) {
  e[++cnt].next = h[x];
  e[cnt].to = y;
  h[x] = cnt;
}
void add(int &id, int o, int l, int r, int v) {
  id = ++cnt, t[id] = t[o], t[id].siz++;
  if (l == r) return;
  int mid = l + r >> 1;
  v <= mid ? add(t[id].c[0], t[o].c[0], l, mid, v)
           : add(t[id].c[1], t[o].c[1], mid + 1, r, v);
}
int ask(int id, int o, int l, int r, int L, int R) {
  if (l >= L && r <= R) return t[id].siz - t[o].siz;
  int mid = l + r >> 1, sum = 0;
  if (L <= mid) sum += ask(t[id].c[0], t[o].c[0], l, mid, L, R);
  if (R > mid) sum += ask(t[id].c[1], t[o].c[1], mid + 1, r, L, R);
  return sum;
}
void dfs1(int u, int fa) {
  d[u] = d[fa] + 1, siz[u] = 1, f[u] = fa;
  for (register int i = h[u]; i; i = e[i].next) {
    int j = e[i].to;
    if (j == fa) continue;
    dfs1(j, u);
    siz[u] += siz[j];
    if (siz[j] > siz[son[u]]) son[u] = j;
  }
}
void dfs2(int u, int tp) {
  top[u] = tp, p[u] = ++pos, rt[pos] = rt[pos - 1], fp[pos] = u;
  add(rt[pos], rt[pos], 0, m, ti[u]);
  if (son[u]) dfs2(son[u], tp);
  for (register int i = h[u]; i; i = e[i].next) {
    int j = e[i].to;
    if (j == f[u] || j == son[u]) continue;
    dfs2(j, j);
  }
}
int query(int u, int v, int y, int k, int w) {
  bool pd = 0;
  int sum = 0, yv = v;
  zcnt[0] = zcnt[1] = 0;
  if (ti[u] < y || ti[u] > w) k++;
  while (top[u] != top[v]) {
    if (d[top[u]] < d[top[v]]) swap(u, v), pd ^= 1;
    zc[++zcnt[pd]][pd] = node(p[top[u]], p[u]);
    u = f[top[u]];
  }
  if (d[u] > d[v]) swap(u, v), pd ^= 1;
  zc[++zcnt[pd]][pd] = node(p[u], p[v]);
  for (register int i = 1; i <= zcnt[0]; i++) {
    int L = zc[i][0].l, R = zc[i][0].r,
        v = ask(rt[R], rt[L - 1], 0, m, 0, y - 1) +
            ask(rt[R], rt[L - 1], 0, m, w + 1, m);
    if (k > v) {
      k -= v;
      continue;
    }
    int l = L, r = R, ans = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      if (ask(rt[R], rt[mid - 1], 0, m, 0, y - 1) +
              ask(rt[R], rt[mid - 1], 0, m, w + 1, m) >=
          k)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return fp[ans] == yv ? -1 : fp[ans];
  }
  for (register int i = zcnt[1]; i; i--) {
    int L = zc[i][1].l, R = zc[i][1].r,
        v = ask(rt[R], rt[L - 1], 0, m, 0, y - 1) +
            ask(rt[R], rt[L - 1], 0, m, w + 1, m);
    if (k > v) {
      k -= v;
      continue;
    }
    int l = L, r = R, ans = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      if (ask(rt[mid], rt[L - 1], 0, m, 0, y - 1) +
              ask(rt[mid], rt[L - 1], 0, m, w + 1, m) >=
          k)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return fp[ans] == yv ? -1 : fp[ans];
  }
  return -1;
}
int main() {
  int op, x;
  n = read();
  for (register int i = 1; i <= n; i++) {
    x = read();
    addedge(x, i), addedge(i, x);
  }
  m = read();
  for (register int i = 1; i <= m; i++) {
    op = read(), x = read();
    if (op == 1)
      ti[x] = i;
    else
      w[i].u = x, w[i].v = read(), w[i].k = read(), w[i].y = read() + 1;
  }
  dfs1(1, 0), dfs2(1, 1);
  for (register int i = 1; i <= m; i++) {
    if (!w[i].u) continue;
    printf("%d\n", query(w[i].u, w[i].v, w[i].y, w[i].k, i));
  }
  return 0;
}
