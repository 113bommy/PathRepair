#include <bits/stdc++.h>
using namespace std;
int s, x1, x2, t1, t2, p, d, v1, v2;
int main() {
  scanf("%d %d %d", &s, &x1, &x2);
  scanf("%d %d", &t1, &t2);
  scanf("%d %d", &p, &d);
  if (t2 <= t1)
    printf("%d", abs(x1 - x2) * t2);
  else {
    v1 = abs(x1 - x2) * t2;
    if ((p > x1 && d == -1) || (p < x1 && d == 1))
      v2 = abs(p - x1) * t1;
    else {
      if (p > x1) {
        v2 = (2 * s - p - x1) * t1;
        d = 1 - d;
      }
      if (p < x1) {
        v2 = (p + x1) * t1;
        d = 1 - d;
      }
    }
    p = x1;
    if ((p > x2 && d == -1) || (p < x2 && d == 1))
      v2 += abs(p - x2) * t1;
    else {
      if (p > x2) v2 += (2 * s - p - x2) * t1;
      if (p < x2) v2 += (p + x2) * t1;
    }
    printf("%d", min(v1, v2));
  }
  return 0;
}
