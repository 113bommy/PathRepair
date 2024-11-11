#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
int x, y;
int v, t;
int vx, vy;
int wx, wy;
int main() {
  int xxx, yyy;
  cin >> xxx >> yyy >> x >> y;
  x -= xxx;
  y -= yyy;
  cin >> v >> t;
  cin >> vx >> vy;
  cin >> wx >> wy;
  double a = 0, b = 1e10;
  double best = 1e10;
  for (int it = (0); it < (200); it++) {
    double s = (a + b) / 2;
    double nx = 0;
    double ny = 0;
    nx += min(t + 0., s) * vx;
    ny += min(t + 0., s) * vy;
    if (s > t) {
      nx += (s - t) * wx;
      ny += (s - t) * wy;
    }
    double d = hypot(nx - x, ny - y);
    if (d < s * v)
      best = s, b = s;
    else
      a = s;
  }
  printf("%.10lf\n", best);
  return 0;
}
