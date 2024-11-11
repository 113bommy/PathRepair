#include <bits/stdc++.h>
using namespace std;
class VagueDouble {
 public:
  double vd;
  VagueDouble() { vd = (1ll << (int)(60)); }
  VagueDouble(const double d) { vd = d; }
  VagueDouble operator+(const VagueDouble VD) const {
    return VagueDouble(vd + VD.vd);
  }
  VagueDouble operator-(const VagueDouble VD) const {
    return VagueDouble(vd - VD.vd);
  }
  VagueDouble operator*(const VagueDouble VD) const {
    return VagueDouble(vd * VD.vd);
  }
  VagueDouble operator/(const VagueDouble VD) const {
    return VagueDouble(vd / VD.vd);
  }
  VagueDouble operator+(const double d) const { return VagueDouble(vd + d); }
  VagueDouble operator-(const double d) const { return VagueDouble(vd - d); }
  VagueDouble operator*(const double d) const { return VagueDouble(vd * d); }
  VagueDouble operator/(const double d) const { return VagueDouble(vd / d); }
  bool operator<(const VagueDouble VD) const {
    return vd + (double)0.00000000001 < VD.vd;
  }
  bool operator>(const VagueDouble VD) const {
    return vd - (double)0.00000000001 > VD.vd;
  }
  bool operator==(const VagueDouble VD) const {
    return !(vd + (double)0.00000000001 < VD.vd) &&
           !(vd - (double)0.00000000001 > VD.vd);
  }
  bool operator<(const double d) const {
    return vd + (double)0.00000000001 < d;
  }
  bool operator>(const double d) const {
    return vd - (double)0.00000000001 > d;
  }
  bool operator==(const double d) const {
    return !(vd - (double)0.00000000001 > d) &&
           !(vd + (double)0.00000000001 < d);
  }
  void operator+=(const VagueDouble VD) { *this = *this + VD; }
  void operator-=(const VagueDouble VD) { *this = *this - VD; }
  void operator*=(const VagueDouble VD) { *this = *this * VD; }
  void operator/=(const VagueDouble VD) { *this = *this / VD; }
  double to_double() { return vd; }
  friend std::ostream &operator<<(std::ostream &os, const VagueDouble VD) {
    os << VD.vd;
    return os;
  }
  friend std::istream &operator>>(std::istream &is, VagueDouble &VD) {
    double d;
    is >> d;
    VD == VagueDouble(d);
    return is;
  }
};
class P {
 private:
  VagueDouble px, py;

 public:
  P() {
    px = (1ll << (int)(60));
    py = (1ll << (int)(60));
  }
  P(double _x, double _y) {
    px = _x;
    py = _y;
  }
  P(VagueDouble _x, VagueDouble _y) {
    px = _x;
    py = _y;
  }
  P operator+(const P p) const { return P(px + p.px, py + p.py); }
  P operator-(const P p) const { return P(px - p.px, py - p.py); }
  P operator*(const double d) const { return P(px * d, py * d); }
  P operator/(const double d) const { return P(px / d, py / d); }
  bool operator<(const P &p) const {
    return (px == p.px) ? (py < p.py) : (px < p.px);
  }
  bool operator>(const P &p) const {
    return (px == p.px) ? (py > p.py) : (px > p.px);
  }
  bool operator==(const P &p) const { return (px == p.px) && (py == p.py); }
  void operator+=(const P &p) { *this = *this + p; }
  void operator-=(const P &p) { *this = *this - p; }
  void operator*=(const double &p) { *this = *this * p; }
  void operator/=(const double &p) { *this = *this / p; }
  double x() { return px.vd; }
  double y() { return py.vd; }
  double sqr(double d) { return d * d; }
  double dist(P p0, P p1) {
    return sqrt(sqr(p0.x() - p1.x()) + sqr(p0.y() - p1.y()));
  }
  friend std::ostream &operator<<(std::ostream &os, const P &p) {
    os << p.px.vd << "," << p.py.vd;
    return os;
  }
  friend std::istream &operator>>(std::istream &is, P &p) {
    double _x, _y;
    is >> _x >> _y;
    p = P(_x, _y);
    return is;
  }
};
VagueDouble sqr(VagueDouble VD) { return VD.vd * VD.vd; }
VagueDouble sqr(double d) { return d * d; }
VagueDouble sqrt(VagueDouble VD) { return VagueDouble(sqrt(VD.vd)); }
VagueDouble dist(P p0, P p1) {
  return sqrt(sqr(p0.x() - p1.x()) + sqr(p0.y() - p1.y()));
}
int main() {
  int n, k;
  VagueDouble res = 0.0;
  cin >> n >> k;
  P point[105];
  for (int i = 0; i < ((int)(n)); ++i) cin >> point[i];
  for (int i = 0; i < ((int)(n - 1)); ++i) res += dist(point[i], point[i + 1]);
  printf("%0.20lf\n", res.to_double() / 50.0);
}
