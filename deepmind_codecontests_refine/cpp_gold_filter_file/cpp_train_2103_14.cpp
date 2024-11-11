#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, k, i, x, n, y;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b >> c >> d >> k;
    if (a % c > 0)
      x = (a / c) + 1;
    else
      x = (a / c);
    if (b % d > 0)
      y = (b / d + 1);
    else
      y = (b / d);
    if (x + y <= k)
      cout << x << " " << y << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
