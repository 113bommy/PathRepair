#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, T, l, r, mid;
long long check(long long x) {
  if (x * d >= c) return a + 1;
  return x * b * d;
}
signed main() {
  cin >> T;
  while (T--) {
    cin >> a >> b >> c >> d;
    if (c * b < a) {
      cout << "-1\n";
      continue;
    }
    l = 0;
    r = 1000000000;
    while (l < r) {
      mid = r - (r - l >> 1);
      if (check(mid) >= a)
        r = mid - 1;
      else
        l = mid;
    }
    cout << (l + 1) * a - l * (l + 1) / 2 * d * b << "\n";
  }
}
