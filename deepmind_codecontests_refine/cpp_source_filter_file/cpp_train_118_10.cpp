#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
const long long MOD = 998244353;
long long n, cnt[20], a[N];
long long p10[20];
long long scs(long long x) {
  long long res = 0;
  while (x) {
    res++;
    x /= 10;
  }
  return res;
}
long long calc(long long x) {
  long long res = 0;
  long long nDi = scs(x);
  for (long long i = 1; i <= nDi; i++) {
    long long u = x % 10;
    x /= 10;
    for (long long j = 1; j <= 18; j++) {
      long long dem = 0;
      {
        long long v = j - i;
        if (v >= 0 && v == i - 1) {
          for (long long k = v; k <= 10; k++) {
            dem += cnt[k];
          }
        } else if (v >= 0 && v < i - 1) {
          dem += cnt[v];
        }
      }
      {
        long long v = j - i;
        if (v >= 0 && v == i) {
          for (long long k = v; k <= 10; k++) {
            dem += cnt[k];
          }
        } else if (v >= 0 && v < i) {
          dem += cnt[v];
        }
      }
      res = (res + 1LL * u * dem * p10[j - 1]) % MOD;
    }
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  p10[0] = 1;
  for (long long i = 1; i < 20; i++) {
    p10[i] = (p10[i - 1] * 10) % MOD;
  }
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[scs(a[i])]++;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans = (ans + calc(a[i])) % MOD;
  }
  cout << ans;
  return 0;
}
