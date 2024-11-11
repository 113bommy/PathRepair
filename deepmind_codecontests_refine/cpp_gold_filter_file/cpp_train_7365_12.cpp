#include <bits/stdc++.h>
using namespace std;
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
double a, b, l;
double f(double x1) {
  double y2 = sqrt(((l) * (l)) - ((x1) * (x1)));
  return fabs(-b * y2 - a * x1 + x1 * y2) / l;
}
double TernarySearch(double L, double R) {
  double lt, rt;
  for (int i = 0; i < 100; i++) {
    lt = (2 * L + R) / 3;
    rt = (L + 2 * R) / 3;
    if (f(lt) < f(rt))
      R = rt;
    else
      L = lt;
  }
  return f((L + R) / 2.0);
}
double FindAns() {
  if (b >= l) return min(l, a);
  if (a >= l) return min(l, b);
  return TernarySearch(0, l);
}
int main() {
  int i, j, k, tks, ks = 1, n, m;
  while (cin >> a >> b >> l) {
    if ((a = FindAns()) > 1e-7)
      printf("%.8lf\n", a);
    else
      printf("My poor head =(\n");
  }
  return 0;
}
