#include <bits/stdc++.h>
using namespace std;
double x, y, z, ans = -1;
int num;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> x >> y >> z;
  if (ans < pow(y, z) * log(x)) ans = pow(y, z) * log(x), num = 1;
  if (ans < pow(z, y) * log(x)) ans = pow(z, y) * log(x), num = 2;
  if (ans < y * z * log(x)) ans = y * z * log(x), num = 3;
  if (ans < pow(x, z) * log(y)) ans = pow(x, z) * log(y), num = 4;
  if (ans < pow(z, x) * log(y)) ans = pow(z, x) * log(y), num = 5;
  if (ans < x * z * log(y)) ans = x * z * log(y), num = 6;
  if (ans < pow(x, y) * log(z)) ans = pow(x, y) * log(z), num = 7;
  if (ans < pow(y, x) * log(z)) ans = pow(y, x) * log(z), num = 8;
  if (ans < x * y * log(z)) ans = x * y * log(z), num = 9;
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
      cout << "y^x^z";
      break;
    case 5:
      cout << "y^z^x";
      break;
    case 6:
      cout << "(y^x)^z";
      break;
    case 7:
      cout << "z^x^y";
      break;
    case 8:
      cout << "z^y^x";
      break;
    case 9:
      cout << "(z^x)^y";
      break;
  }
  cout << '\n';
  return 0;
}
