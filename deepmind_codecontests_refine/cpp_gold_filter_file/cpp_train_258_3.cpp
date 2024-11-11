#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int N = 1e5 + 5;
const double PI = acos(-1);
struct point {
  double x, y;
};
double dist(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double scal(double x, double y, double x1, double y1, double x3, double y3) {
  pair<double, double> p = make_pair(x1 - x, y1 - y),
                       h = make_pair(x3 - x, y3 - y);
  return p.first * h.first + p.second * h.second;
}
double g(point a, point b, point c) {
  double sc = scal(b.x, b.y, c.x, c.y, a.x, a.y);
  if (sc <= 0) {
    return dist(a, b);
  }
  sc = scal(c.x, c.y, b.x, b.y, a.x, a.y);
  if (sc <= 0) {
    return dist(a, c);
  }
  double x, y, z;
  y = -1;
  if (b.x == c.x) {
    return abs(a.x - b.x);
  }
  x = (b.y - c.y) / (b.x - c.x);
  z = b.y - x * b.x;
  return abs((x * a.x + y * a.y + z) / sqrt(x * x + y * y));
}
int n;
point points[N];
int main() {
  cin >> n;
  cin >> points[0].x >> points[0].y;
  double mn = 1e18, mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> points[i].x >> points[i].y;
    mx = max(mx, dist(points[0], points[i]));
    if (i > 1) {
      mn = min(mn, g(points[0], points[i - 1], points[i]));
    }
  }
  mn = min(mn, g(points[0], points[1], points[n]));
  cout << fixed << setprecision(10) << (mx * mx * PI) - (mn * mn * PI) << endl;
}
