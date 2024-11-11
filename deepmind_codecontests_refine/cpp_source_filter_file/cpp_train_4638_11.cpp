#include <bits/stdc++.h>
using namespace std;
const int Maxn = 10000 + 10;
const int INF = 0x7f7f7f7f;
const double eps = 1e-10;
inline int compare(double a, double b) {
  return (a > b + eps) ? 1 : ((a + eps < b) ? -1 : 0);
}
struct Point {
  double x, y, z;
  Point() {}
  Point(double x1, double y1, double z1) : x(x1), y(y1), z(z1) {}
  double dist(Point &p) {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y) +
                (z - p.z) * (z - p.z));
  }
  Point operator+(const Point &p) const {
    return Point(x + p.x, y + p.y, z + p.z);
  }
  Point operator-(const Point &p) const {
    return Point(x - p.x, y - p.y, z - p.z);
  }
  Point operator*(const double &t) const { return Point(x * t, y * t, z * t); }
};
int n;
double v1, v2;
Point p[Maxn], h, ans;
bool check(double m) {
  double tmp = m;
  Point t1 = p[n];
  for (int i = 0; i < n; i++) {
    if (tmp > p[i].dist(p[i + 1]) / v2)
      tmp -= p[i].dist(p[i + 1]) / v2;
    else {
      Point t = p[i + 1] - p[i];
      t1 = t * (tmp * v2 / p[i].dist(p[i + 1]));
      t1 = t1 + p[i];
      break;
    }
  }
  if (compare(t1.dist(h), m * v1) <= 1) {
    ans = t1;
    return true;
  }
  return false;
}
int main() {
  double sum = 0;
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i <= n; i++) cin >> p[i].x >> p[i].y >> p[i].z;
  cin >> v1 >> v2;
  cin >> h.x >> h.y >> h.z;
  for (int i = 0; i < n; i++) sum += p[i].dist(p[i + 1]);
  if (compare(sum / v2, p[n].dist(h) / v1) == -1) {
    cout << "NO\n";
    return 0;
  }
  double l = 0, r = 1e9, m;
  while (abs(r - l) >= eps) {
    m = (l + r) * 0.5;
    if (check(m))
      r = m;
    else
      l = m;
  }
  printf("YES\n");
  printf("%.10lf\n", l);
  printf("%.10lf %.10lf %.10lf\n", ans.x, ans.y, ans.z);
  return 0;
}
