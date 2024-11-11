#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long double x, y, z;
  cin >> x >> y >> z;
  const long double eps = (long double)1e-12;
  auto check = [&](long double x, long double y) {
    return abs(x - y) < eps || abs(x - y) < eps * abs(x);
  };
  long double logx = log(x);
  long double logy = log(y);
  long double logz = log(z);
  vector<long double> a(11);
  a[0] = logx * pow(y, z);
  a[1] = logx * pow(z, y);
  a[2] = logx * y * z;
  a[3] = a[2];
  a[4] = logy * pow(x, z);
  a[5] = logy * pow(z, x);
  a[6] = logy * x * z;
  a[7] = a[6];
  a[8] = logz * pow(x, y);
  a[9] = logz * pow(y, x);
  a[10] = logz * x * y;
  long double tmp = -1;
  int pos = -1;
  for (int i = 0; i < 11; i++) {
    if (!check(a[i], tmp) && a[i] > tmp) {
      tmp = a[i];
      pos = i;
    }
  }
  if (pos == 0) {
    cout << "x^y^z" << '\n';
  } else if (pos == 1) {
    cout << "x^z^y" << '\n';
  } else if (pos == 2) {
    cout << "(x^y)^z" << '\n';
  } else if (pos == 4) {
    cout << "y^x^z" << '\n';
  } else if (pos == 5) {
    cout << "y^z^x" << '\n';
  } else if (pos == 6) {
    cout << "(y^x)^z" << '\n';
  } else if (pos == 8) {
    cout << "z^x^y" << '\n';
  } else if (pos == 9) {
    cout << "z^y^x" << '\n';
  } else {
    cout << "(z^x)^y" << '\n';
  }
  return 0;
}
