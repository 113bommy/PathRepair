#include <bits/stdc++.h>
using namespace std;
long long rr[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long cc[] = {1, 1, 0, -1, -1, -1, 0, 1};
const long long mod = 1e9 + 7;
const long long N = 300050;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long test = 1;
  cin >> test;
  while (test--) {
    long long n, k;
    cin >> n >> k;
    long long l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 > l2) {
      swap(l1, l2);
      swap(r1, r2);
    }
    long long tot = 0, diff = 0, len = max(r1, r2) - min(l1, l2), ans = 0;
    if (r2 >= l1 && r2 <= r1) {
      tot = max(0LL, r2 - max(l1, l2));
    } else if (r1 >= l2 && r1 <= r2) {
      tot = max(0LL, r1 - max(l1, l2));
    }
    if (l1 > r2) {
      diff = r1 - r2;
    } else if (l2 > r1) {
      diff = l2 - r1;
    }
    len -= tot;
    tot *= n;
    if (tot >= k) {
      cout << 0 << '\n';
      continue;
    }
    k -= tot;
    if (len == 0) {
      cout << k * 2 << '\n';
      continue;
    }
    long long temp = min(n, k / len), sum = 0, sum2 = 0;
    sum = (temp > 0) ? (diff + len) + (k - len) * 2 : k;
    sum2 += temp * (len + diff);
    k -= temp * len;
    if (temp != n && k < len && k) {
      if (temp) {
        sum2 += min(2 * k, diff + k);
      } else
        sum2 += diff + k;
      k = 0;
    }
    sum2 += k * 2;
    ans += min(sum, sum2);
    cout << ans << '\n';
  }
  return 0;
}
