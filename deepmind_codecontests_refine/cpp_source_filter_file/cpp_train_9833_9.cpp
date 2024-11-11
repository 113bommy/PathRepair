#include <bits/stdc++.h>
int main() {
  int n, m;
  double res;
  scanf("%d %d", &n, &m);
  if (n == 1 && m == 1)
    res = 1.0;
  else {
    res = 1.0 / n + (n - 1) * (m - 1) / n / (n * m - 1);
  }
  printf("%.10lf\n", res);
  return 0;
}
