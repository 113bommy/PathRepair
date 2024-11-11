#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
double dot(complex<double> a, complex<double> b) {
  return (conj(a) * b).real();
}
double cross(complex<double> a, complex<double> b) {
  return (conj(a) * b).imag();
}
double orient(complex<double> a, complex<double> b, complex<double> c) {
  return cross(b - a, c - a);
}
double dist(complex<double> a, complex<double> b) { return abs(a - b); }
double aaaa, bbbb;
int main() {
  complex<double> s, f;
  cin >> aaaa >> bbbb;
  s = {aaaa, bbbb};
  ;
  cin >> aaaa >> bbbb;
  f = {aaaa, bbbb};
  ;
  double vmax, t;
  cin >> vmax >> t;
  complex<double> v1, v2;
  cin >> aaaa >> bbbb;
  v1 = {aaaa, bbbb};
  ;
  cin >> aaaa >> bbbb;
  v2 = {aaaa, bbbb};
  ;
  double l = 0, r = 100000;
  double m;
  while (l < r && abs(l - r) >= 1e-6) {
    m = (l + r) / 2;
    double xx = s.real() + min(m, t) * v1.real() + max(m - t, 0.0) * v2.real();
    double yy = s.imag() + min(m, t) * v1.imag() + max(m - t, 0.0) * v2.imag();
    complex<double> qq = {xx, yy};
    if (dist(qq, f) < vmax * m)
      r = m;
    else
      l = m;
  }
  cout << fixed << setprecision(20);
  cout << m << endl;
}
