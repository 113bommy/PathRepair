#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  int t;
  int m, w, d;
  cin >> t;
  while (t--) {
    cin >> m >> d >> w;
    if (d == 1)
      cout << m - 1 << endl;
    else {
      int g = gcd(w, d - 1);
      int limit = min(m, d);
      int up = w / g;
      int a = limit / up;
      long long ans = 0;
      ans = limit * 1LL * a - (a + 1) * 1LL * a / 2 * up;
      cout << ans << endl;
    }
  }
  return 0;
}
