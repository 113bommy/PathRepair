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
point P[4], R[100000], V[100000];
bool equals(double a, double b) { return abs(a - b) < 1e-3; }
double cross(point p, point q) { return p.x * q.y - p.y * q.x; }
double get_norm(point p) { return sqrt(p.x * p.x + p.y * p.y); }
bool colineal(point a, point b, point c) {
  return equals(get_norm(c - a) - get_norm(b - a) - get_norm(c - b), 0);
}
bool isOnRectangle(point x) {
  for (int i = 0; i < 4; i++)
    if (cross(x - P[i], P[(i + 1) % 4] - x) *
            cross(P[(i + 2) % 4] - P[i], P[(i + 1) % 4] - P[(i + 2) % 4]) <
        0)
      return false;
  return true;
}
bool isSide(int i) {
  for (int j = 0; j < 4; j++)
    if ((equals(R[i].x, P[j].x) || equals(R[i].y, P[j].y)) &&
        equals(cross(V[i], P[(j + 1) % 4] - P[j]), 0))
      return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cin >> N >> P[0].x >> P[0].y >> P[2].x >> P[2].y;
  P[1] = point(P[0].x, P[2].y);
  P[3] = point(P[2].x, P[0].y);
  for (int i = 0; i < N; i++) cin >> R[i].x >> R[i].y >> V[i].x >> V[i].y;
  double a = 0, b = INFINITY;
  for (int i = 0; i < N; i++) {
    pair<double, double> T(INFINITY, -INFINITY);
    if (equals(V[i].x, 0) && equals(V[i].y, 0) && isOnRectangle(R[i])) continue;
    if (!isSide(i))
      for (int j = 0; j < 4; j++) {
        double t = cross(P[j] - R[i], P[(j + 1) % 4] - P[j]) /
                   cross(V[i], P[(j + 1) % 4] - P[j]);
        point x = R[i] + (V[i] * t);
        if (colineal(P[j], x, P[(j + 1) % 4]))
          T = make_pair(min(T.first, t), max(T.second, t));
      }
    a = max(a, T.first + 1e-15);
    b = min(b, T.second - 1e-15);
  }
  if (a > b)
    cout << "-1\n";
  else
    cout << setprecision(15) << fixed << a << "\n";
}
