#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
const double pi = acos(-1.0);
const double eps = 1e-7;
template <class TT>
TT sqr(TT a) {
  return a * a;
}
template <class TT>
TT abs(TT a) {
  if (a < 0) return -a;
  return a;
}
template <class ZZ>
ZZ max(ZZ a, ZZ b, ZZ c) {
  return max(a, max(b, c));
}
template <class ZZ>
ZZ min(ZZ a, ZZ b, ZZ c) {
  return min(a, min(b, c));
}
double S;
int a, b, c;
double first, second, Z;
double gz(double x, double y, double z) {
  Z = z;
  double re = 0;
  if (a) re += log(x) * a;
  if (b) re += log(y) * b;
  if (c) re += log(z) * c;
  return re;
}
double gy(double x) {
  int i = 800;
  double l, h, pa, pb, va, vb;
  l = 0;
  h = S - x;
  while (i--) {
    pa = (h + 2 * l) / 3.0;
    pb = (2 * h + l) / 3.0;
    va = gz(x, pa, S - pa - x);
    vb = gz(x, pb, S - pb - x);
    if (va > vb)
      h = pb;
    else
      l = pa;
  }
  second = (l + h) / 2;
  return gz(x, second, S - x - second);
}
void go() {
  int i = 800;
  double l, h, pa, pb, va, vb;
  l = 0;
  h = S;
  while (i--) {
    pa = (h + 2 * l) / 3.0;
    pb = (2 * h + l) / 3.0;
    va = gy(pa);
    vb = gy(pb);
    if (va > vb)
      h = pb;
    else
      l = pa;
  }
  first = (l + h) / 2;
}
int main() {
  int i, j, k, l, tks, ks = 1, n, m;
  while (cin >> S >> a >> b >> c) {
    go();
    printf("%.10lf %.10lf %.10lf\n", first, second, Z);
  }
  return 0;
}
