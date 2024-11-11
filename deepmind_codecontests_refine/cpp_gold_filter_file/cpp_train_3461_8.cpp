#include <bits/stdc++.h>
using namespace std;
const long long du = 998244353;
const long long mxn = 5 * 1e5 + 1;
long long n, k;
long long mul(long long x, long long y) { return (x * 1ll * y) % du; }
long long power(long long x, long long y) {
  long long z = 1;
  while (y > 0) {
    if (y % 2 == 1) z = mul(z, x);
    x = mul(x, x);
    y /= 2;
  }
  return z;
}
long long f[mxn];
long long add(long long a, long long b) {
  a += b;
  if (a >= du) a -= du;
  if (a < 0) a += du;
  return (a);
}
long long inv(long long x) { return (power(x, du - 2)); }
long long divide(long long x, long long y) { return (mul(x, inv(y))); }
long long C(long long K, long long N) {
  if (N < K) return (0);
  return (divide(f[N], mul(f[N - K], f[K])));
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long ans = 0;
  cin >> n >> k;
  f[0] = 1;
  for (long long i = 1; i < mxn; i++) {
    f[i] = mul(f[i - 1], i);
  }
  for (long long i = 1; i <= n; i++) {
    long long t = max(0ll, n / i - 1);
    { ans = add(ans, C(k - 1, t)); }
  }
  cout << ans;
}
