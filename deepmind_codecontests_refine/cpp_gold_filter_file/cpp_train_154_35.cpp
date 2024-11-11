#include <bits/stdc++.h>
const double pi = (double)(2.0 * acos(0.0));
const int inf = 1 << 30;
const double eps = 1E-9;
const double e = exp(1.0);
const int sz = 100000 + 5;
const int mod = 1000000000 + 7;
using namespace std;
int main() {
  double x, y, z, res, v;
  string st = "";
  scanf("%lf %lf %lf", &x, &y, &z);
  if (x < 1.0 + eps && y < 1.0 + eps && z < 1.0 + eps) {
    res = 1e18;
    v = z * log(y) + log(log(1.0 / x));
    if (res > v + eps) res = v, st = "x^y^z";
    v = y * log(z) + log(log(1.0 / x));
    if (res > v + eps) res = v, st = "x^z^y";
    v = log(y) + log(z) + log(log(1.0 / x));
    if (res > v + eps) res = v, st = "(x^y)^z";
    v = z * log(x) + log(log(1.0 / y));
    if (res > v + eps) res = v, st = "y^x^z";
    v = x * log(z) + log(log(1.0 / y));
    if (res > v + eps) res = v, st = "y^z^x";
    v = log(x) + log(z) + log(log(1.0 / y));
    if (res > v + eps) res = v, st = "(y^x)^z";
    v = y * log(x) + log(log(1.0 / z));
    if (res > v + eps) res = v, st = "z^x^y";
    v = x * log(y) + log(log(1.0 / z));
    if (res > v + eps) res = v, st = "z^y^x";
    v = log(x) + log(y) + log(log(1.0 / z));
    if (res > v + eps) res = v, st = "(z^x)^y";
    cout << st << endl;
  } else {
    res = -1e18;
    if (x > 1.0 + eps) {
      v = z * log(y) + log(log(x));
      if (res + eps < v) res = v, st = "x^y^z";
      v = y * log(z) + log(log(x));
      if (res + eps < v) res = v, st = "x^z^y";
      v = log(y) + log(z) + log(log(x));
      if (res + eps < v) res = v, st = "(x^y)^z";
    }
    if (y > 1.0 + eps) {
      v = z * log(x) + log(log(y));
      if (res + eps < v) res = v, st = "y^x^z";
      v = x * log(z) + log(log(y));
      if (res + eps < v) res = v, st = "y^z^x";
      v = log(x) + log(z) + log(log(y));
      if (res + eps < v) res = v, st = "(y^x)^z";
    }
    if (z > 1.0 + eps) {
      v = y * log(x) + log(log(z));
      if (res + eps < v) res = v, st = "z^x^y";
      v = x * log(y) + log(log(z));
      if (res + eps < v) res = v, st = "z^y^x";
      v = log(x) + log(y) + log(log(z));
      if (res + eps < v) res = v, st = "(z^x)^y";
    }
    cout << st << endl;
  }
  return 0;
}
