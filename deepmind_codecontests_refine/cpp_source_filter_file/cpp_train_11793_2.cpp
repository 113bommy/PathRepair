#include <bits/stdc++.h>
int main() {
  double x;
  double n, R, r;
  double L, l, c, total = 2 * 3.14159265358979323846;
  scanf("%lf%lf%lf", &n, &R, &r);
  L = R - r;
  l = r + r;
  if (L < 0) {
    c = total * 2;
  } else if (L == 0)
    c = total;
  else {
    x = (1 - (l * l) / (2 * L * L));
    if (x < -1) {
      c = total;
    } else if (x > 1) {
      c = 0;
    } else {
      c = acos(x);
    }
  }
  double eps = 0.00001;
  double count = total / c;
  if (count > n || fabs(count - n) < eps)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
