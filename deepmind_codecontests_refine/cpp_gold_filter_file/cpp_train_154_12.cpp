#include <bits/stdc++.h>
int main() {
  int i;
  double x, y, z;
  double a[9];
  for (i = 0; i <= 8; i++) a[i] = -1e100;
  char count[9][10] = {"x^y^z",   "x^z^y", "(x^y)^z", "y^x^z",  "y^z^x",
                       "(y^x)^z", "z^x^y", "z^y^x",   "(z^x)^y"};
  int max;
  scanf("%lf%lf%lf", &x, &y, &z);
  if (x <= 1 && y <= 1 && z <= 1) {
    a[0] = pow(y, z) * log(x);
    a[1] = pow(z, y) * log(x);
    a[2] = y * z * log(x);
    a[3] = pow(x, z) * log(y);
    a[4] = pow(z, x) * log(y);
    a[5] = x * z * log(y);
    a[6] = pow(x, y) * log(z);
    a[7] = pow(y, x) * log(z);
    a[8] = x * y * log(z);
  } else {
    if (x > 1) {
      a[0] = z * log(y) + log(log(x));
      a[1] = y * log(z) + log(log(x));
      a[2] = log(y) + log(z) + log(log(x));
    }
    if (y > 1) {
      a[3] = z * log(x) + log(log(y));
      a[4] = x * log(z) + log(log(y));
      a[5] = log(x) + log(z) + log(log(y));
    }
    if (z > 1) {
      a[6] = y * log(x) + log(log(z));
      a[7] = x * log(y) + log(log(z));
      a[8] = log(x) + log(y) + log(log(z));
    }
  }
  for (i = 1, max = 0; i <= 8; i++) {
    if (a[i] > a[max] + 1e-6) max = i;
  }
  printf("%s\n", count[max]);
}
