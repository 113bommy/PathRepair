#include <bits/stdc++.h>
using namespace std;
long double a[12];
char out[12][10] = {
    "x^y^z",   "x^z^y",   "(x^y)^z", "(x^z)^y", "y^x^z",   "y^z^x",
    "(y^x)^z", "(y^z)^x", "z^x^y",   "z^y^x",   "(z^x)^y", "(z^y)^x",
};
int main() {
  double x, y, z;
  while (~scanf("%lf%lf%lf", &x, &y, &z)) {
    long double logx = log(x);
    long double logy = log(y);
    long double logz = log(z);
    a[0] = logx * powl(y, z);
    a[1] = logx * powl(z, y);
    a[2] = logx * y * z;
    a[3] = -1;
    a[4] = logy * powl(x, z);
    a[5] = logy * powl(z, x);
    a[6] = logy * x * z;
    a[7] = -1;
    a[8] = logz * powl(x, y);
    a[9] = logz * powl(y, x);
    a[10] = logz * x * y;
    a[11] = -1;
    long double ans = -1;
    int index = -1;
    for (int i = 0; i < 12; i++) {
      if (a[i] > ans && a[i] - ans >= 1e-10) {
        ans = a[i];
        index = i;
      }
    }
    puts(out[index]);
  }
  return 0;
}
