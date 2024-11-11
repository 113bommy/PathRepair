#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
const double inf = 0x3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const double eps = 1e-6;
int sign(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
struct Point {
  int x, y;
  Point() {}
  Point(int _x, int _y) {
    x = _x;
    y = _y;
  }
} p[maxn];
int cross(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
  long long ans = 0;
  double v[maxn];
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    int k = 0;
    for (int j = 0; j < n; j++) {
      if (i != j) v[cnt++] = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
    }
    sort(v, v + cnt);
    for (int j = 0; j < cnt && v[j] <= eps; j++) {
      while (k < cnt && v[k] < v[j] + pi) k++;
      ans += (long long)(cnt - k + j) * (long long)(cnt - k + j - 1) *
             (long long)(k - j - 1) * (long long)(k - j - 2) / 2;
    }
  }
  printf("%lld\n", ans / 2);
  return 0;
}
