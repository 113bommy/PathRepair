#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
const double eps = 1e-9, PI = acos(-1.0);
struct Point {
  double x, y;
  Point operator+(const Point &b) const { return (Point){x + b.x, y + b.y}; }
  Point operator-(const Point &b) const { return (Point){x - b.x, y - b.y}; }
  Point operator*(const double &k) const { return (Point){k * x, k * y}; }
  double operator*(const Point &b) const { return x * b.y - y * b.x; }
  double operator^(const Point &b) const { return x * b.x + y * b.y; }
} a[N], q;
int n;
double pre[N], suf[N];
Point Intersect(Point P, Point v, Point Q, Point w) {
  Point u = P - Q;
  double t = (w * u) / (v * w);
  return P + v * t;
}
double Check(double ang) {
  int rev = 0;
  Point ra = (Point){cos(ang), sin(ang)};
  if (ra * (a[1] - q) < 0) rev = 1, ra = ra * -1.0;
  int l = 2, r = n, L, R;
  while (l < r) {
    int mid = l + r >> 1;
    if (ra * (a[mid] - q) < 0)
      r = mid;
    else if ((a[mid] - q) * (a[1] - q) < 0)
      r = mid - 1;
    else
      l = mid + 1;
  }
  L = l;
  r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (ra * (a[mid] - q) < 0)
      l = mid;
    else
      r = mid - 1;
  }
  R = l;
  Point cl = Intersect(q, ra, a[L - 1], a[L] - a[L - 1]),
        cr = Intersect(q, ra, a[R], a[R % n + 1] - a[R]);
  double area = pre[L - 1] + suf[R + 1];
  area += (cl - a[1]) * (a[L - 1] - a[1]);
  area += (cr - a[1]) * (cl - a[1]);
  area += (a[R % n + 1] - a[1]) * (cr - a[1]);
  if (rev) area = pre[n] - area;
  return area - (pre[n] - area);
}
void preCalc() {
  pre[0] = pre[1] = 0;
  for (int i = 2; i <= n; ++i)
    pre[i] = pre[i - 1] + (a[i] - a[1]) * (a[i - 1] - a[1]);
  suf[n] = 0;
  for (int i = n - 1; i; --i)
    suf[i] = suf[i + 1] + (a[i + 1] - a[1]) * (a[i] - a[1]);
}
int main() {
  int Ques;
  scanf("%d%d", &n, &Ques);
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &a[i].x, &a[i].y);
  preCalc();
  while (Ques--) {
    scanf("%lf%lf", &q.x, &q.y);
    double l = 0, r = PI, res0 = Check(0);
    while (l + eps < r) {
      double mid = (l + r) / 2;
      if (res0 * Check(mid) >= 0)
        l = mid;
      else
        r = mid;
    }
    printf("%.20lf\n", l);
  }
  return 0;
}
