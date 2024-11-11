#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long l1, r1;
    cin >> l1 >> r1;
    long long l2, r2;
    cin >> l2 >> r2;
    if (l2 < l1) {
      swap(l1, l2);
      swap(r1, r2);
    }
    long long cur = max(0ll, min(r1, r2) - max(l1, l2));
    cur *= n;
    if (cur >= k) {
      cout << "0\n";
      continue;
    }
    long long ans = 0;
    if (r1 > l2) {
      for (long long i = 0; i < n; ++i) {
        long long t1 = min(r1, r2) - max(l1, l2);
        long long t2 = max(r1, r2) - min(l1, l2);
        long long x = t2 - t1;
        if (cur + x <= k) {
          cur += x;
          ans += x;
        } else {
          ans += k - cur;
          cur = k;
          break;
        }
      }
      if (cur < k) {
        ans += 2 * (k - cur);
      }
    } else {
      long long t = l2 - r1;
      r1 = l2;
      long long x1 = 0, x2 = 0;
      long long cur2 = cur;
      ans = 1e18;
      for (long long i = 0; i < n; ++i) {
        x2 += t;
        long long t1 = min(r1, r2) - max(l1, l2);
        long long t2 = max(r1, r2) - min(l1, l2);
        long long x = t2 - t1;
        if (cur2 + x <= k) {
          cur2 += x;
          x2 += x;
        } else {
          x2 += k - cur2;
          cur2 = k;
          ans = min(ans, x2);
          break;
        }
        if (cur2 <= k) {
          ans = min(ans, x2 + 2 * (k - cur2));
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
