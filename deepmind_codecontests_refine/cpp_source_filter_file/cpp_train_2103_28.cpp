#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x, y;
    if (a % c != 0 && b % d != 0) {
      x = (a / c) + 1;
      y = (b / d) + 1;
    }
    if (a % c == 0 && b % d == 0) {
      x = (a / c);
      y = (b / d);
    }
    if (a % c != 0 && b % d == 0) {
      x = (a / c) + 1;
      y = (b / d);
    }
    if (a % c == 0 && b / d != 0) {
      x = a / c;
      y = (b / d) + 1;
    }
    if (x + y <= k) {
      cout << x << " " << y << "\n";
    }
    if (x + y > k) {
      cout << -1 << "\n";
    }
  }
}
