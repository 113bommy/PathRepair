#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int x1, x2, y1, y2, a1, a2, sp, l, r, mid;
  double t0, t, t1, t2, diff, best, now;
  while (scanf("%lf %lf %d %d %lf", &t1, &t2, &x1, &x2, &t0) == 5) {
    if (t1 == t2)
      printf("%d %d\n", x1, x2);
    else {
      best = t2 - t0;
      sp = x2;
      a1 = 0, a2 = x2;
      for (y1 = 1; y1 < x1; y1++) {
        l = 0;
        r = x2;
        while (l < r) {
          mid = l + (r - l) / 2;
          if ((t1 * y1 + t2 * mid) / (y1 + mid) < t0)
            l = mid + 1;
          else
            r = mid;
        }
        now = ((t1 * y1 + t2 * r) / (y1 + r));
        if (now >= t0) {
          diff = ((now) > (t0) ? ((now) - (t0)) : ((t0) - (now)));
          if (diff < best) {
            best = diff;
            sp = y1 + r;
            a1 = y1, a2 = r;
          } else if (diff == best) {
            if (y1 + r > sp) {
              sp = y1 + r;
              a1 = y1, a2 = r;
            }
          }
        }
      }
      printf("%d %d\n", a1, a2);
    }
  }
  return 0;
}
