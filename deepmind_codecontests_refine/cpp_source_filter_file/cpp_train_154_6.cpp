#include <bits/stdc++.h>
int main() {
  double x, y, z;
  double max;
  int ind = 0;
  scanf("%lf %lf %lf", &x, &y, &z);
  if (x - 1.0 < 1e-6 && y - 1.0 < 1e-6 && z - 1.0 < 1e-6) {
    max = 1000000;
    if (z * log(y) + log(log(1 / x)) - max < 1e-6) {
      max = z * log(y) + log(log(1 / x));
      ind = 1;
    }
    if (y * log(z) + log(log(1 / x)) - max < 1e-6) {
      max = y * log(z) + log(log(1 / x));
      ind = 2;
    }
    if (log(y) + log(z) + log(log(1 / x)) - max < 1e-6) {
      max = log(y) + log(z) + log(log(1 / x));
      ind = 3;
    }
    if (z * log(x) + log(log(1 / y)) - max < 1e-6) {
      max = z * log(x) + log(log(1 / y));
      ind = 5;
    }
    if (x * log(z) + log(log(1 / y)) - max < 1e-6) {
      max = x * log(z) + log(log(1 / y));
      ind = 6;
    }
    if (log(x) + log(z) + log(log(1 / y)) - max < 1e-6) {
      max = log(x) + log(z) + log(log(1 / y));
      ind = 7;
    }
    if (y * log(x) + log(log(1 / z)) - max < 1e-6) {
      max = y * log(x) + log(log(1 / z));
      ind = 9;
    }
    if (x * log(y) + log(log(1 / z)) - max < 1e-6) {
      max = x * log(y) + log(log(1 / z));
      ind = 10;
    }
    if (log(x) + log(y) + log(log(1 / z)) - max < 1e-6) {
      max = log(x) + log(y) + log(log(1 / z));
      ind = 11;
    }
  } else {
    max = -1000;
    if (x - 1.0 > 0.01) {
      if (z * log(y) + log(log(x)) - max > 1e-6) {
        max = z * log(y) + log(log(x));
        ind = 1;
      }
      if (y * log(z) + log(log(x)) - max > 1e-6) {
        max = y * log(z) + log(log(x));
        ind = 2;
      }
      if (log(y) + log(z) + log(log(x)) - max > 1e-6) {
        max = log(y) + log(z) + log(log(x));
        ind = 3;
      }
    }
    if (y - 1.0 > 0.01) {
      if (z * log(x) + log(log(y)) - max > 1e-6) {
        max = z * log(x) + log(log(y));
        ind = 5;
      }
      if (x * log(z) + log(log(y)) - max > 1e-6) {
        max = x * log(z) + log(log(y));
        ind = 6;
      }
      if (log(x) + log(z) + log(log(y)) - max > 1e-6) {
        max = log(x) + log(z) + log(log(y));
        ind = 7;
      }
    }
    if (z - 1.0 > 0.01) {
      if (y * log(x) + log(log(z)) - max > 1e-6) {
        max = y * log(x) + log(log(z));
        ind = 9;
      }
      if (x * log(y) + log(log(z)) - max > 1e-6) {
        max = x * log(y) + log(log(z));
        ind = 10;
      }
      if (log(x) + log(y) + log(log(z)) - max > 1e-6) {
        max = log(x) + log(y) + log(log(z));
        ind = 11;
      }
    }
  }
  switch (ind) {
    case 1:
      printf("x^y^z\n");
      break;
    case 2:
      printf("x^z^y\n");
      break;
    case 3:
      printf("(x^y)^z\n");
      break;
    case 4:
      printf("(x^z)^y\n");
      break;
    case 5:
      printf("y^x^z\n");
      break;
    case 6:
      printf("y^z^x\n");
      break;
    case 7:
      printf("(y^x)^z\n");
      break;
    case 8:
      printf("(y^z)^x\n");
      break;
    case 9:
      printf("z^x^y\n");
      break;
    case 10:
      printf("z^y^x\n");
      break;
    case 11:
      printf("(z^x)^y\n");
      break;
    case 12:
      printf("(z^y)^x\n");
      break;
    default:
      printf("ERROR\n");
  }
  return 0;
}
