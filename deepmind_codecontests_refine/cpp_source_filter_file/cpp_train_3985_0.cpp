#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m;
int a[MAXN], b[MAXN], tot = 0, fa[MAXN];
struct Edge {
  int u, v, w;
} E[MAXN << 1];
bool cmp(const struct Edge& a, const struct Edge& b) { return a.w > b.w; }
int findSet(int x) {
  if (x != fa[x]) fa[x] = findSet(fa[x]);
  return fa[x];
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1, sz; i <= m; i++) {
    scanf("%d", &sz);
    for (int j = 1, x; j <= sz; j++) {
      scanf("%d", &x);
      E[++tot] = {i, m + x, a[i] + b[x]};
    }
  }
  for (int i = 1; i <= n + m; i++) fa[i] = i;
  sort(E + 1, E + 1 + tot, cmp);
  long long ans = 0;
  for (int i = 1; i <= n + m; i++) fa[i] = i;
  for (int i = 1; i <= tot; i++) {
    int pu = findSet(E[i].u), pv = findSet(E[i].v);
    if (pu != pv)
      fa[pv] = pu;
    else
      ans += (long long)E[i].w;
  }
  printf("%lld\n", ans);
  return 0;
}
