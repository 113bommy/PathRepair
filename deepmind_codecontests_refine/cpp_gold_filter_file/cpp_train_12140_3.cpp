#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e6 + 5;
long long t, n, m, k, a[siz];
long long sign[siz], p[siz], cnt[siz];
bool prime[siz];
long long f(long long c) { return (c * p[c - 1]) % mod; }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (long long i = 1; i < siz; i++) sign[i] = 1;
  for (long long i = 1; i < siz; i++) prime[i] = 1;
  prime[0] = prime[1] = 0;
  for (long long i = 2; i < siz; i++) {
    if (!prime[i]) continue;
    for (long long j = i; j < siz; j += i) {
      prime[j] = j == i;
      if ((j / i) % i == 0)
        sign[j] = 0;
      else
        sign[j] *= -1;
    }
  }
  p[0] = 1;
  for (long long i = 1; i < siz; i++) p[i] = (p[i - 1] * 2) % mod;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    cnt[x]++;
  }
  for (long long i = 1; i < siz; i++)
    for (long long j = 2 * i; j < siz; j += i) cnt[i] += cnt[j];
  long long ans = 0;
  for (long long i = 2; i < siz; i++) {
    long long cur = 0;
    for (long long j = i; j < siz; j += i) {
      cur = (cur + sign[j / i] * f(cnt[j])) % mod;
    }
    ans += cur * i;
    ans %= mod;
  }
  (ans += mod) %= mod;
  cout << ans << endl;
}
