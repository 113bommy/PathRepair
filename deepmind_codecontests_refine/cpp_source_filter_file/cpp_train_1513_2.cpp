#include <bits/stdc++.h>
int main() {
  long long t;
  int n;
  double x, y, m;
  scanf("%d%I64d", &n, &t);
  if (t == 0)
    printf("%d\n", &n);
  else {
    y = log10(1.000000011);
    x = t * y;
    m = pow(10, x);
    printf("%.7lf\n", m * 1000);
  }
}
