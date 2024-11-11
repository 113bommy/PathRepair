#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  double lx, ly, ux, uy;
  double rx, ry, vx, vy;
  while (cin >> n >> lx >> ly >> ux >> uy) {
    double mn = 0;
    double mx = inf * 10;
    bool bad = 0;
    if (lx == ux || ly == uy) bad = 1;
    for (int i = 0; i < n; ++i) {
      cin >> rx >> ry >> vx >> vy;
      if (!bad) {
        if (vx == 0) {
          if (rx <= lx || rx >= ux) bad = 1;
        } else if (vx > 0) {
          mn = max(mn, (lx - rx) / vx);
          mx = min(mx, (ux - rx) / vx);
        } else {
          mn = max(mn, (ux - rx) / vx);
          mx = min(mx, (lx - rx) / vx);
        }
        if (vy == 0) {
          if (ry <= ly || ry >= uy) bad = 1;
        } else if (vy > 0) {
          mn = max(mn, (ly - ry) / vy);
          mx = min(mx, (uy - ry) / vy);
        } else {
          mn = max(mn, (uy - ry) / vy);
          mx = min(mx, (ly - ry) / vy);
        }
      }
    }
    if (bad || mn > mx || fabs(mn - mx) < eps || mx <= 0)
      printf("-1\n");
    else {
      if (mn < 0) mn = eps;
      printf("%.10lf\n", mn);
    }
  }
  return 0;
}
