#include <bits/stdc++.h>
const long long INF = 4e18L + 1;
const int IINF = 2e9 + 1;
const int limit = 1048576;
using namespace std;
const double eps = 1e-9;
const double fail = 4.4242315e-12;
const complex<double> fail2(fail, fail);
bool eq(double r1, double r2) { return fabs(r1 - r2) < eps; }
bool eq(complex<double> c1, complex<double> c2) {
  return eq(c1.real(), c2.real()) and eq(c1.imag(), c2.imag());
}
double dot(complex<double> c1, complex<double> c2) {
  return c1.real() * c2.real() + c1.imag() * c2.imag();
}
double det(complex<double> c1, complex<double> c2) {
  return c1.real() * c2.imag() - c1.imag() * c2.real();
}
struct line {
  complex<double> n;
  double c;
  line(complex<double> n1, double c1) : n{n1 / abs(n1)}, c{c1} {}
  line(complex<double> p1, complex<double> p2)
      : n{((p2 - p1) / abs(p2 - p1)) * complex<double>(0, 1)}, c{dot(p1, n)} {}
  complex<double> dir() const { return n * complex<double>(0, 1); }
  complex<double> val(double t) const { return c * n + t * dir(); }
  double intersect(const line& other) const {
    if (fabs(det(n, other.n)) < eps) {
      return fail;
    } else {
      return (other.c - c * dot(n, other.n)) / dot(dir(), other.n);
    }
  }
};
struct seg {
  line l;
  double start, end;
  seg(complex<double> p1, complex<double> p2)
      : l{p1, p2}, start{dot(l.dir(), p1)}, end{dot(l.dir(), p2)} {}
  complex<double> p1() const { return l.val(start); }
  complex<double> p2() const { return l.val(end); }
  double len() const { return fabs(end - start); }
};
double dist(const line& l, const complex<double>& p) {
  return fabs(dot(p, l.n) - l.c);
}
complex<double> intersect(const line& a, const line& b) {
  double t = a.intersect(b);
  if (eq(t, fail)) {
    return fail2;
  } else {
    return a.val(t);
  }
}
complex<double> intersect(const seg& s, const line& l) {
  double t = s.l.intersect(l);
  if (eq(t, fail) or !(eq(fabs(t - s.start) + fabs(t - s.end), s.len()))) {
    return fail2;
  } else {
    return s.l.val(t);
  }
}
int n;
vector<complex<double> > polygon;
bool check_r(double radius, complex<double>& candB, complex<double>& candL) {
  int i1 = 2, m = 0;
  vector<int> best(n);
  vector<complex<double> > cand(n);
  for (int i = int(0); i < int(n); i++) {
    cand[i] = polygon[i + 1];
  }
  for (int i = int(0); i < int(n); i++) {
    i1 = max(i1, i + 2);
    m = max(m, i);
    best[i] = i1 - i;
    line l1(polygon[i], polygon[i + 1]);
    while (i1 != i + n) {
      line l2(polygon[i1], polygon[i1 + 1]);
      if (det(polygon[i + 1] - polygon[i], polygon[i1 + 1] - polygon[i1]) <
          eps) {
        break;
      }
      complex<double> temp = intersect(l1, l2);
      complex<double> u1 = polygon[i] - polygon[i + 1],
                      u2 = polygon[i1 + 1] - polygon[i1];
      u1 /= abs(u1);
      u2 /= abs(u2);
      line bisect(temp, temp + (u1 + u2) / 2.0);
      while (eq(intersect(seg(polygon[m], polygon[m + 1]), bisect), fail2)) {
        m++;
      }
      complex<double> cross =
          intersect(seg(polygon[m], polygon[m + 1]), bisect);
      if (max(dist(l1, cross), dist(l2, cross)) < radius) {
        i1++;
        best[i] = i1 - i;
        cand[i] = cross;
      } else {
        break;
      }
    }
  }
  for (int i = int(0); i < int(n); i++) {
    if (best[i] + best[(i + best[i]) % n] >= n) {
      candB = cand[i];
      candL = cand[(i + best[i]) % n];
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = int(0); i < int(n); i++) {
    double t1, t2;
    cin >> t1 >> t2;
    polygon.push_back(complex<double>(t1, t2));
  }
  for (int i = int(n); i < int(2 * n); i++) {
    polygon.push_back(polygon[i - n]);
  }
  double start = 0.0, fin = 100000;
  complex<double> Bar, Lya;
  for (int i = int(0); i < int(102); i++) {
    double m = (start + fin) / 2.0;
    complex<double> candB, candL;
    if (check_r(m, candB, candL)) {
      fin = m;
      Bar = candB;
      Lya = candL;
    } else {
      start = m;
    }
  }
  cout << setprecision(8) << fixed << fin << "\n";
  cout << Bar.real() << " " << Bar.imag() << "\n";
  cout << Lya.real() << " " << Lya.imag() << "\n";
  return 0;
}
