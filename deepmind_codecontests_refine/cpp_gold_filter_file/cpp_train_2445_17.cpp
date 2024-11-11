#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, n;
  cin >> a >> b >> n;
  while (n--) {
    long long l, t, m;
    cin >> l >> t >> m;
    long long lo = l, hi = (t - a) / b + 2, mid, ans = -1, n1;
    while (lo < hi) {
      mid = (lo + hi) / 2;
      n1 = (mid - l + 1);
      if (a + (mid - 1) * b <= t &&
          n1 * (a + (l - 1) * b) + (n1 * (n1 - 1) * b) / 2 <= t * m) {
        lo = mid + 1;
        ans = max(ans, mid);
      } else
        hi = mid;
    }
    cout << ans << endl;
  }
  return 0;
}
