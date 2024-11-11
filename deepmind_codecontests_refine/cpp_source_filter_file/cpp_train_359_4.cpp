#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
struct Point {
  double x, y;
  int idx;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  bool operator==(const Point &rhs) const {
    return abs(x - rhs.x) < eps && (y - rhs.y) < eps;
  }
  bool operator<(const Point &rhs) const {
    return x < rhs.x || (abs(x - rhs.x) < eps && y < rhs.y);
  }
};
Point operator-(Point p1, Point p2) { return Point(p1.x - p2.x, p1.y - p2.y); }
double Cross(Point p1, Point p2) { return p1.x * p2.y - p2.x * p1.y; }
Point p[200010], cvx[200010];
bool ans[200010];
int pos[200010];
bool cmp(double x) { return x < 0 || abs(x) < eps; }
int ConvexHull(int n) {
  sort(p, p + n);
  int tot = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && p[i] == p[i - 1]) {
      pos[i] = pos[i - 1];
      continue;
    }
    pos[i] = i;
    while (tot > 1 &&
           cmp(Cross(cvx[tot - 1] - cvx[tot - 2], p[i] - cvx[tot - 2])) == true)
      tot--;
    cvx[tot++] = p[i];
  }
  int k = tot;
  for (int i = n - 2; i >= 0; i--) {
    while (tot > k &&
           cmp(Cross(cvx[tot - 1] - cvx[tot - 2], p[i] - cvx[tot - 2]) == true))
      tot--;
    cvx[tot++] = p[i];
  }
  if (n > 1) tot--;
  return tot;
}
bool cmp2(const Point &p1, const Point &p2) {
  return p1.y < p2.y || (abs(p1.y - p2.y) < eps && p1.x < p2.x);
}
int main(void) {
  int n;
  while (~scanf("%d", &n)) {
    memset(ans, false, sizeof(ans));
    memset(pos, 0, sizeof(pos));
    double minv1 = inf, minv2 = inf;
    for (int i = 0; i < n; i++) {
      double s, r;
      scanf("%lf%lf", &s, &r);
      minv1 = min(10000 / r, minv1);
      minv2 = min(minv2, 10000 / s);
      p[i] = Point(10000 / s, 10000 / r);
      p[i].idx = i;
    }
    int tot = ConvexHull(n);
    for (int i = 0; i < tot; i++) {
      ans[cvx[i].idx] = true;
      if (abs(cvx[i].y - minv1) < eps) break;
    }
    for (int i = 0; i < n; i++) {
      if (ans[p[pos[i]].idx] == true) ans[p[i].idx] = true;
    }
    for (int i = 0; i < n; i++)
      if (ans[i] == true) printf("%d ", i + 1);
    printf("\n");
  }
  return 0;
}
