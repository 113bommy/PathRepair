#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, i, c, d, k, x, y;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a >> b >> c >> d >> k;
    if (a % c == 0) {
      x = a / c;
    } else {
      x = a / c + 1;
    }
    if (b % d == 0) {
      y = b / d;
    } else {
      y = b / d + 1;
    }
    if (x + y > k) {
      cout << "-1" << endl;
    } else {
      cout << x << " " << k - x << endl;
    }
  }
}
