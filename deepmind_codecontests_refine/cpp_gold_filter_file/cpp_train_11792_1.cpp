#include <bits/stdc++.h>
using namespace std;
long long t, n, k, l1, l2, r1, r2;
long long x, a, b;
int main(void) {
  cin >> t;
  while (t--) {
    cin >> n >> k >> l1 >> r1 >> l2 >> r2;
    long long ans = 0;
    if (l1 > l2) {
      x = l1;
      l1 = l2;
      l2 = x;
      x = r1;
      r1 = r2;
      r2 = x;
    }
    if (l2 > r1) {
      a = l2 - r1;
      b = r2 - l1 - a;
      if (k <= n * (a + b)) {
        long long r = k % (a + b);
        long long c = k / (a + b);
        ans = c * (2 * a + b);
        if (c && (r < a))
          ans += r * 2;
        else if (r)
          ans += (a + r);
      } else {
        ans = (k - n * (a + b)) * 2 + n * (2 * a + b);
      }
    } else {
      a = min(r1, r2) - l2;
      b = max(r1, r2) - l1;
      if (k <= n * a)
        ans = 0;
      else if (k <= n * b)
        ans = k - n * a;
      else
        ans = (k - n * b) * 2 + n * (b - a);
    }
    cout << ans << '\n';
  }
  return 0;
}
