#include <bits/stdc++.h>
int main() {
  int n, i;
  double p, get = 0.0, ans = 0.0;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%lf", &p);
    ans += (get * 2 + 1) * p;
    get = (get + 1) * p;
  }
  printf("%lf\n", ans);
  return 0;
}
