#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5;
struct Point {
  double x, y;
  Point(double xx = 0, double yy = 0) {
    x = xx;
    y = yy;
  }
  bool operator<(const Point &other) const {
    if (x != other.x) return x < other.x;
    return y < other.y;
  }
};
Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
double operator*(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}
double operator^(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
double norm(Point a) { return a * a; }
double abs(Point a) { return sqrt(norm(a)); }
Point q[800050];
void gethull(Point *p, int n, Point *cov, int &m) {
  int cnt = m = 0;
  for (int i = 1; i <= n; ++i) {
    while (cnt > 1 && ((q[cnt] - q[cnt - 1]) ^ (p[i] - q[cnt - 1])) <= 0) --cnt;
    q[++cnt] = p[i];
  }
  for (int i = 1; i <= cnt; ++i) {
    cov[++m] = q[i];
  }
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    while (cnt > 1 && ((q[cnt] - q[cnt - 1]) ^ (p[i] - q[cnt - 1])) >= 0) --cnt;
    q[++cnt] = p[i];
  }
  for (int i = cnt - 1; i > 1; --i) {
    cov[++m] = q[i];
  }
}
int n, m;
int cnt;
Point a[800050];
Point cov[800050];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    int p, q;
    p = min(x, v);
    q = min(y, v - p);
    a[++cnt] = Point(x - p, y - q);
    q = min(lim - y, v - p);
    a[++cnt] = Point(x - p, y + q);
    p = min(lim - x, v);
    q = min(y, v - p);
    a[++cnt] = Point(x + p, y - q);
    q = min(lim - y, v - p);
    a[++cnt] = Point(x + p, y + q);
    q = min(y, v);
    p = min(x, v - q);
    a[++cnt] = Point(x - p, y - q);
    p = min(lim - x, v - q);
    a[++cnt] = Point(x + p, y - q);
    q = min(lim - y, v);
    p = min(x, v - q);
    a[++cnt] = Point(x - p, y + q);
    p = min(lim - x, v - q);
    a[++cnt] = Point(x + p, y + q);
  }
  sort(a + 1, a + cnt + 1);
  gethull(a, cnt, cov, m);
  int k = -1;
  double t;
  for (int i = 1; i <= m; ++i) {
    int u = i, v = u % m + 1, w = v % m + 1;
    double d = abs(cov[u] - cov[v]) * abs(cov[v] - cov[w]) *
               abs(cov[w] - cov[u]) /
               fabs((cov[u] - cov[v]) ^ (cov[u] - cov[w]));
    if (k == -1 || d > t) {
      k = i;
      t = d;
    }
  }
  int u = k, v = u % m + 1, w = v % m + 1;
  printf("%.0lf %.0lf\n", cov[u].x, cov[u].y);
  printf("%.0lf %.0lf\n", cov[v].x, cov[v].y);
  printf("%.0lf %.0lf\n", cov[w].x, cov[w].y);
  return 0;
}
