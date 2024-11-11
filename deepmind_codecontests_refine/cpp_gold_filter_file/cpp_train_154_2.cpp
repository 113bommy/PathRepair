#include <bits/stdc++.h>
using namespace std;
void print(int num) {
  switch (num) {
    case 1:
      cout << "x^y^z";
      break;
    case 2:
      cout << "x^z^y";
      break;
    case 3:
      cout << "(x^y)^z";
      break;
    case 4:
      cout << "(x^z)^y";
      break;
    case 5:
      cout << "y^x^z";
      break;
    case 6:
      cout << "y^z^x";
      break;
    case 7:
      cout << "(y^x)^z";
      break;
    case 8:
      cout << "(y^z)^x";
      break;
    case 9:
      cout << "z^x^y";
      break;
    case 10:
      cout << "z^y^x";
      break;
    case 11:
      cout << "(z^x)^y";
      break;
    case 12:
      cout << "(z^y)^x";
      break;
  }
}
int main() {
  double x, y, z;
  cin >> x >> y >> z;
  int ans = 0;
  double can = -1 * (1e12);
  double tmp;
  if (x > 1) {
    tmp = z * log(y) + log(log(x));
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 1;
    }
    tmp = y * log(z) + log(log(x));
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 2;
    }
    tmp = log((y * z)) + log(log(x));
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 3;
    }
  }
  if (y > 1) {
    tmp = z * log(x) + log(log(y));
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 5;
    }
    tmp = x * log(z) + log(log(y));
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 6;
    }
    tmp = log((x * z)) + log(log(y));
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 7;
    }
  }
  if (z > 1) {
    tmp = y * log(x) + log(log(z));
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 9;
    }
    tmp = x * log(y) + log(log(z));
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 10;
    }
    tmp = log(y * x) + log(log(z));
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 11;
    }
  }
  if (x <= 1 && y <= 1 && z <= 1) {
    tmp = pow(y, z) * log(x);
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 1;
    }
    tmp = pow(z, y) * log(x);
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 2;
    }
    tmp = (y * z) * log(x);
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 3;
    }
    tmp = pow(x, z) * log(y);
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 5;
    }
    tmp = pow(z, x) * log(y);
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 6;
    }
    tmp = (x * z) * log(y);
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 7;
    }
    tmp = pow(x, y) * log(z);
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 9;
    }
    tmp = pow(y, x) * log(z);
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 10;
    }
    tmp = (y * x) * log(z);
    if (tmp - can > 1e-12) {
      can = tmp;
      ans = 11;
    }
  }
  print(ans);
  return 0;
}
