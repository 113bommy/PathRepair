#include <bits/stdc++.h>
using namespace std;
const char ans[15][10] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
                          "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
                          "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
double cal(double x, double y, double z, int k) {
  switch (k) {
    case 0:
      return z * log(y) + log(log(x));
    case 1:
      return y * log(z) + log(log(x));
    case 2:
    case 3:
      return log(y) + log(z) + log(log(x));
    case 4:
      return z * log(x) + log(log(y));
    case 5:
      return x * log(z) + log(log(y));
    case 6:
    case 7:
      return log(x) + log(z) + log(log(y));
    case 8:
      return y * log(x) + log(log(z));
    case 9:
      return x * log(y) + log(log(z));
    case 10:
    case 11:
      return log(x) + log(y) + log(log(z));
  }
}
int main() {
  double a[5];
  scanf("%lf%lf%lf", &a[0], &a[1], &a[2]);
  if (a[0] > 1.0 || a[1] > 1.0 || a[2] > 1.0) {
    int m = -1;
    double k = -1.0;
    for (int i = (0); i <= (2); i++) {
      if (a[i] < 1.0) continue;
      for (int j = (0); j <= (3); j++) {
        double tmp = cal(a[0], a[1], a[2], i * 4 + j);
        if (m == -1 || tmp - k > 1e8) {
          m = i * 4 + j;
          k = tmp;
        }
      }
    }
    printf("%s", ans[m]);
  } else {
    int m = -1;
    double k = 1.0;
    for (int i = (0); i <= (2); i++) {
      double t = a[i];
      a[i] = 1 / a[i];
      for (int j = (0); j <= (3); j++) {
        double tmp = cal(a[0], a[1], a[2], i * 4 + j);
        if (m == -1 || k - tmp > 1e8) {
          m = i * 4 + j;
          k = tmp;
        }
      }
      a[i] = t;
    }
    printf("%s", ans[m]);
  }
  return 0;
}
