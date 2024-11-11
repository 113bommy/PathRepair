#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, x, y;
  cin >> a >> b >> c >> d >> x >> y;
  a = abs(a - c);
  b = abs(b - d);
  if (!(a % x) && !(b % y) && ((a * y) % 2) == ((b * x) % 2))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
