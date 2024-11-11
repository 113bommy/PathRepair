#include <bits/stdc++.h>
using namespace std;
int n, m, x[505];
int main() {
  int i, u, v, c;
  double ans = 0, r;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &c);
    r = 1.0 * (x[u] + x[v]) / c;
    ans = max(r, ans);
  }
  printf("%lf\n", ans);
  return 0;
}
