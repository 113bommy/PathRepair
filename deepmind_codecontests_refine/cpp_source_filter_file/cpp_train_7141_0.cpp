#include <bits/stdc++.h>
using namespace std;
const int N = 12005, M = 33005, Inf = 0x3f3f3f3f;
int n, a[N], lst[100005], ls[7], s, t, cost;
int eid = 1, he[N], nw[N], q[N], d[N], vs[N];
struct edge {
  int v, nx, c, w;
} e[M * 2];
void add(int u, int v, int c, int w) {
  e[++eid] = {v, he[u], c, w}, he[u] = eid;
  e[++eid] = {u, he[v], 0, -w}, he[v] = eid;
}
int spfa() {
  memset(d, 63, sizeof d), memcpy(nw, he, sizeof he);
  q[0] = s, d[s] = 0, vs[s] = 1;
  for (int l = 0, r = 0; l <= r; l++) {
    int u = q[l % N];
    vs[u] = 0;
    for (int i = he[u], v; (v = e[i].v); i = e[i].nx)
      if (e[i].c && d[u] + e[i].w < d[v]) {
        d[v] = d[u] + e[i].w;
        if (!vs[v]) q[++r % N] = v, vs[v] = 1;
      }
  }
  return d[t] < Inf;
}
int dfs(int u, int lim, int re = 0) {
  if (u == t) return lim;
  vs[u] = 1;
  for (int &i = nw[u], v; v = e[i].v; i = e[i].nx)
    if (!vs[v] && e[i].c && d[v] == d[u] + e[i].w) {
      int t = dfs(v, min(lim, e[i].c));
      e[i].c -= t, e[i ^ 1].c += t, re += t, lim -= t, cost += t * e[i].w;
      if (!lim) break;
    }
  if (lim) d[u] = Inf;
  vs[u] = 0;
  return re;
}
int main() {
  cin >> n;
  s = n * 4 + 1, t = s + 1;
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (n); i >= (1); i--) {
    int i1 = i + n, i2 = i1 + n, i3 = i2 + n;
    int l2 = lst[a[i] - 1], L2 = lst[a[i] + 1], &l3 = ls[a[i] % 7];
    add(s, i, 1, 0), add(i, i1, 1, -1), add(i1, t, 1, 0);
    add(i2, i, 1, 0), add(i3, i, 1, 0);
    auto Add = [&](int i, int l) {
      if (l) add(i, l, 4, 0), add(i1, l, 1, 0);
    };
    Add(i2, l2), Add(i2, L2), Add(i3, l3), lst[a[i]] = l3 = i;
  }
  add(t, t + 1, 4, 0), t++;
  while (spfa()) dfs(s, Inf);
  cout << -cost;
  return 0;
}
