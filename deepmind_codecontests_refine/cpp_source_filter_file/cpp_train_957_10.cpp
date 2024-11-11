#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x1, x2, t1, t2, t0;
  scanf("%lld%lld%lld%lld%lld", &t1, &t2, &x1, &x2, &t0);
  long long y1 = -1, y2 = -1;
  double minp = 100000000.0;
  if (t1 == t2) {
    printf("%lld %lld", x1, x2);
    return 0;
  }
  if (t0 == t2) {
    printf("0 %lld", x1, x2);
    return 0;
  }
  for (int i = 0; i <= x1; i++) {
    long long l = 0, r = x2;
    long long t;
    while (l < r - 1) {
      t = l + (r - l) / 2;
      if ((double(i * t1 + t * t2)) / (double(i + t)) <= t0)
        l = t;
      else
        r = t;
    }
    if ((l != 0 || i != 0) &&
        (double(i * t1 + l * t2)) / (double(i + l)) >= t0 &&
        abs((double(i * t1 + l * t2)) / (double(i + l)) - t0) <=
            minp + 0.000000000001) {
      minp = abs((double(i * t1 + l * t2)) / (double(i + l)) - t0);
      y1 = i, y2 = l;
    } else {
      if ((double(i * t1 + r * t2)) / (double(i + r)) >= t0 &&
          abs((double(i * t1 + r * t2)) / (double(i + r)) - t0) <=
              minp + 0.000000000001) {
        minp = abs((double(i * t1 + r * t2)) / (double(i + r)) - t0);
        y1 = i, y2 = r;
      }
    }
  }
  if (y1 == -1) {
    printf("0 %lld", x2);
    return 0;
  }
  if (y1 == 0) {
    printf("0 %lld", x2);
    return 0;
  }
  if (y2 == 0) {
    printf("%lld 0", x1);
    return 0;
  }
  { printf("%lld %lld", y1, y2); }
  return 0;
}
