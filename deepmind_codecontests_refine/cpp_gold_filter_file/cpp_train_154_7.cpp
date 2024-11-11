#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 1e5 + 10;
long double a[20];
string s[] = {"x^y^z",   "x^z^y",   "(x^y)^z", "(x^z)^y", "y^x^z",   "y^z^x",
              "(y^x)^z", "(y^z)^x", "z^x^y",   "z^y^x",   "(z^x)^y", "(z^y)^x"};
int main() {
  long double x, y, z;
  while (cin >> x >> y >> z) {
    a[0] = pow(y, z) * log(x);
    a[1] = pow(z, y) * log(x);
    a[2] = z * log(pow(x, y));
    a[3] = y * log(pow(x, z));
    a[4] = pow(x, z) * log(y);
    a[5] = pow(z, x) * log(y);
    a[6] = z * log(pow(y, x));
    a[7] = x * log(pow(y, z));
    a[8] = pow(x, y) * log(z);
    a[9] = pow(y, x) * log(z);
    a[10] = y * log(pow(z, x));
    a[11] = x * log(pow(z, y));
    int index = 0;
    for (int i = 1; i < 12; ++i) {
      if (a[i] > a[index] + eps) {
        index = i;
      }
    }
    cout << s[index] << endl;
  }
  return 0;
}
