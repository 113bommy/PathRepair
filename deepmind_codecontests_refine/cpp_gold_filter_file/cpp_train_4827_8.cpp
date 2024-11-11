#include <bits/stdc++.h>
int main() {
  int n;
  double ans = 0, tmp = 0, now = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf", &tmp);
    now *= tmp;
    ans += 2 * now + tmp;
    now += tmp;
  }
  printf("%.10f\n", ans);
  return 0;
}
