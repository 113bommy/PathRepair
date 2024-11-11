#include <bits/stdc++.h>
using namespace std;
const int N = 200000, M = 200000;
int n, m;
long long ans;
int a[M + 5], b[M + 5], w[M + 5], p[M + 5];
int fa[N + 5], siz[N + 5], flag[N + 5];
bool cmp(int u, int v) { return w[u] > w[v]; }
int root(int u) { return u == fa[u] ? u : fa[u] = root(fa[u]); }
bool merge(int u, int v) {
  u = root(u), v = root(v);
  if (flag[u] && flag[v]) return 0;
  if (u == v) {
    flag[u] = 1;
    return 1;
  }
  if (siz[u] < siz[v]) u ^= v ^= u ^= v;
  fa[v] = u, siz[u] += siz[v], flag[u] |= flag[v];
  return 1;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  for (int i = 1; i <= m; i++) scanf("%d %d %d", &a[i], &b[i], &w[i]), p[i] = i;
  sort(p + 1, p + m + 1, cmp);
  for (int i = 1; i <= m; i++)
    if (merge(a[p[i]], b[p[i]])) ans += w[p[i]];
  printf("%lld", ans);
  return 0;
}
