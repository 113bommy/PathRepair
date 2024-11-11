#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
void Open() {}
long long t1, t2, X1, X2, t0;
long long cmp(long long ay1, long long ay2, long long by1, long long by2) {
  if ((ay1 * t1 + ay2 * t2) * (by1 + by2) < (by1 * t1 + by2 * t2) * (ay1 + ay2))
    return -1;
  if ((ay1 * t1 + ay2 * t2) * (by1 + by2) ==
      (by1 * t1 + by2 * t2) * (ay1 + ay2))
    return 0;
  return 1;
}
int main() {
  scanf("%I64d%I64d%I64d%I64d%I64d", &t1, &t2, &X1, &X2, &t0);
  if (t0 == t2 && t1 == t0) {
    printf("%I64d %I64d\n", X1, X2);
    return 0;
  }
  if (t1 == t0) {
    printf("%I64d %I64d\n", X1, 0LL);
    return 0;
  }
  if (t0 == t2) {
    printf("%I64d %I64d\n", 0LL, X2);
    return 0;
  }
  long long y1 = 0, y2 = X2;
  for (long long i = 0; i <= X1; i++) {
    double cur = (double)(t1 - t0) / (t0 - t2) * i;
    long long cy2 = ceil(cur);
    if (cy2 <= X2 && (t1 * i + t2 * cy2) >= (i + cy2) * t0 &&
        cmp(i, cy2, y1, y2) <= 0) {
      if (cmp(i, cy2, y1, y2) == 0 && i + cy2 > y1 + y2) {
        y1 = i, y2 = cy2;
      } else if (cmp(i, cy2, y1, y2) == -1) {
        y1 = i, y2 = cy2;
      }
    }
  }
  printf("%I64d %I64d\n", y1, y2);
  return 0;
}
