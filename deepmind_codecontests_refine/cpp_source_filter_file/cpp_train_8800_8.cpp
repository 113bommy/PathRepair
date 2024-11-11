#include <bits/stdc++.h>
using namespace std;
int n, k;
int l, r;
long long pw[500007], inv[500007], ans = 0;
pair<int, int> p[500007];
const long long mod = 1e9 + 7;
long long pwr(long long x, long long y) {
  if (y == 0) return 1LL;
  if (y == 1) return x;
  long long ret = pwr(x, y / 2);
  if (y % 2 == 0)
    return (ret * ret) % mod;
  else
    return (((ret * ret) % mod) * x) % mod;
}
long long C(long long k, long long n) {
  if (k > n)
    return 0;
  else
    return (((pw[n] * inv[k]) % mod) * inv[n - k]);
}
int main() {
  ios_base::sync_with_stdio(0);
  inv[0] = 1;
  pw[0] = 1;
  for (long long i = 1; i <= 500000; i++) pw[i] = (pw[i - 1] * i) % mod;
  inv[500000] = pwr(pw[500000], mod - 2);
  for (long long i = 499999; i >= 1; i--) inv[i] = (inv[i + 1] * (i + 1)) % mod;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> l >> r;
    p[i * 2 - 1] = make_pair(l, 1);
    p[i * 2] = make_pair(r + 1, -1);
  }
  sort(p + 1, p + 1 + 2 * n);
  long long cur = 1;
  for (int i = 2; i <= 2 * n; i++) {
    long long val = p[i].first - p[i - 1].first;
    ans += (val * C(k, cur)) % mod;
    if (ans >= mod) ans -= mod;
    cur += p[i].second;
  }
  cout << ans;
}
