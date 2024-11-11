#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
int n;
double p, q;
struct point {
  double x, y;
  point(double xx = 0, double yy = 0) : x(xx), y(yy) {}
  void input() { scanf("%lf%lf", &x, &y); }
  point operator-(const point& tt) const { return point(x - tt.x, y - tt.y); }
  double operator*(const point& tt) const { return x * tt.y - y * tt.x; }
  bool operator<(const point& tt) const {
    if (fabs(x - tt.x) < eps) return y < tt.y;
    return x < tt.x;
  }
  bool operator==(const point& tt) const {
    return fabs(x - tt.x) < eps && fabs(y - tt.y) < eps;
  }
} in[100015];
bool cmp(point a, point b) { return a * b > 0; }
point stk[100015];
int top = 0;
bool check(double t) {
  point tmp(p / t, q / t);
  for (int i = 0; i < n; ++i)
    if ((in[i + 1] - in[i]) * (tmp - in[i]) < eps) return 0;
  return 1;
}
int main() {
  int i, j;
  scanf("%d%lf%lf", &n, &p, &q);
  for (i = 1; i <= n; ++i) in[i].input();
  sort(in + 1, in + 1 + n);
  n = unique(in + 1, in + 1 + n) - in - 1;
  sort(in + 1, in + 1 + n, cmp);
  double maxx = 0, maxy = 0;
  for (i = 1; i <= n; ++i) {
    maxx = max(maxx, in[i].x);
    maxy = max(maxy, in[i].y);
  }
  in[0] = point(maxx, 0.0);
  in[++n] = point(0.0, maxy);
  stk[top++] = in[0];
  stk[top++] = in[1];
  for (i = 2; i <= n; ++i) {
    while (top > 1 &&
           (stk[top - 1] - stk[top - 2]) * (in[i] - stk[top - 2]) < eps)
      --top;
    stk[top++] = in[i];
  }
  n = top - 1;
  for (i = 0; i < top; ++i) in[i] = stk[i];
  double l, r, mid;
  l = 0, r = 1.0e7;
  for (int k = 1; k <= 100; ++k) {
    mid = (l + r) * 0.5;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf\n", l);
  return 0;
}
