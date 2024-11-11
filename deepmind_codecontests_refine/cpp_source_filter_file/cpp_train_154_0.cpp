#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
long double x, y, z;
string expre[13] = {"",      "x^y^z",   "x^z^y",   "(x^y)^z", "(x^z)^y",
                    "y^x^z", "y^z^x",   "(y^x)^z", "(y^z)^x", "z^x^y",
                    "z^y^x", "(z^x)^y", "(z^y)^x"};
long double val[13];
long double calc1(long double x, long double y, long double z) {
  return pow(y, z) * log(x);
}
long double calc2(long double x, long double y, long double z) {
  return y * z * log(x);
}
int findMax() {
  long double Max = val[1];
  int pos = 1;
  for (int i = 2; i <= 12; ++i) {
    if ((val[i] - Max) > eps) {
      Max = val[i];
      pos = i;
    }
  }
  return pos;
}
int main() {
  while (cin >> x >> y >> z) {
    val[1] = calc1(x, y, z);
    val[2] = calc1(z, z, y);
    val[3] = calc2(x, y, z);
    val[4] = calc2(x, z, y);
    val[5] = calc1(y, x, z);
    val[6] = calc1(y, z, x);
    val[7] = calc2(y, x, z);
    val[8] = calc2(y, z, x);
    val[9] = calc1(z, x, y);
    val[10] = calc1(z, y, x);
    val[11] = calc2(z, x, y);
    val[12] = calc2(z, y, x);
    cout << expre[findMax()] << endl;
  }
}
