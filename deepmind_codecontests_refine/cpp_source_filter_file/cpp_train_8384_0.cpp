#include <bits/stdc++.h>
int main() {
  int n, l, v1, v2, k;
  scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
  int m = ceil(n / k);
  double t1 =
      1.0 * l / (1.0 * v1 * (m - 1) * (1.0 * (v2 - v1) / (v2 + v1) + 1) + v2);
  double t2 = 1.0 * (v2 - v1) / (v2 + v1) * t1;
  double t3 = (t1 + t2) * (m - 1) + t1;
  printf("%.15lf\n", t3);
  return 0;
}
