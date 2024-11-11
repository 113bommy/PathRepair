#include <bits/stdc++.h>
using namespace std;
bool flag;
const double eps = 1e-12;
double sqr(double x) { return x * x; }
void read(complex<double> &A) {
  double x, y;
  cin >> x >> y;
  A = complex<double>(x, y);
}
bool tri(complex<double> A, double ra, complex<double> B, double rb) {
  double a[] = {abs(A - B), ra, rb};
  sort(a, a + 3);
  return (a[0] + a[1] + eps > a[2]);
}
bool ok(complex<double> A, double ra, complex<double> B, double rb,
        complex<double> C, double rc) {
  if (abs(A - C) < ra + eps && abs(B - C) < rb + eps) return true;
  if (!tri(A, ra, B, rb)) return false;
  double d = abs(A - B);
  double t = (sqr(ra) + sqr(d) - sqr(rb)) / 2.0 / sqr(d);
  double h = sqrt(max(sqr(ra) - sqr(t * d), 0.0));
  double mx = A.real() + t * (B.real() - A.real()),
         my = A.imag() + t * (B.imag() - A.imag());
  double dx, dy;
  if (abs(A.imag() - my) < eps) {
    dy = h * (A.real() - my) / sqrt(sqr(A.real() - mx) + sqr(A.imag() - my)),
    dx = dy * (my - A.imag()) / (A.real() - mx);
  } else {
    dx = h * (A.imag() - my) / sqrt(sqr(A.real() - mx) + sqr(A.imag() - my)),
    dy = dx * (mx - A.real()) / (A.imag() - my);
  }
  complex<double> tmp;
  tmp = complex<double>(mx + dx, my + dy);
  if (abs(tmp - C) < rc + eps) return true;
  tmp = complex<double>(mx - dx, my - dy);
  if (abs(tmp - C) < rc + eps) return true;
  return false;
}
bool check(complex<double> A, double ra, complex<double> B, double rb,
           complex<double> C, double rc) {
  if (ok(A, ra, B, rb, C, rc)) return true;
  if (ok(A, ra, C, rc, B, rb)) return true;
  if (ok(B, rb, C, rc, A, ra)) return true;
  return false;
}
int main() {
  double t1, t2;
  complex<double> A, B, C;
  cin >> t1 >> t2;
  read(A);
  read(B);
  read(C);
  if (abs(A - C) + abs(B - C) < abs(A - B) + t2 + eps) {
    double ans = min(abs(A - C) + abs(B - C) + t1, abs(A - B) + t2);
    printf("%.9lf", ans);
    return 0;
  }
  double low = 0, high = min(abs(A - C) + t1, abs(A - B) + t2), mid;
  int k = 100;
  while (k--) {
    mid = (low + high) / 2.0;
    if (check(A, mid, B, abs(A - B) + t2 - mid, C, abs(A - C) + t1 - mid))
      low = mid;
    else
      high = mid;
  }
  printf("%.9lf", mid);
}
