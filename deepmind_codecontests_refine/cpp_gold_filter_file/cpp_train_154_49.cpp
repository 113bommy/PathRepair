#include <bits/stdc++.h>
double x, y, z, xy, yz, zx, x_y, y_z, z_x, y_x, z_y, x_z,
    max = -98765987654321.0, mod = 987654321.0, a[14];
int ans;
char ar[50][50] = {"",      "x^y^z",   "x^z^y",   "(x^y)^z", "(x^z)^y",
                   "y^x^z", "y^z^x",   "(y^x)^z", "(y^z)^x", "z^x^y",
                   "z^y^x", "(z^x)^y", "(z^y)^x"};
int main() {
  scanf("%lf %lf %lf", &x, &y, &z);
  if (log(x) > 0) {
    a[1] = z * log(y) + log(log(x));
    a[1] += 987654321.0;
  } else if (log(x) < 0) {
    a[1] = z * log(y) - log(-log(x));
    a[1] -= 987654321.0;
  } else
    a[1] = 0;
  a[1] = log(x) > 0   ? z * log(y) + log(log(x)) + mod
         : log(x) < 0 ? z * log(y) - log(-log(x)) - mod
                      : 0;
  a[2] = log(x) > 0   ? y * log(z) + log(log(x)) + mod
         : log(x) < 0 ? y * log(z) - log(-log(x)) - mod
                      : 0;
  a[3] = log(x) > 0   ? log(y * z) + log(log(x)) + mod
         : log(x) < 0 ? -log(y * z) - log(-log(x)) - mod
                      : 0;
  a[4] = a[3];
  a[5] = log(y) > 0   ? z * log(x) + log(log(y)) + mod
         : log(y) < 0 ? z * log(x) - log(-log(y)) - mod
                      : 0;
  a[6] = log(y) > 0   ? x * log(z) + log(log(y)) + mod
         : log(y) < 0 ? x * log(z) - log(-log(y)) - mod
                      : 0;
  a[7] = log(y) > 0   ? log(x * z) + log(log(y)) + mod
         : log(y) < 0 ? -log(x * z) - log(-log(y)) - mod
                      : 0;
  a[8] = a[7];
  a[9] = log(z) > 0   ? y * log(x) + log(log(z)) + mod
         : log(z) < 0 ? y * log(x) - log(-log(z)) - mod
                      : 0;
  a[10] = log(z) > 0   ? x * log(y) + log(log(z)) + mod
          : log(z) < 0 ? x * log(y) - log(-log(z)) - mod
                       : 0;
  a[11] = log(z) > 0   ? log(x * y) + log(log(z)) + mod
          : log(z) < 0 ? -log(x * y) - log(-log(z)) - mod
                       : 0;
  a[12] = a[11];
  for (int i = 1; i <= 12; i++) {
    if (a[i] > max) {
      max = a[i];
      ans = i;
    }
  }
  printf("%s", ar[ans]);
  return 0;
}
