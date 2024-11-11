#include <bits/stdc++.h>
int n;
int deg[100010];
double ans, cnt;
int main() {
  scanf("%d%lf", &n, &ans);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    ++deg[u], ++deg[v];
  }
  for (int i = 1; i <= n; ++i)
    if (deg[i] == 1) ++cnt;
  ans = ans / cnt * 2.0;
  printf("%.9lf\n", ans);
  return 0;
}
