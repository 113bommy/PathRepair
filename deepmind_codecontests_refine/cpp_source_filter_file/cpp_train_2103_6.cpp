#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, k, t, x, y;
  cin >> t;
  while (t-- > 0) {
    cin >> a >> b >> c >> d >> k;
    if (a % c == 0)
      x = a / c;
    else
      x = (a / c) + 1;
    if (b % d == 0)
      y = b / d;
    else
      y = (b / d) + 1;
    if (x + y <= k)
      cout << x << " " << y << endl;
    else
      cout << -1;
  }
}
