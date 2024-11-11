#include <bits/stdc++.h>
using namespace std;
long long inp;
long long i1, i2, i3, i4, i5, i6, i7, i8;
long long mov = (long long)1e9 + 7;
using Point = complex<double>;
const double kPi = 4.0 * atan(1.0);
const double kEps = 1e-9;
double dot(Point a, Point b) { return (conj(a) * b).real(); }
double cross(Point a, Point b) { return (conj(a) * b).imag(); }
double dist(Point a, Point b) { return abs(b - a); }
Point perp(Point a) { return Point{-a.imag(), a.real()}; }
template <class P>
int segmentIntersection(const P& s1, const P& e1, const P& s2, const P& e2,
                        P& r1, P& r2) {
  if (e1 == s1) {
    if (e2 == s2) {
      if (e1 == e2) {
        r1 = e1;
        return 1;
      } else
        return 0;
    } else
      return segmentIntersection(s2, e2, s1, e1, r1, r2);
  }
  P v1 = e1 - s1, v2 = e2 - s2, d = s2 - s1;
  auto a = cross(v1, v2), a1 = cross(v1, d), a2 = cross(v2, d);
  if (a == 0) {
    auto b1 = dot(s1, v1), c1 = dot(e1, v1), b2 = dot(s2, v1), c2 = dot(e2, v1);
    if (a1 || a2 || max(b1, min(b2, c2)) > min(c1, max(b2, c2))) return 0;
    r1 = min(b2, c2) < b1 ? s1 : (b2 < c2 ? s2 : e2);
    r2 = max(b2, c2) > c1 ? e1 : (b2 > c2 ? s2 : e2);
    return 2 - (r1 == r2);
  }
  if (a < 0) {
    a = -a;
    a1 = -a1;
    a2 = -a2;
  }
  if (0 < a1 || a < -a1 || 0 < a2 || a < -a2) return 0;
  r1 = s1 - v1 * a2 / a;
  return 1;
}
double eval(vector<long long> a, vector<long long> b, vector<long long> c) {
  double dotp = 0;
  for (int i = (0); i < (5); i++) {
    dotp += ((double)b.at(i) - a.at(i)) * ((double)c.at(i) - a.at(i));
  }
  double abv = 0;
  double usqt = 0;
  for (int i = (0); i < (5); i++) {
    usqt += ((double)b.at(i) - a.at(i)) * ((double)b.at(i) - a.at(i));
  }
  abv += (double)sqrt(usqt);
  usqt = 0;
  for (int i = (0); i < (5); i++) {
    usqt += ((double)c.at(i) - a.at(i)) * ((double)c.at(i) - a.at(i));
  }
  abv *= (double)sqrt(usqt);
  return (acos(dotp / abv));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  long long n;
  cin >> n;
  vector<pair<double, double>> coor;
  vector<double> angle;
  double xi, yi;
  for (int i = (0); i < (n); i++) {
    cin >> xi >> yi;
    if (xi > 0) {
      angle.push_back(180.0 / 3.1415926535897932384626 *
                      asin(yi / (double)sqrt(xi * xi + yi * yi)));
    } else {
      angle.push_back(180.0 + 180.0 / 3.1415926535897932384626 *
                                  asin(-yi / (double)sqrt(xi * xi + yi * yi)));
    }
  }
  sort(angle.begin(), angle.end());
  double r = 0;
  for (int i = (1); i < (n); i++) {
    r = max(r, angle.at(i) - angle.at(i - 1));
  }
  r = max(r, angle.at(0) - angle.at(n - 1) + 360.0);
  cout << 360.0 - r;
  return 0;
}
