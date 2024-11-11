#include <bits/stdc++.h>
using namespace std;
int main() {
  double x, y, z;
  scanf("%lf%lf%lf", &x, &y, &z);
  double m = -1000000.0;
  int ad = 2;
  for (int i = 0; i < 12; i++) {
    double cmp;
    if (x >= 1 || y >= 1 || z >= 1) switch (i) {
        case 0:
          cmp = z * log(y) + log(log(x));
          break;
        case 1:
          cmp = y * log(z) + log(log(x));
          break;
        case 2:
          cmp = log(y * z) + log(log(x));
          break;
        case 3:
          cmp = log(y * z) + log(log(x));
          break;
        case 4:
          cmp = z * log(x) + log(log(y));
          break;
        case 5:
          cmp = x * log(z) + log(log(y));
          break;
        case 6:
          cmp = log(x * z) + log(log(y));
          break;
        case 7:
          cmp = log(x * z) + log(log(y));
          break;
        case 8:
          cmp = y * log(x) + log(log(z));
          break;
        case 9:
          cmp = x * log(y) + log(log(z));
          break;
        case 10:
          cmp = log(x * y) + log(log(z));
          break;
        case 11:
          cmp = log(x * y) + log(log(z));
          break;
      }
    else
      switch (i) {
        case 0:
          cmp = pow(x, pow(y, z));
          break;
        case 1:
          cmp = pow(x, pow(z, y));
          break;
        case 2:
          cmp = pow(pow(x, y), z);
          break;
        case 3:
          cmp = pow(pow(x, z), y);
          break;
        case 4:
          cmp = pow(y, pow(x, z));
          break;
        case 5:
          cmp = pow(y, pow(z, x));
          break;
        case 6:
          cmp = pow(y, x * z);
          break;
        case 7:
          cmp = pow(y, x * z);
          break;
        case 8:
          cmp = pow(z, pow(x, y));
          break;
        case 9:
          cmp = pow(z, pow(y, x));
          break;
        case 10:
        case 11:
          cmp = pow(z, x * y);
          break;
      }
    if (cmp - m > 1e-12) {
      ad = i;
      m = cmp;
    }
  }
  switch (ad) {
    case 0:
      cout << "x^y^z";
      break;
    case 1:
      cout << "x^z^y";
      break;
    case 2:
      cout << "(x^y)^z";
      break;
    case 3:
      cout << "(x^z)^y";
      break;
    case 4:
      cout << "y^x^z";
      break;
    case 5:
      cout << "y^z^x";
      break;
    case 6:
      cout << "(y^x)^z";
      break;
    case 7:
      cout << "(y^z)^x";
      break;
    case 8:
      cout << "z^x^y";
      break;
    case 9:
      cout << "z^y^x";
      break;
    case 10:
      cout << "(z^x)^y";
      break;
    case 11:
      cout << "(z^y)^x";
      break;
  }
}
