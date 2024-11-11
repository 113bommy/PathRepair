#include <bits/stdc++.h>
int head[111111], next[222222], edge[222222];
int L[111111], R[111111];
int n, m;
int headQ[111111], nextQ[222222], edgeQ[222222];
int f[111111 << 1], g[111111 << 1], a, b;
int ans[111111];
void build(int v, int u) {
  int i, j;
  L[v] = ++n;
  for (i = head[v]; i; i = next[i])
    if ((j = edge[i]) != u) build(j, v);
  R[v] = n;
}
void _insert(int t, int l, int r, int x) {
  if (l == r) {
    g[t] = (f[t] += x) != 0;
    return;
  }
  int p = t << 1, q = p | 1;
  if (a <= l && r <= b) {
    if (!(f[t] += x))
      g[t] = g[p] + g[q];
    else
      g[t] = r - l + 1;
    return;
  }
  int m = (l + r) >> 1;
  if (m >= a) _insert(p, l, m, x);
  if (m < b) _insert(q, m + 1, r, x);
  if (!f[t]) g[t] = g[p] + g[q];
}
void insert(int v, int x) {
  a = L[v], b = R[v];
  _insert(1, 1, n, x);
}
void calc(int v, int u) {
  int i, j;
  if (headQ[v]) {
    insert(v, 1);
    for (i = headQ[v]; i; i = nextQ[i]) insert(edgeQ[i], 1);
  }
  if ((ans[v] = g[1])) --ans[v];
  for (i = head[v]; i; i = next[i])
    if ((j = edge[i]) != u) calc(j, v);
  if (headQ[v]) {
    insert(v, -1);
    for (i = headQ[v]; i; i = nextQ[i]) insert(edgeQ[i], -1);
  }
}
int main() {
  int i, j, k, t = 0;
  scanf("%d%d", &n, &m);
  memset(head, 0, sizeof head);
  for (i = 1; i < n; ++i) {
    scanf("%d%d", &j, &k);
    edge[++t] = k;
    next[t] = head[j];
    head[j] = t;
    edge[++t] = j;
    next[t] = head[k];
    head[k] = t;
  }
  n = 0, build(1, 0);
  memset(headQ, 0, sizeof headQ);
  for (t = 0; m; --m) {
    scanf("%d%d", &j, &k);
    edgeQ[++t] = k;
    nextQ[t] = headQ[j];
    headQ[j] = t;
    edgeQ[++t] = j;
    nextQ[t] = headQ[k];
    headQ[k] = t;
  }
  memset(f, 0, sizeof f);
  memset(g, 0, sizeof g);
  calc(1, 0);
  for (i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
