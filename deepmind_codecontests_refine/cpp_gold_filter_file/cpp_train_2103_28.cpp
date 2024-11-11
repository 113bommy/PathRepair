#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x, y;
    x = a / c;
    y = b / d;
    if (a % c != 0) {
      x++;
    }
    if (b % d != 0) {
      y++;
    }
    if (x + y <= k) {
      cout << x << " " << y << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
