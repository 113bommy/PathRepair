#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
const long long mod = 1000000007;
const int maxn = 2e5 + 100;
int n;
int head[maxn];
int cnt = 0;
int in[maxn], out[maxn], fin[maxn];
int d[maxn];
struct edge {
  int to, next;
} e[maxn * 2];
struct Edge {
  int u, v, w;
  Edge(int a = 0, int b = 0, int c = 0) : u(a), v(b), w(c) {}
} edge[maxn * 2];
struct node {
  int l, r;
  long long mi;
  long long lazy;
} seg[maxn * 4];
int tol = 0;
void add(int u, int v) {
  e[++tol].to = v, e[tol].next = head[u], head[u] = tol;
  e[++tol].to = u, e[tol].next = head[v], head[v] = tol;
}
void dfs(int x, int f) {
  in[x] = ++cnt;
  fin[cnt] = x;
  for (int i = head[x]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == f) continue;
    dfs(v, x);
  }
  out[x] = cnt;
}
void pushdown(int i) {
  if (seg[i].l != seg[i].r && seg[i].lazy) {
    seg[i * 2].mi += seg[i].lazy;
    seg[i * 2].lazy += seg[i].lazy;
    seg[i * 2 + 1].mi += seg[i].lazy;
    seg[i * 2 + 1].lazy += seg[i].lazy;
    seg[i].lazy = 0;
  }
}
void pushup(int i) {
  if (seg[i].l != seg[i].r) {
    seg[i].mi = min(seg[i * 2].mi, seg[i * 2 + 1].mi);
  }
}
void build(int i, int l, int r) {
  seg[i].l = l, seg[i].r = r;
  seg[i].lazy = 0;
  if (l == r) {
    seg[i].mi = d[fin[l]];
    return;
  }
  int m = (l + r) / 2;
  build(i * 2, l, m);
  build(i * 2 + 1, m + 1, r);
  pushup(i);
}
void update(int i, int l, int r, long long v) {
  if (seg[i].l == l && seg[i].r == r) {
    seg[i].mi += v;
    seg[i].lazy += v;
    return;
  }
  pushdown(i);
  int m = (seg[i].l + seg[i].r) / 2;
  if (r <= m)
    update(i * 2, l, r, v);
  else if (l > m)
    update(i * 2 + 1, l, r, v);
  else {
    update(i * 2, l, m, v);
    update(i * 2 + 1, m + 1, r, v);
  }
  pushup(i);
}
long long query(int i, int l, int r) {
  if (seg[i].l == l && seg[i].r == r) {
    return seg[i].mi;
  }
  pushdown(i);
  int m = (seg[i].l + seg[i].r) / 2;
  if (r <= m)
    return query(i * 2, l, r);
  else if (l > m)
    return query(i * 2 + 1, l, r);
  else
    return min(query(i * 2, l, m), query(i * 2 + 1, m + 1, r));
}
int main() {
  int q;
  scanf("%d%d", &n, &q);
  tol = 0;
  cnt = 0;
  memset(head, 0, sizeof(head));
  for (int i = 1; i < 2 * n - 1; i++) {
    scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    if (i < n)
      add(edge[i].u, edge[i].v);
    else
      d[edge[i].u] = edge[i].w;
  }
  dfs(1, 0);
  build(1, 1, n);
  for (int i = 1; i < n; i++)
    update(1, in[edge[i].v], out[edge[i].v], edge[i].w);
  while (q--) {
    int k, u, v;
    scanf("%d%d%d", &k, &u, &v);
    if (k == 1) {
      if (u < n) {
        int t = edge[u].w;
        update(1, in[edge[u].v], out[edge[u].v], v - t);
      } else {
        update(1, in[edge[u].u], in[edge[u].u], v - edge[u].w);
        d[edge[u].u] = v;
      }
      edge[u].w = v;
    } else if (k == 2) {
      long long ans = query(1, in[v], in[v]) - d[v];
      ans += query(1, in[u], out[u]) - (query(1, in[u], out[u]) - d[u]);
      if (in[u] <= in[v] && out[v] <= out[u]) {
        long long t =
            query(1, in[v], in[v]) - d[v] - query(1, in[u], in[u]) + d[u];
        ans = min(ans, t);
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
