#include <bits/stdc++.h>
const int N = 1e5;
int n, m, a[N + 5], b[N + 5], bel[N + N + 5];
struct Edge {
  int u, v, w;
} E[N + N + 5];
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  int tot = 0;
  long long ans = 0;
  for (int s, i = 1; i <= m; i++) {
    scanf("%d", &s);
    for (int x, j = 1; j <= s; j++) {
      scanf("%d", &x);
      E[++tot] = Edge{x, n + i, a[i] + b[x]};
      ans += a[i] + b[x];
    }
  }
  std::sort(E + 1, E + tot + 1,
            [](const Edge &x, const Edge &y) { return x.w > y.w; });
  for (int i = 1; i <= n + m; i++) {
    bel[i] = i;
  }
  std::function<int(int)> find = [&](int x) {
    return bel[x] == x ? x : bel[x] = find(bel[x]);
  };
  for (int i = 1; i <= tot; i++) {
    int u = find(E[i].u), v = find(E[i].v);
    if (u != v) {
      bel[v] = u;
      ans -= E[i].w;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
