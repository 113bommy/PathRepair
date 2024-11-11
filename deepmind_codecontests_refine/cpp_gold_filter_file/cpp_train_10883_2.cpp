#include <bits/stdc++.h>
using namespace std;
struct Interval {
  Interval() {}
  Interval(double l, double r) {
    left = l;
    right = r;
  }
  bool operator<(const Interval &other) const { return left < other.left; }
  double left;
  double right;
};
struct Circle {
  double x;
  double y;
  double r;
};
const double PI = 3.141592653589793;
const int N = 1e5 + 5;
double X, Y, R;
vector<Interval> vecInt;
Circle circle[N];
double dist[N];
double sqr(double x) { return x * x; }
void getInterval(int i) {
  double arg, offset, a1, a2, left, right;
  Circle c = circle[i];
  if (c.r == 0.0 || c.r + R <= dist[i]) {
    return;
  }
  arg = acos((c.x - X) / dist[i]);
  if (c.y - Y < 0) {
    arg = 2 * PI - arg;
  }
  if (sqrt(sqr(dist[i]) - sqr(c.r)) <= R) {
    offset = asin(c.r / dist[i]);
  } else {
    offset = acos((sqr(R) + sqr(dist[i]) - sqr(c.r)) / (2 * R * dist[i]));
  }
  a1 = arg + offset;
  a2 = arg - offset;
  if (a1 > 2 * PI) {
    a1 -= 2 * PI;
  }
  if (a2 < 0) {
    a2 += 2 * PI;
  }
  left = min(a1, a2);
  right = max(a1, a2);
  if (right - left <= PI) {
    vecInt.push_back(Interval(left, right));
  } else {
    vecInt.push_back(Interval(0, left));
    vecInt.push_back(Interval(right, 2 * PI));
  }
}
int main() {
  int n, i, v, t;
  double ans = 0;
  bool skip = false;
  scanf("%lf%lf%d%d", &X, &Y, &v, &t);
  R = (double)v * t;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lf%lf%lf", &circle[i].x, &circle[i].y, &circle[i].r);
  }
  for (i = 0; i < n; i++) {
    dist[i] = sqrt(sqr(X - circle[i].x) + sqr(Y - circle[i].y));
    if (dist[i] <= circle[i].r) {
      ans = 1;
      skip = true;
      break;
    }
  }
  if (!skip) {
    for (i = 0; i < n; i++) {
      getInterval(i);
    }
    sort(vecInt.begin(), vecInt.end());
    double right = 0;
    for (i = 0; i < vecInt.size(); i++) {
      if (vecInt[i].right > right) {
        ans += vecInt[i].right - max(vecInt[i].left, right);
        right = vecInt[i].right;
      }
    }
    ans /= 2 * PI;
  }
  printf("%.6lf\n", ans);
  return 0;
}
