#include <bits/stdc++.h>
int a[10010], n, k;
double p, l = 0.0, r = 1000.0, m, s;
int main() {
  scanf("%d%d", &n, &k);
  p = 1.0 - k / 100.0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= 35; i++) {
    m = (l + r) / 2.0, s = 0.0;
    for (int j = 1; j <= n; j++)
      (a[j] > m) ? s += (a[j] - m)* p : s -= (m - a[j]);
    (s > 0.0) ? l = m : r = m;
  }
  printf("%.10f\n", m);
  return 0;
}
