#include <bits/stdc++.h>
const int N = 2e5;
struct Edge {
  int to, nxt;
};
struct Node {
  int v, lt;
};
Edge e[N + 10];
int head[N + 10], tote;
int n, m, a[N + 10];
Node t[(N << 2) + 10];
int dfn[N + 10], rk[N + 10], cnt, siz[N + 10];
inline void addEdge(int u, int v) {
  e[++tote].to = v;
  e[tote].nxt = head[u];
  head[u] = tote;
}
void DFS(int u) {
  dfn[u] = ++cnt;
  rk[cnt] = u;
  siz[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    DFS(v);
    siz[u] += siz[v];
  }
}
inline void pushUp(int i) { t[i].v = t[(i << 1)].v + t[(i << 1 | 1)].v; }
inline void pushDown(int i, int l, int r) {
  if (t[i].lt) {
    int mid = (l + r) >> 1;
    t[(i << 1)].lt ^= t[i].lt;
    t[(i << 1 | 1)].lt ^= t[i].lt;
    t[(i << 1)].v = mid - l + 1 - t[(i << 1)].v;
    t[(i << 1 | 1)].v = r - mid - t[(i << 1 | 1)].v;
    t[i].lt = 0;
  }
}
void build(int i, int l, int r) {
  if (l == r) {
    t[i].v = a[rk[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build((i << 1), l, mid);
  build((i << 1 | 1), mid + 1, r);
  pushUp(i);
}
void modify(int i, int l, int r, int ml, int mr) {
  if (ml <= l && r <= mr) {
    t[i].v = r - l + 1 - t[i].v;
    t[i].lt ^= 1;
    return;
  }
  int mid = (l + r) >> 1;
  pushDown(i, l, r);
  if (ml <= mid) modify((i << 1), l, mid, ml, mr);
  if (mr > mid) modify((i << 1 | 1), mid + 1, r, ml, mr);
  pushUp(i);
}
int query(int i, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return t[i].v;
  int mid = (l + r) >> 1;
  pushDown(i, l, r);
  int res = 0;
  if (ql <= mid) res += query((i << 1), l, mid, ql, qr);
  if (qr > mid) res += query((i << 1 | 1), mid + 1, r, ql, qr);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int p;
    scanf("%d", &p);
    addEdge(p, i);
  }
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  DFS(1);
  build(1, 1, n);
  scanf("%d", &m);
  while (m--) {
    char opt[10];
    int u;
    scanf("%s%d", opt, &u);
    if (opt[0] == 'g')
      printf("%d\n", query(1, 1, n, dfn[u], dfn[u] + siz[u] - 1));
    else
      modify(1, 1, n, dfn[u], dfn[u] + siz[u] - 1);
  }
  return 0;
}
