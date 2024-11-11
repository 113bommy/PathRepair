#include <bits/stdc++.h>
using namespace std;
long long labs(long long n) { return n < 0 ? -n : n; }
int main() {
  long long t1, t2, x1, x2, t0;
  scanf("%I64d%I64d%I64d%I64d%I64d", &t1, &t2, &x1, &x2, &t0);
  long long sy1 = 0, sy2 = 0;
  double st = 123123123.0;
  if (t2 == t0 && t0 == t1) {
    printf("%I64d %I64d\n", x1, x2);
    return 0;
  } else if (labs(t2 - t0) == labs(t1 - t0)) {
    printf("%I64d %I64d\n", min(x1, x2), min(x2, x1));
    return 0;
  } else if (t2 == t0) {
    printf("0 %I64d\n", x2);
    return 0;
  } else if (t1 == t0) {
    printf("%I64d 0\n", x1);
    return 0;
  }
  const double EPS = 1e-9;
  for (long long y1 = 0; y1 <= x1; y1++) {
    long long y2 = y1 * (t0 - t1) / (t2 - t0);
    if ((y1 * t0 - t1 * y1) % (t2 - t0)) y2++;
    double t = 0.0;
    if (!y1) {
      y2 = x2;
      t = t2;
    }
    if (y1 > 0 && y2 > 0)
      t = (double(t1 * y1) + double(t2 * y2)) / double(y1 + y2);
    if ((y2 >= 0 && y2 <= x2)) {
      if (t + EPS > double(t0)) {
        if (t < st) {
          st = t;
          sy1 = y1;
          sy2 = y2;
        } else if (fabs(t - st) < EPS && y1 + y2 > sy1 + sy2) {
          st = t;
          sy1 = y1;
          sy2 = y2;
        }
      }
    }
  }
  printf("%I64d %I64d\n", sy1, sy2);
  return 0;
}
