#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, i, z, x;
  scanf("%d%d", &n, &h);
  double a1, a2, a3, a4;
  a1 = (0.5 * h);
  a2 = a1 / n;
  for (i = 1; i < n; i++) {
    a3 = i * a2;
    x = 100;
    double hi = (h * 1.0);
    double lo = 0.0, mid;
    while (x--) {
      mid = (hi + lo) / 2;
      a4 = 0.5 * (mid * mid) / h;
      if (a4 > a3) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    printf("%lf ", mid);
  }
  return 0;
}
