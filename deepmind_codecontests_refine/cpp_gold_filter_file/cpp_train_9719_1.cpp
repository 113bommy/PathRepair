#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double x, y, z;
  y = abs(sqrt(a * b / c));
  x = a / y;
  z = b / y;
  cout << 4 * (x + y + z);
  return 0;
}
