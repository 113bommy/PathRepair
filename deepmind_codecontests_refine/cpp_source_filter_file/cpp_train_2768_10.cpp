#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
struct point {
  double x, y;
} p[1024];
point intersection(point u1, point u2, point v1, point v2) {
  point ret = u1;
  double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) /
             ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
  ret.x += (u2.x - u1.x) * t;
  ret.y += (u2.y - u1.y) * t;
  return ret;
}
point ptoline(point p, point l1, point l2) {
  point t = p;
  t.x += l1.y - l2.y, t.y += l2.x - l1.x;
  return intersection(p, t, l1, l2);
}
double dis(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main() {
  int n;
  double ans = 1e9;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
  p[n] = p[0];
  ans = dis(p[0], ptoline(p[0], p[1], p[2]));
  for (int i = 1; i < n; i++) {
    ans = min(ans, dis(p[i], ptoline(p[i], p[i - 1], p[i + 1])));
  }
  printf("%.10f\n", ans / 2);
  return 0;
}
