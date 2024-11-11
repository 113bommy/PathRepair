#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7,
                maxlog = 65;
long long d[maxn], fc[maxn], inv[maxn];
long long _pow(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = _pow(a, b / 2);
  ans = (ans * ans) % mod;
  if (b % 2) ans *= a;
  return ans % mod;
}
long long en(long long k, long long n) {
  if (k > n) return 0;
  if (k == n) return 1;
  return ((fc[n] * inv[k]) % mod * inv[n - k]) % mod;
}
long long cn(long long x, long long y) {
  if (x == 1) return 1;
  long long cnt = 0, dd = d[x];
  while (!(x % dd)) {
    cnt++;
    x /= dd;
  }
  return (cn(x, y) * en(cnt, y + cnt - 1)) % mod;
}
int32_t main() {
  fc[0] = 1;
  for (long long i = 1; i < maxn; i++) fc[i] = (fc[i - 1] * i) % mod;
  inv[maxn - 1] = _pow(fc[maxn - 1], mod - 2);
  for (long long i = maxn - 2; i >= 0; i--)
    inv[i] = (inv[i + 1] * (i + 1)) % mod;
  for (long long i = 2; i < maxn; i++) {
    if (!d[i]) {
      for (long long j = i; j < maxn; j += i) {
        if (!d[j]) d[j] = i;
      }
    }
  }
  long long Q;
  cin >> Q;
  for (long long q = 0; q < Q; q++) {
    long long x, y;
    cin >> x >> y;
    cout << (cn(x, y) * _pow((long long)2, y - 1)) % mod << '\n';
  }
}
