#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Pt {
  T x, y;
  Pt() {}
  Pt(T _x, T _y) : x(_x), y(_y) {}
  Pt(const Pt<T>& pt) : x(pt.x), y(pt.y) {}
  Pt<T> operator+(const Pt<T> pt) const { return Pt<T>(x + pt.x, y + pt.y); }
  Pt<T> operator-() const { return Pt<T>(-x, -y); }
  Pt<T> operator-(const Pt<T> pt) const { return Pt<T>(x - pt.x, y - pt.y); }
  Pt<T> operator*(T t) const { return Pt<T>(x * t, y * t); }
  Pt<T> operator/(T t) const { return Pt<T>(x / t, y / t); }
  T dot(Pt<T> v) const { return x * v.x + y * v.y; }
  T cross(Pt<T> v) const { return x * v.y - y * v.x; }
  Pt<T> mid(const Pt<T> pt) { return Pt<T>((x + pt.x) / 2, (y + pt.y) / 2); }
  T d2() { return x * x + y * y; }
  double d() { return sqrt(d2()); }
  Pt<T> rot(double th) {
    double c = cos(th), s = sin(th);
    return Pt<T>(c * x - s * y, s * x + c * y);
  }
  Pt<T> rot90() { return Pt<T>(-y, x); }
  bool operator==(const Pt<T> pt) const { return x == pt.x && y == pt.y; }
  bool operator<(const Pt<T>& pt) const {
    return x < pt.x || (x == pt.x && y < pt.y);
  }
  void print() { printf("(%lf,%lf)\n", x, y); }
};
struct CL {
  Pt<double> p;
  double t0, t1;
  CL() {}
  CL(const Pt<double>& _p, double _t0, double _t1) : p(_p), t0(_t0), t1(_t1) {}
};
bool cross_lines(const Pt<double> ap, const Pt<double> av, const Pt<double> bp,
                 const Pt<double> bv, CL& cl) {
  double op01 = av.cross(bv);
  if (op01 == 0.0) {
    Pt<double> v = bp - ap;
    if (v.cross(av) != 0.0) return false;
    Pt<double> a1 = ap + av;
    Pt<double> b1 = bp + bv;
    return ((bp - ap).dot(b1 - ap) <= 0.0 || (bp - a1).dot(b1 - a1) <= 0.0 ||
            (ap - bp).dot(a1 - bp) <= 0.0 || (ap - b1).dot(a1 - b1) <= 0.0);
  }
  Pt<double> v = bp - ap;
  double op0 = v.cross(av);
  double op1 = v.cross(bv);
  double t0 = op1 / op01;
  double t1 = op0 / op01;
  cl.p = bv * t1 + bp;
  cl.t0 = t0;
  cl.t1 = t1;
  return true;
}
int main() {
  int y0, y1, wy, bx, by, r;
  scanf("%d%d%d%d%d%d", &y0, &y1, &wy, &bx, &by, &r);
  Pt<double> sp(0, y0 + r), gp(bx, 2 * (wy - r) - by), v(gp - sp);
  CL cl;
  cross_lines(sp, v, Pt<double>(0, y1), v.rot90(), cl);
  if (Pt<double>(cl.p.x, cl.p.y - y1).d2() < (double)r * r)
    puts("-1");
  else {
    cross_lines(sp, v, Pt<double>(0, wy - r), Pt<double>(1, 0), cl);
    printf("%.10lf\n", cl.p.x);
  }
  return 0;
}
