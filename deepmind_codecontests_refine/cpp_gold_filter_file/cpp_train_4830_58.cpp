#include <bits/stdc++.h>
using namespace std;
int n;
double step = 200.0;
double Pi = acos(-1.0), ang;
struct dot {
  double x, y;
  dot(double _x = 0, double _y = 0) { x = _x, y = _y; }
} O, v, w;
dot operator+(dot p, dot q) { return dot(p.x + q.x, p.y + q.y); }
dot operator-(dot p, dot q) { return dot(p.x - q.x, p.y - q.y); }
dot operator*(dot p, double r) { return dot(p.x * r, p.y * r); }
dot operator*(double r, dot p) { return dot(p.x * r, p.y * r); }
double dj(dot p, dot q) { return p.x * q.x + p.y * q.y; }
double cj(dot p, dot q) { return p.x * q.y - p.y * q.x; }
void rot(dot &p, double ang) {
  double x = p.x * cos(ang) - p.y * sin(ang);
  double y = p.y * cos(ang) + p.x * sin(ang);
  p = dot(x, y);
}
dot Getdot(dot P, dot v, dot Q, dot w) {
  dot u = P - Q;
  double t = cj(w, u) / cj(v, w);
  return P + v * t;
}
int main() {
  int i;
  w = v = dot(1.0, 0.0);
  scanf("%d", &n), O = dot(0.0, 0.0);
  if (n <= 4) {
    printf("No solution");
    return 0;
  }
  ang = 2.0 / n * Pi;
  for (i = 1; i < n; i++) {
    if (i == (n + 1) / 2 + 1)
      O = O + 400 * v;
    else
      O = O + step * v, step -= 1e-2;
    rot(v, ang);
    printf("%.5lf %.5lf\n", O.x, O.y);
  }
  O = Getdot(O, v, dot(0, 0), w);
  printf("%.5lf %.5lf", O.x, O.y);
  return 0;
}
