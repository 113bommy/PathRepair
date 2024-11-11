#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
const double EPS = 1e-10;
const double PI = acos(-1.0);
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  double x, y, z;
  cin >> x >> y >> z;
  vector<double> a(12, -10000000000);
  auto f1 = [](double a, double b, double c) { return pow(a, pow(b, c)); };
  auto f2 = [](double a, double b, double c) { return pow(pow(a, b), c); };
  auto f3 = [](double a, double b, double c) {
    return c * log(b) + log(log(a));
  };
  auto f4 = [](double a, double b, double c) {
    return log(c) + log(b) + log(log(a));
  };
  if (x <= 1 && y <= 1 && z <= 1) {
    a[0] = f1(x, y, z);
    a[1] = f1(x, z, y);
    a[2] = f2(x, y, z);
    a[3] = f2(x, z, y);
    a[4] = f1(y, x, z);
    a[5] = f1(y, z, x);
    a[6] = f2(y, x, z);
    a[7] = f2(y, z, x);
    a[8] = f1(z, x, y);
    a[9] = f1(z, y, x);
    a[10] = f2(z, x, y);
    a[11] = f2(z, y, x);
  } else {
    if (x > 1) {
      a[0] = f3(x, y, z);
      a[1] = f3(x, z, y);
      a[2] = f4(x, y, z);
      a[3] = f4(x, z, y);
    }
    if (y > 1) {
      a[4] = f3(y, x, z);
      a[5] = f3(y, z, x);
      a[6] = f4(y, x, z);
      a[7] = f4(y, z, x);
    }
    if (z > 1) {
      a[8] = f3(z, x, y);
      a[9] = f3(z, y, x);
      a[10] = f4(z, x, y);
      a[11] = f4(z, y, x);
    }
  }
  double tmp = a[0];
  int ret = 0;
  for (int i = (0); i < (12); ++i) {
    if (tmp < a[i]) {
      tmp = a[i];
      ret = i;
    }
  }
  string S[12] = {
      "x^y^z",   "x^z^y",   "(x^y)^z", "(x^z)^y", "y^x^z",   "y^z^x",
      "(y^x)^z", "(y^z)^x", "z^x^y",   "z^y^x",   "(z^x)^y", "(z^y)^x",
  };
  cout << S[ret] << endl;
  return 0;
}
