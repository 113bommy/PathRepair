#include <bits/stdc++.h>
using namespace std;
string str[10] = {"",      "x^y^z",   "x^z^y", "(x^y)^z", "y^x^z",
                  "y^z^x", "(y^x)^z", "z^x^y", "z^y^x",   "(z^x)^y"};
long double a[11];
long double mx, x, y, z;
int m;
int main() {
  if (0) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  cin >> x >> y >> z;
  a[1] = log(x) * pow(y, z);
  a[2] = log(x) * pow(z, y);
  a[3] = y * z * log(x);
  a[4] = log(y) * pow(x, z);
  a[5] = log(y) * pow(z, x);
  a[6] = x * z * log(y);
  a[7] = log(z) * pow(x, y);
  a[8] = log(z) * pow(y, x);
  a[9] = x * y * log(z);
  mx = a[1];
  m = 1;
  for (int i = 1; i <= 9; i++) {
    if (a[i] > mx) {
      mx = a[i];
      m = i;
    }
  }
  cout << str[m] << endl;
  return 0;
}
