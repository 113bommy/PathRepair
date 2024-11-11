#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int x, y, n;
  while (~scanf("%d%d%d", &x, &y, &n)) {
    int a, b, xx, yy;
    double min = 100000 + 10;
    double s = x * 1.0 / y;
    for (b = 1; b <= n; ++b) {
      a = (double)b * x / y;
      double t = 1.0 * (a - 1) / b;
      if (a > 1 && min > fabs(t - s)) {
        min = fabs(t - s);
        xx = a - 1;
        yy = b;
      }
      t = 1.0 * a / b;
      if (min > fabs(t - s)) {
        min = fabs(t - s);
        xx = a;
        yy = b;
      }
      t = (1.0 * a + 1) / b;
      if (min > fabs(t - s)) {
        min = fabs(t - s);
        xx = a + 1;
        yy = b;
      }
    }
    printf("%d/%d", xx, yy);
    printf("\n");
  }
  return 0;
}
