#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
const double EPS = 1e-9;
struct pt {
  double x, y, z;
  pt(double x, double y, double z) : x(x), y(y), z(z) {}
  pt() {}
  double norm2() { return *this * *this; }
  double norm() { return sqrt(norm2()); }
  bool operator==(pt p) {
    return abs(x - p.x) < EPS && abs(y - p.y) < EPS && abs(z - p.z) < EPS;
  }
  pt operator+(pt p) { return pt(x + p.x, y + p.y, z + p.z); }
  pt operator-(pt p) { return pt(x - p.x, y - p.y, z - p.z); }
  pt operator*(double t) { return pt(x * t, y * t, z * t); }
  pt operator/(double t) { return pt(x / t, y / t, z / t); }
  double operator*(pt p) { return x * p.x + y * p.y + z * p.z; }
  void in() { scanf("%lf%lf%lf", &x, &y, &z); }
  void out() { printf("%.15f %.15f %.15f\n", x, y, z); }
};
struct ln {
  pt p, pq;
  ln(pt p, pt q) : p(p), pq(q - p) {}
  ln() {}
  bool has(pt r) { return dist(r) < EPS; }
  bool seghas(pt r) { return has(r) && (r - p) * (r - (p + pq)) - EPS < 0; }
  pt proj(pt r) { return p + pq * ((r - p) * pq / pq.norm2()); }
  double dist(pt r) { return (r - proj(r)).norm(); }
};
int n, vp, vs;
pt pol[MAXN], h;
double calcTime(pt p) { return (p - h).norm() / vp; }
int main() {
  while (scanf("%d", &n) >= 1) {
    for (int i = (0); i < (int)(n + 1); i++) {
      pol[i].in();
    }
    scanf("%d%d", &vp, &vs);
    h.in();
    double t = 0.0;
    bool ok = false;
    for (int i = (0); i < (int)(n); i++) {
      double a = 0.0, b = 1.0, bestT = -1.0;
      int cnt = 300;
      bool tudoOK = false;
      ln r(pol[i], pol[i + 1]);
      while (cnt--) {
        double c = (a + b) / 2.0;
        pt p = r.p + r.pq * c;
        double tott = t + r.pq.norm() * c / vs;
        if (calcTime(p) <= tott + EPS) {
          tudoOK = true;
          bestT = tott;
          b = c;
        } else {
          a = c;
        }
      }
      if (tudoOK) {
        ok = true;
        puts("YES");
        printf("%.15f\n", bestT);
        pt p = r.p + r.pq * a;
        p.out();
        break;
      }
      t += r.pq.norm() / vs;
    }
    if (!ok) puts("NO");
  }
  return 0;
}
