#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  void read() { scanf("%lf%lf", &x, &y); }
  bool operator<(const Point& p) const {
    return x < p.x || (x == p.x && y > p.y);
  }
};
Point operator+(const Point& A, const Point& B) {
  return Point(A.x + B.x, A.y + B.y);
}
Point operator-(const Point& A, const Point& B) {
  return Point(A.x - B.x, A.y - B.y);
}
Point operator*(const Point& A, double p) { return Point(A.x * p, A.y * p); }
bool operator==(const Point& A, const Point& B) {
  return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}
double Cross(const Point& A, const Point& B) { return A.x * B.y - A.y * B.x; }
Point GetIntersection(Point P, Point v, Point Q, Point w) {
  Point u = P - Q;
  double t = Cross(w, u) / Cross(v, w);
  return P + v * t;
}
const int maxn = 100000 + 10;
int n;
Point p[maxn], ch[maxn];
int A, B;
int main() {
  scanf("%d%d%d", &n, &A, &B);
  int mx = 1, my = 1;
  for (int i = 0; i < n; i++) {
    p[i].read();
    mx = max(mx, (int)p[i].x);
    my = max(my, (int)p[i].y);
  }
  p[n++] = Point(0, my);
  p[n++] = Point(mx, 0);
  sort(p, p + n);
  n = unique(p, p + n) - p;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    while (tot > 1 &&
           dcmp(Cross(ch[tot - 1] - ch[tot - 2], p[i] - ch[tot - 1])) > 0)
      tot--;
    ch[tot++] = p[i];
  }
  Point t(A, B);
  Point O(0, 0);
  for (int i = 0; i < tot - 1; i++) {
    int d1 = dcmp(Cross(t, ch[i]));
    int d2 = dcmp(Cross(t, ch[i + 1]));
    if (d1 * d2 <= 0) {
      Point P = GetIntersection(O, t, ch[i], ch[i + 1] - ch[i]);
      double ans = A / P.x;
      printf("%.15f\n", ans);
      break;
    }
  }
  return 0;
}
