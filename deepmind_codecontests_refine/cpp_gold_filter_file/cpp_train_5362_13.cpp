#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int main() {
  int x1, y1;
  scanf("%d", &x1), scanf("%d", &y1);
  int x2, y2;
  scanf("%d", &x2), scanf("%d", &y2);
  int vm, t;
  scanf("%d", &vm), scanf("%d", &t);
  int vx, vy;
  scanf("%d", &vx), scanf("%d", &vy);
  int wx, wy;
  scanf("%d", &wx), scanf("%d", &wy);
  double lb = 0, ub = 1e50;
  while (ub - lb > 1e-9) {
    double m = lb + (ub - lb) / 2;
    double x, y;
    if (m < t) {
      x = x2 - vx * m - x1;
      y = y2 - vy * m - y1;
    } else {
      x = x2 - 1.0 * vx * t - wx * (m - t) - x1;
      y = y2 - 1.0 * vy * t - wy * (m - t) - y1;
    }
    double d = sqrt(x * x + y * y);
    if (d / vm <= m) {
      ub = m;
    } else {
      lb = m;
    }
  }
  printf("%.18lf\n", lb);
}
