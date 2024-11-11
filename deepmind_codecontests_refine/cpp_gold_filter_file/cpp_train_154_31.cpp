#include <bits/stdc++.h>
int c = 1;
double x, y, z, a[20];
char b[20][20];
double lg(double x) {
  if (x < 0)
    return -2e9;
  else
    return log(x);
}
int main() {
  scanf("%lf %lf %lf", &x, &y, &z);
  strcpy(b[1], "x^y^z");
  strcpy(b[2], "x^z^y");
  strcpy(b[3], "(x^y)^z");
  strcpy(b[4], "(x^z)^y");
  strcpy(b[5], "y^x^z");
  strcpy(b[6], "y^z^x");
  strcpy(b[7], "(y^x)^z");
  strcpy(b[8], "(y^z)^x");
  strcpy(b[9], "z^x^y");
  strcpy(b[10], "z^y^x");
  strcpy(b[11], "(z^x)^y");
  strcpy(b[12], "(z^y)^x");
  if (x <= 1 && y <= 1 && z <= 1) {
    a[1] = pow(x, pow(y, z));
    a[2] = pow(x, pow(z, y));
    a[3] = pow(x, y * z);
    a[4] = pow(x, z * y);
    a[5] = pow(y, pow(x, z));
    a[6] = pow(y, pow(z, x));
    a[7] = pow(y, x * z);
    a[8] = pow(y, z * x);
    a[9] = pow(z, pow(x, y));
    a[10] = pow(z, pow(y, x));
    a[11] = pow(z, x * y);
    a[12] = pow(z, y * x);
  } else {
    a[1] = z * lg(y) + lg(lg(x));
    a[2] = y * lg(z) + lg(lg(x));
    a[3] = lg(y * z) + lg(lg(x));
    a[4] = lg(z * y) + lg(lg(x));
    a[5] = z * lg(x) + lg(lg(y));
    a[6] = x * lg(z) + lg(lg(y));
    a[7] = lg(x * z) + lg(lg(y));
    a[8] = lg(z * x) + lg(lg(y));
    a[9] = y * lg(x) + lg(lg(z));
    a[10] = x * lg(y) + lg(lg(z));
    a[11] = lg(x * y) + lg(lg(z));
    a[12] = lg(y * x) + lg(lg(z));
  }
  for (int i = 2; i <= 12; i++)
    if (a[i] > a[c]) c = i;
  printf("%s\n", b[c]);
  scanf("\n");
  return 0;
}
