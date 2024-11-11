#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point() : x(0), y(0) {}
  point(double a, double b) : x(a), y(b) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
  point operator*(double k) { return point(x * k, y * k); }
};
int N;
point P[1000];
double cross(point p, point q) { return p.x * q.y - p.y * q.x; }
double get_norm(point p) { return sqrt(p.x * p.x + p.y * p.y); }
bool isConvex(double d) {
  for (int i = 0; i < N; i++) {
    point u = P[(i + 2) % N] - P[i], v = point(-u.y, u.x) * (d / get_norm(u));
    if (cross(v, u) * cross(P[(i + 1) % N] - P[i], u) < 0) v = v * (-1);
    point a = P[i] + v, b = P[(i + 1) % N] - v, c = P[(i + 2) % N] + v;
    if (cross(b - a, c - b) >= 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cin >> N;
  for (int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;
  double a = 0, b = 1e9;
  for (int i = 0; i < 100; i++) {
    double m = (a + b) / 2;
    if (isConvex(m))
      a = m;
    else
      b = m;
  }
  cout << setprecision(10) << fixed << a;
}
