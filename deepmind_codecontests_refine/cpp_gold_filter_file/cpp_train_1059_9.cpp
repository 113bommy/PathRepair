#include <bits/stdc++.h>
using namespace std;
int cnt_dig(long a) {
  if (a < 10) return 1;
  return 1 + cnt_dig(a / 10);
}
int main() {
  int q;
  cin >> q;
  long long f[100005], g[100005], k;
  long ans, cnt, lo, hi, mid;
  for (long i = 1; i < 100005; i++) {
    if (i == 1)
      g[i] = 1;
    else
      g[i] = g[i - 1] + cnt_dig(i);
  }
  for (long i = 1; i < 100005; i++) {
    if (i == 1)
      f[i] = g[i];
    else
      f[i] = f[i - 1] + g[i];
  }
  while (q--) {
    cin >> k;
    lo = 1;
    hi = 100005 - 1;
    while (lo < hi) {
      mid = (lo + hi) / 2;
      if (f[mid] < k)
        lo = mid + 1;
      else
        hi = mid;
    }
    if (f[hi] > k) {
      if (hi > 1) {
        hi--;
        k = k - f[hi];
        lo = 1;
        while (lo < hi && k > 0) {
          mid = (lo + hi) / 2;
          if (g[mid] < k)
            lo = mid + 1;
          else
            hi = mid;
        }
        if (g[hi] > k) {
          if (hi > 1) {
            hi--;
            k -= g[hi];
          }
        } else
          k -= g[hi];
      }
    } else
      k -= f[hi];
    if (k == 0)
      ans = (hi % 10);
    else {
      hi++;
      cnt = cnt_dig(hi);
      while (cnt != k - 1) {
        ans = hi % 10;
        hi /= 10;
        cnt--;
      }
    }
    cout << ans << endl;
  }
}
