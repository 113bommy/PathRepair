#include <bits/stdc++.h>
using namespace std;
double x1, y, x2, y2, V, t, vx, vy, wx, wy, i, l, r, vtx, vty;
double calc(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool kt(double i) {
  if (i > t) {
    vtx = vx * t + wx * (i - t);
    vty = vy * t + wy * (i - t);
  } else {
    vtx = vx * i;
    vty = vy * i;
  }
  double kc = calc(vtx + x1, vty + y, x2, y2);
  if (V * i >= kc)
    return true;
  else
    return false;
}
int main() {
  cin >> x1 >> y >> x2 >> y2;
  cin >> V >> t;
  cin >> vx >> vy;
  cin >> wx >> wy;
  l = 0;
  r = 100000000;
  i = (l + r) / 2;
  while (l - r > 0.0000001) {
    if (kt(i) == 1)
      r = i;
    else
      l = i;
    i = (l + r) / 2;
  }
  printf("%.6llf ", i);
}
