#include <bits/stdc++.h>
using namespace std;
const double PI = acosl(-1), EPS = 1e-10;
struct Point {
  double x, y;
  double len() { return sqrt(x * x + y * y); }
  double ang() { return atan2(y, x); }
  Point operator+(const Point &o) const { return (Point){x + o.x, y + o.y}; }
  Point operator-(const Point &o) const { return (Point){x - o.x, y - o.y}; }
} p[2010];
int n, m;
double dis[2010][2010], ang[2010][2010];
double adjust_angle(double x) {
  while (x < 0) x += 2 * PI;
  while (x >= 2 * PI) x -= 2 * PI;
  return x;
}
int tot;
pair<double, pair<int, int> > data[20010];
void addData(double p, int type, int x) {
  data[++tot] = make_pair(p, make_pair(type, x));
}
bool check(int oi, double r) {
  if (r < EPS) return true;
  Point o = p[oi];
  pair<int, int> cur = make_pair(0, 0);
  tot = 0;
  for (int i = 0; i < n + m; ++i) {
    double len = dis[oi][i];
    if (len < EPS) {
      cur.first += i < n;
      continue;
    }
    if (len > 2 * r) continue;
    double agl = ang[oi][i], alpha = acos((len / 2) / r);
    double u = adjust_angle(agl + alpha);
    double v = adjust_angle(agl - alpha);
    if (u > v) swap(u, v);
    if (v - u > PI) swap(u, v);
    if (i < n) {
      addData(u, 0, 1);
      addData(v, 0, -1);
    } else {
      addData(u, 1, 1);
      addData(v, 1, -1);
    }
    if (u > v) {
      if (i < n) {
        addData(2 * PI, 0, -1);
        addData(0, 0, 1);
      } else {
        addData(2 * PI, 1, -1);
        addData(0, 1, 1);
      }
    }
  }
  if (!tot) return cur.first > 0;
  addData(0, 0, 0);
  addData(2 * PI, 0, 0);
  sort(data + 1, data + tot + 1);
  for (int i = 1, j; i <= tot; i = j) {
    j = i;
    for (; j <= tot && fabs(data[i].first - data[j].first) < EPS; ++j) {
      if (data[j].second.first == 0)
        cur.first += data[j].second.second;
      else
        cur.second += data[j].second.second;
    }
    if (j == tot + 1) return false;
    if (cur.first > 0 && cur.second == 0) return true;
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }
  for (int i = 0; i < m; ++i) {
    int s = i + n;
    scanf("%lf%lf", &p[s].x, &p[s].y);
  }
  for (int i = 0; i < n + m; ++i) {
    for (int j = 0; j < n + m; ++j) {
      dis[i][j] = (p[j] - p[i]).len();
      ang[i][j] = (p[j] - p[i]).ang();
    }
  }
  static int per[2010];
  for (int i = 0; i < n + m; ++i) per[i] = i;
  random_shuffle(per, per + n);
  random_shuffle(per + n, per + n + m);
  double ans = 0.0;
  for (int s = 0; s < n + m; ++s) {
    int i = per[s];
    if (check(i, ans + EPS)) {
      double l = ans, r = 1e10;
      for (int j = 0; j < 50 && r - l > EPS; ++j) {
        double mid = (l + r) / 2;
        if (check(i, mid))
          l = ans = mid;
        else
          r = mid;
      }
    }
  }
  if (ans >= 1e9) ans = -1;
  printf("%.8lf\n", ans);
}
