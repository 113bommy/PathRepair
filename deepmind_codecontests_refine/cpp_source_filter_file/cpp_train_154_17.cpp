#include <bits/stdc++.h>
using namespace std;
double x, y, z, arr[12];
int main() {
  ios::sync_with_stdio(0);
  cin >> x >> y >> z;
  arr[1] = pow(y, z) * log(x);
  arr[2] = pow(z, y) * log(x);
  arr[3] = y * z * log(x);
  arr[4] = pow(x, z) * log(y);
  arr[5] = pow(z, x) * log(y);
  arr[6] = x * z * log(y);
  arr[7] = pow(x, y) * log(z);
  arr[8] = pow(y, x) * log(z);
  arr[9] = x * y * log(z);
  int mx = 1;
  for (int i = 2; i < 10; ++i)
    if (arr[i] > arr[mx]) mx = i;
  if (mx == 1) cout << "x^y^z";
  if (mx == 2) cout << "x^z^y";
  if (mx == 3) cout << "(x^y)^z";
  if (mx == 4) cout << "y^x^z";
  if (mx == 5) cout << "y^z^x";
  if (mx == 6) cout << "(y^x)^z";
  if (mx == 7) cout << "z^x^y";
  if (mx == 8) cout << "z^y^x";
  if (mx == 9) cout << "(z^x)^y";
  return 0;
}
