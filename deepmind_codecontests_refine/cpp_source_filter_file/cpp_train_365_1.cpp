#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
const double EPS = 1e-12;
complex<double> pt[maxn];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long x[maxn], y[maxn];
double cross(complex<double> &a, complex<double> &b, complex<double> &c) {
  return imag(conj(b - a) * (c - a));
}
bool eq(double a, double b) { return fabs(a - b) < EPS; }
bool lt(double a, double b) { return a + EPS < b; }
int main() {
  complex<double> offset, rotation, aa, bb;
  int n, i, ans, ansa, ansb;
  long long stepx, stepy, g;
  double xa, xb, curx, step;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    pt[i] = complex<double>((double)x[i], (double)y[i]);
  }
  offset = pt[0];
  for (i = 0; i < n; i++) pt[i] -= offset;
  rotation = pt[1];
  for (i = 0; i < n; i++) pt[i] = pt[i] / rotation * abs(rotation);
  xa = 0., xb = pt[1].real();
  for (i = 2; i < n; i++) {
    if (eq(pt[i - 1].imag(), pt[i].imag())) {
      if (pt[i - 1].real() < pt[i].real()) {
        printf("0");
        return 0;
      }
      continue;
    }
    curx = cross(pt[0], pt[i - 1], pt[i]) / (pt[i].imag() - pt[i - 1].imag());
    if (lt(pt[i - 1].imag(), pt[i].imag())) {
      if (curx > xa) xa = curx;
    } else {
      if (curx < xb) xb = curx;
    }
    if (lt(xb, xa)) {
      printf("0");
      return 0;
    }
  }
  g = gcd(x[1] - x[0], y[1] - y[0]);
  stepx = (x[1] - x[0]) / g;
  stepy = (y[1] - y[0]) / g;
  step = sqrt(stepx * stepx + stepy * stepy + 0.);
  ansb = (int)((xb + EPS) / step) + 1;
  ansa = (xa - EPS < EPS ? 0 : (int)((xa - EPS) / step) + 1);
  ans = ansb - ansa;
  cout << ans;
}
