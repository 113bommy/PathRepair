#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int DIM = 2;
double T1, T2;
complex<double> cinema, shop, home;
inline double dist(const complex<double>& a, const complex<double>& b) {
  return abs(a - b);
}
void readPoint(complex<double>& p) {
  double x, y;
  cin >> x >> y;
  p = complex<double>(x, y);
}
inline bool isIn(const pair<complex<double>, double>& a,
                 const pair<complex<double>, double>& b) {
  double A = dist(a.first, b.first) + a.second;
  double B = b.second;
  return A < B + eps;
}
inline bool isInPoint(const complex<double>& p,
                      const pair<complex<double>, double>& c) {
  return dist(p, c.first) < c.second + eps;
}
inline bool doesIntersect(const pair<complex<double>, double>& a,
                          const pair<complex<double>, double>& b) {
  return dist(a.first, b.first) < a.second + b.second + eps;
}
complex<double> getNewCoords(complex<double> e1prime, complex<double> e2prime,
                             complex<double> P, complex<double> A) {
  double c1 = A.real() - P.real();
  double c2 = A.imag() - P.imag();
  double x = c1 * e1prime.real() + c2 * e2prime.real();
  double y = c1 * e1prime.imag() + c2 * e2prime.imag();
  return complex<double>(x, y);
}
complex<double> getOldCoors(complex<double> e1prime, complex<double> e2prime,
                            complex<double> P, complex<double> A) {
  double a1 = A.real();
  double a2 = A.imag();
  double x = a1 * e1prime.real() + a2 * e1prime.imag();
  double y = a1 * e2prime.real() + a2 * e2prime.imag();
  x += P.real();
  y += P.imag();
  return complex<double>(x, y);
}
vector<complex<double> > getIntersectedPoints(
    const pair<complex<double>, double>& C1,
    const pair<complex<double>, double>& C2) {
  complex<double> P = C1.first;
  complex<double> e1prime = C2.first - C1.first;
  e1prime = e1prime / abs(e1prime);
  complex<double> e2prime = complex<double>(e1prime.imag(), -e1prime.real());
  complex<double> A = getNewCoords(e1prime, e2prime, P, C1.first);
  complex<double> B = getNewCoords(e1prime, e2prime, P, C2.first);
  double R1 = C1.second * C1.second;
  double R2 = C2.second * C2.second;
  double b = B.real();
  double x = (b * b + R1 - R2) / (2.0 * b);
  double Y = R1 - x * x;
  if (Y < 0.0) Y = 0.0;
  vector<complex<double> > ret;
  if (Y < eps) {
    ret.push_back(complex<double>(x, Y));
  } else {
    ret.push_back(complex<double>(x, sqrt(Y)));
    ret.push_back(complex<double>(x, -sqrt(Y)));
  }
  for (int i = 0; i < int(ret.size()); ++i) {
    ret[i] = getOldCoors(e1prime, e2prime, P, ret[i]);
  }
  return ret;
}
bool my_comp(const pair<complex<double>, double>& c1,
             const pair<complex<double>, double>& c2) {
  if (c1.first.real() < c2.first.real()) return true;
  if (c1.first.real() > c2.first.real()) return false;
  if (c1.first.imag() < c2.first.imag()) return true;
  if (c1.first.imag() > c2.first.imag()) return false;
  if (c1.second < c2.second) return true;
  return false;
}
bool intersect3Circles(vector<pair<complex<double>, double> >& circles) {
  sort(circles.begin(), circles.end(), my_comp);
  do {
    if (!doesIntersect(circles[0], circles[1])) {
      return false;
    }
    if (isIn(circles[0], circles[1])) {
      if (doesIntersect(circles[0], circles[2])) {
        return true;
      } else {
        return false;
      }
    }
  } while (next_permutation(circles.begin(), circles.end(), my_comp));
  sort(circles.begin(), circles.end(), my_comp);
  do {
    vector<complex<double> > pts = getIntersectedPoints(circles[0], circles[1]);
    bool ok = false;
    for (int i = 0; i < int(pts.size()); ++i) {
      if (isInPoint(pts[i], circles[2])) {
        ok = true;
        break;
      }
    }
    if (ok) return true;
  } while (next_permutation(circles.begin(), circles.end(), my_comp));
  return false;
}
bool check(double Q) {
  vector<pair<complex<double>, double> > circles(3);
  circles[0] = pair<complex<double>, double>(cinema, Q);
  circles[1] =
      pair<complex<double>, double>(shop, max(0.0, T1 - dist(shop, home) - Q));
  circles[2] = pair<complex<double>, double>(home, max(0.0, T2 - Q));
  return intersect3Circles(circles);
}
int main() {
  cout.setf(ios::fixed);
  cout.precision(9);
  double t1, t2;
  cin >> t1 >> t2;
  readPoint(cinema);
  readPoint(home);
  readPoint(shop);
  T2 = t2 + dist(cinema, home);
  T1 = t1 + dist(cinema, shop) + dist(shop, home);
  if (dist(cinema, shop) + dist(shop, home) < T2 + eps) {
    cout << min(T1, T2) << endl;
    return 0;
  }
  double L = 0.0;
  double R = min(T1, T2);
  check(1.000253);
  for (int step = 1; step <= 40; ++step) {
    double Q = (L + R) / 2.0;
    if (check(Q)) {
      L = Q;
    } else {
      R = Q;
    }
  }
  cout << (L + R) / 2.0 << endl;
  return 0;
}
