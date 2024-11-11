#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long n, i, a[100002], p[100002], fac[100002], inv[100002], ans;
long long read() {
  char c = getchar();
  long long w = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c <= '9' && c >= '0') {
    w = w * 10 + c - '0';
    c = getchar();
  }
  return w;
}
long long poww(long long a, long long b) {
  long long ans = 1, base = a;
  while (b) {
    if (b & 1) ans = ans * base % mod;
    base = base * base % mod;
    b >>= 1;
  }
  return ans;
}
long long C(long long n, long long m) {
  if (n < 0 || m < 0 || n < m) return 0;
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
long long my_comp(const long long &x, const long long &y) {
  return a[x] < a[y];
}
long long solve(long long s) {
  long long l = s, r = s, ans = 1;
  for (long long i = (a[s] == n + 1) ? 1 : 2; i <= n; i++) {
    long long pos = p[i], cnt = a[p[i]] - a[p[i - 1]] - 1;
    if (a[p[i]] == n + 1) pos = n + 1;
    if (pos >= l && pos <= r) return 0;
    if (pos < l) {
      if (l - pos - 1 > cnt) return 0;
      ans = ans * C(cnt, l - pos - 1) % mod;
      r += cnt - (l - pos - 1);
      l = pos;
    } else {
      if (pos - r - 1 > cnt) return 0;
      ans = ans * C(cnt, pos - r - 1) % mod;
      l -= cnt - (r - pos - 1);
      r = pos;
    }
    if (a[p[i]] == n + 1) break;
  }
  return ans;
}
signed main() {
  n = read();
  for (i = a[0] = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] == 0) a[i] = n + 1;
  }
  for (i = 1; i <= n; i++) p[i] = i;
  sort(p + 1, p + n + 1, my_comp);
  for (i = fac[0] = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  inv[n] = poww(fac[n], mod - 2);
  for (i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  if (a[p[1]] == 1)
    ans = solve(p[1]);
  else {
    for (i = 1; i <= n; i++) {
      if (a[i] == n + 1) ans = (ans + solve(i)) % mod;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
