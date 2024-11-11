#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double x, y, z;
  x = sqrt(a * b / c);
  y = a / x;
  z = b / y;
  cout << 4 * (x + y + z);
  return 0;
}
