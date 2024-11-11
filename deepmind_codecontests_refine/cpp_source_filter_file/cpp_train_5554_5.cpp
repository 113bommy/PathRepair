#include <bits/stdc++.h>
const double EPS = 1e-7, pi = 3.141592653589793;
struct unit {
  double x, y;
  unit(double _x = 0, double _y = 0) : x(_x), y(_y) {}
  double cross(const unit &A) const { return x * A.y - y * A.x; }
  inline double len() const { return sqrt(x * x + y * y); }
  double operator*(const unit &A) const { return x * A.x + y * A.y; }
  unit operator*(const double &A) const { return unit(x * A, y * A); }
  unit operator-(const unit &A) const { return unit(x - A.x, y - A.y); }
  unit operator+(const unit &A) const { return unit(x + A.x, y + A.y); }
  unit operator/(const double &A) const { return unit(x / A, y / A); }
  inline void out() { printf("%.6lf %.6lf\n", x, y); }
};
void rotate(unit &A, double the) {
  double x = A.x * cos(the) - A.y * sin(the),
         y = A.x * sin(the) + A.y * cos(the);
  A = unit(x, y);
}
double r, R, v;
unit now;
void tangentpoint(unit p, unit &A, unit &B) {
  double d = p.len();
  p = p / d;
  double cost = r / d, sint = sqrt(d * d - r * r) / d;
  unit ver = unit(-p.y, p.x);
  A = (p * r * cost) + (ver * r * sint);
  B = (p * r * cost) - (ver * r * sint);
}
inline double min(double a, double b) { return a < b ? a : b; }
double arclength(unit A, unit B) {
  return r * acos((A * B) / A.len() / B.len());
}
double calcdis(unit &now, unit tar) {
  unit u = unit() - now, v = tar - now;
  unit t1, t2, a, b;
  tangentpoint(now, t1, t2);
  tangentpoint(tar, a, b);
  if (v.len() < (t1 - now).len() + sqrt(R * R - r * r)) {
    return v.len();
  }
  double ans = (t1 - now).len() + (b - tar).len() +
               min(min(arclength(t2, a), arclength(t2, b)),
                   min(arclength(t1, a), arclength(t1, b)));
  return ans;
}
double bs(double l, double u, double st, double w) {
  double low = l, up = u;
  for (int i = 0; i < 100; i++) {
    double mid = (low + up) / 2;
    double d = calcdis(now, unit(R * cos(mid), R * sin(mid)));
    if (st + (mid - l) / w > d / v)
      up = mid;
    else
      low = mid;
  }
  return low;
}
int main() {
  unit tar;
  double vp;
  while (~scanf("%lf%lf%lf", &tar.x, &tar.y, &vp)) {
    scanf("%lf%lf%lf%lf", &now.x, &now.y, &v, &r);
    double theta = acos(now * (unit(-1, 0)) / now.len());
    if (now.y < 0) theta *= -1;
    rotate(now, theta);
    rotate(tar, theta);
    R = tar.len();
    double w = vp / R, T = 2.0 * pi / w;
    double anst = 1e8;
    if (tar.y < -EPS) {
      double theta = acos(tar * unit(1, 0) / tar.len());
      double st = theta / w, et = st + T / 2.0;
      double d1 = calcdis(now, unit(R, 0)), d2 = calcdis(now, unit(-R, 0));
      int k = ceil((d2 / v - et) / (T));
      if (et >= d2 / v) k = 0;
      if (st + k * T < d1 / v + EPS) {
        double tmp = bs(0, pi, st + k * T, +w);
        anst = min(anst, st + k * T + tmp / w);
      }
      st = et;
      et = st + T / 2.0;
      k = ceil((d1 / v - et) / (T));
      if (et >= d1 / v) k = 0;
      if (st + k * T < d2 / v + EPS) {
        double tmp = bs(pi, 2 * pi, st + k * T, w);
        anst = min(anst, st + k * T + (tmp + pi) / w);
      }
      if (calcdis(now, unit(R, 0)) / v < theta / w + EPS) {
        double tmp = bs(-theta, 0, 0, w);
        anst = min(anst, (tmp + theta) / w);
      }
    } else {
      double theta = acos(tar * unit(-1, 0) / tar.len());
      double st = theta / w, et = st + T / 2.0;
      double d1 = calcdis(now, unit(R, 0)), d2 = calcdis(now, unit(-R, 0));
      int k = ceil((d1 / v - et) / (T));
      if (et >= d1 / v) k = 0;
      if (st + k * T < d2 / v + EPS) {
        double tmp = bs(pi, 2 * pi, st + k * T, w);
        anst = min(anst, st + k * T + (tmp + pi) / w);
      }
      st = et;
      et = st + T / 2.0;
      k = ceil((d2 / v - et) / (T));
      if (et >= d2 / v) k = 0;
      if (st + k * T < d1 / v + EPS) {
        double tmp = bs(0, pi, st + k * T, w);
        anst = min(anst, st + k * T + tmp / w);
      }
      if (calcdis(now, unit(-R, 0)) / v < theta / w + EPS) {
        double tmp = bs(pi - theta, pi, 0, w);
        anst = min(anst, (tmp - pi + theta) / w);
      }
    }
    printf("%.10lf\n", anst);
  }
}
