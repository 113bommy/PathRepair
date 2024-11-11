#include <bits/stdc++.h>
using namespace std;
const long double pi = 2 * acos(0.0);
double a, b, l, d;
double R(double x) {
  double y, s;
  y = sqrt(l * l - x * x);
  s = (0 * (a - 0) + b * (0 - y) + x * (y - a)) / 2.0;
  if (s < 0) s = -s;
  return 2 * s / l;
}
double MAX(double l, double r) {
  int i;
  for (i = 0; i <= 100; i++) {
    double k1, k2, d, F1, F2;
    d = (r - l) / 3;
    k1 = l + d;
    k2 = r - d;
    F1 = R(k1);
    F2 = R(k2);
    if (F1 > F2)
      l = k1;
    else
      r = k2;
  }
  return R(l);
}
int main() {
  cin >> a >> b >> l;
  if (a > b) swap(a, b);
  if (l <= a && l <= b) {
    cout << l << endl;
    return 0;
  }
  if (l >= a && l <= b) {
    cout << a << endl;
    return 0;
  }
  double uns = MAX(0, l);
  if (uns > l) uns = l;
  if (uns > a) uns = a;
  if (uns > b) uns = b;
  if (uns < (1e-7)) {
    cout << "My poor head =(" << endl;
    return 0;
  }
  printf("%.8llf\n", uns);
}
