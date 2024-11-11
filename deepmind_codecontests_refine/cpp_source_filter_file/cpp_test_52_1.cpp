#include <bits/stdc++.h>
using namespace std;
long long constexpr max_n = 1e5 + 10, max_lg = 30, mas_sq = 1000, mod = 1e9 + 7;
long long bpow(long long x, long long y) {
  long long res = 1LL;
  while (y) {
    if (y & 1) {
      res *= x;
      res %= mod;
    }
    x *= x;
    x %= mod;
    y /= 2;
  }
  return res;
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    while (k > 0) {
      long long a = 0;
      for (long long i = 1; i <= k; i++) {
        if (((1LL << i) - 1LL) <= k) {
          a = i;
        } else
          break;
      }
      k -= ((1LL << a) - 1LL);
      if (k > 0) {
        ans += bpow(n, a);
        k--;
      } else {
        for (long long i = 0; i < (a - 1); i++) {
          ans += bpow(n, i);
          ans %= mod;
        }
      }
      ans %= mod;
    }
    cout << (long long)ans << '\n';
  }
}
