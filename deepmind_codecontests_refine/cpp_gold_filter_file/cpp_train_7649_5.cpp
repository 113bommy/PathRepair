#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
const int maxn = (int)1e6;
pair<double, double> make(double a, double b) {
  return make_pair(a - b, a + b);
}
pair<double, double> segment(pair<double, double> a, pair<double, double> b) {
  double k, l, m, n;
  k = a.first * b.first;
  l = a.second * b.first;
  m = a.first * b.second;
  n = a.second * b.second;
  double h1 = min(min(k, l), min(m, n));
  double h2 = max(max(k, l), max(m, n));
  return make_pair(h1, h2);
}
bool check(pair<double, double> a, pair<double, double> b) {
  if (max(a.first, b.first) <= min(a.second, b.second)) {
    return true;
  } else {
    return false;
  }
}
int main() {
  scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
  double l = 0.0;
  double r = 1000000001.0;
  for (int i = 0; i < maxn; i++) {
    double m = (l + r) / 2;
    pair<double, double> a1, b1, c1, d1;
    a1 = make(a, m);
    b1 = make(b, m);
    c1 = make(c, m);
    d1 = make(d, m);
    pair<double, double> segm1 = segment(a1, d1);
    pair<double, double> segm2 = segment(b1, c1);
    if (check(segm1, segm2)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%.10lf", l);
  return 0;
}
