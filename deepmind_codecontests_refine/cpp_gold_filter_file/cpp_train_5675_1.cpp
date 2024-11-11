#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  int vm, t;
  scanf("%d%d", &vm, &t);
  int vx, vy, wx, wy;
  scanf("%d%d%d%d", &vx, &vy, &wx, &wy);
  double l = 0;
  double r = 100000000;
  for (int i = 1; i <= 10000; i++) {
    double mid = (l + r) / 2;
    double xt1, yt1;
    if (mid > t) {
      xt1 = x1 + vx * t + wx * (mid - t);
      yt1 = y1 + vy * t + wy * (mid - t);
    } else {
      xt1 = x1 + vx * mid;
      yt1 = y1 + vy * mid;
    }
    double dis =
        sqrt(abs(xt1 - x2) * abs(xt1 - x2) + abs(yt1 - y2) * abs(yt1 - y2));
    if (dis / vm > mid) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%.7f", l);
  return 0;
}
