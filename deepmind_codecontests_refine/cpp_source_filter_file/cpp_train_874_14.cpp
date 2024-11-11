#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int n, ans;
double a[2000];
struct Line {
  double x, y, vx, vy;
  void read() {
    double t1, t2;
    scanf("%lf%lf%lf%lf%lf%lf", &t1, &x, &y, &t2, &vx, &vy);
    vx -= x;
    vy -= y;
    vx /= t2 - t1;
    vy /= t2 - t1;
    x -= t1 * vx;
    y -= t1 * vy;
  }
} line[2000];
struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  double det(point res) { return x * res.y - y * res.x; }
  bool operator<(const point& rhs) const {
    if (abs(x * rhs.y - y * rhs.x) < eps) {
      if (abs(x - rhs.x) < eps) return y < rhs.y;
      return x < rhs.x;
    } else
      return abs(x * rhs.y - y * rhs.x) < 0;
  }
} b[2000];
int main() {
  scanf("%d", &n);
  if (n) ans = 1;
  for (int i = 1; i <= n; i++) line[i].read();
  for (int id = 1; id <= n; id++) {
    int tot = 0;
    for (int j = 1; j <= n; j++)
      if (id != j) {
        double vx = line[j].vx - line[id].vx, vy = line[j].vy - line[id].vy;
        double t = fabs(vx) > eps   ? (line[j].x - line[id].x) / vx
                   : fabs(vy) > eps ? (line[j].y - line[id].y) / vy
                                    : 0;
        if (fabs(line[j].x - line[id].x - t * vx) <= eps &&
            fabs(line[j].y - line[id].y - t * vy) <= eps)
          a[++tot] = t, b[tot] = point(vx, vy);
      }
    sort(a + 1, a + 1 + tot);
    int cnt = 0;
    for (int i = 1; i <= tot; i++) {
      if (i == 1 || a[i] - a[i - 1] >= eps)
        cnt = 1;
      else
        cnt++;
      ans = max(ans, cnt + 1);
    }
    sort(b + 1, b + tot + 1);
    cnt = 0;
    for (int i = 1; i <= tot; i++) {
      if (i == 1 || fabs(b[i].det(b[i - 1])) > eps)
        cnt = 1;
      else if (fabs(b[i].x - b[i - 1].x) > eps ||
               fabs(b[i].y - b[i - 1].y) > eps)
        cnt++;
      ans = max(ans, cnt + 1);
    }
  }
  cout << ans << endl;
}
