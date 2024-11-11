#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, k, n, x, y, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b >> c >> d >> k;
    if (a <= c) {
      x = 1;
    } else {
      if (a % c == 0) {
        x = a / c;
      } else {
        x = (a / c) + 1;
      }
    }
    if (b < d) {
      y = 1;
    } else {
      if (b % d == 0) {
        y = b / d;
      } else {
        y = (b / d) + 1;
      }
    }
    if ((x + y) > k) {
      cout << -1 << endl;
    } else {
      x = k - y;
      cout << x << " " << y << endl;
    }
  }
}
