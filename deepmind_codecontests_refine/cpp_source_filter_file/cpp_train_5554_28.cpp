#include <bits/stdc++.h>
using namespace std;
struct pt {
  double x, y;
  pt operator-(pt r) { return {x - r.x, y - r.y}; }
  pt operator+(pt r) { return {x + r.x, y + r.y}; }
  pt operator*(double a) { return {x * a, y * a}; }
  bool operator<(const pt& r) const {
    return (x + 1e-8 > r.x && x - 1e-8 < r.x) ? y < r.y : x < r.x;
  }
  bool operator==(const pt& r) const {
    return (x + 1e-8 > r.x && x - 1e-8 < r.x) &&
           (y + 1e-8 > r.y && y - 1e-8 < r.y);
  };
  double dst(pt r = {0, 0}) {
    return sqrt((x - r.x) * (x - r.x) + (y - r.y) * (y - r.y));
  }
  double XP(pt b) { return x * b.y - y * b.x; }
  double DT(pt& b) { return x * b.x + y * b.y; }
  bool gt() { return ~scanf("%lf%lf", &x, &y); }
};
double xp, yp, vp, x, y, v, r, rp;
pt rot(pt p, double rad) {
  return {p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad)};
}
double dist(pt p1, pt p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }
pt her, me;
double XX(pt& a, pt& b, pt& c) {
  return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}
bool cp(pt a, pt b) {
  return (a.y + 1e-8 > b.y && a.y - 1e-8 < b.y) ? a.x < b.x : a.y < b.y;
}
bool cli(pt o, pt b, double r) {
  pt d = b - o;
  double D = d.x * d.x + d.y * d.y, X = o.XP(b), O = r * r * D - X * X,
         u = abs(d.y) * sqrt(O);
  if (O < 1e-8) return 0;
  pt a = {(X * d.y + d.y / abs(d.x) * d.x * sqrt(O)) / D, (-X * d.x + u) / D},
     A = {(X * d.y - d.y / abs(d.x) * d.x * sqrt(O)) / D, (-X * d.x - u) / D};
  int I = 2;
  if (a.x < min(o.x, b.x) - 1e-8 || a.x > max(o.x, b.x) + 1e-8 ||
      a.y < min(o.y, b.y) - 1e-8 || a.y > max(o.y, b.y) + 1e-8)
    --I, a = A;
  if (A.x < min(o.x, b.x) - 1e-8 || A.x > max(o.x, b.x) + 1e-8 ||
      A.y < min(o.y, b.y) - 1e-8 || A.y > max(o.y, b.y) + 1e-8)
    --I, A = a;
  return I;
}
bool ok(double t) {
  double fspin = (2 * 3.14159265358979323846264338327950288419716939 * rp) / vp;
  double ang = 2 * 3.14159265358979323846264338327950288419716939 *
               ((t / fspin) - floor(t / fspin));
  pt herr = rot(her, ang);
  if (!cli(me, herr, r)) return dist(me, herr) < t * v;
  double dme = dist({0, 0}, me), dher = dist({0, 0}, herr);
  double tme = sqrt(dme * dme - r * r), ther = sqrt(dher * dher - r * r);
  double ttl = tme + ther;
  double ame = atan2(me.y, me.x), aher = atan2(herr.y, herr.x);
  if (ame < 1e-8) ame += 2 * 3.14159265358979323846264338327950288419716939;
  if (aher < 1e-8) aher += 2 * 3.14159265358979323846264338327950288419716939;
  double ftheta =
      min(fabs(ame - aher), 2 * 3.14159265358979323846264338327950288419716939 -
                                fabs(ame - aher));
  double theta = ftheta - acos(r / dme) - acos(r / dher);
  ttl += theta * r;
  return ttl < t * v;
}
double bs(double lo, double hi) {
  double mid = (hi + lo) / 2;
  if (fabs(lo - hi) < 1e-8) return mid;
  if (ok(mid)) return bs(lo, mid);
  return bs(mid, hi);
}
int main() {
  cin >> xp >> yp >> vp >> x >> y >> v >> r;
  her = {xp, yp};
  me = {x, y};
  rp = dist({0, 0}, her);
  cout << setprecision(10) << fixed << bs(0, 1e9) << endl;
  return 0;
}
