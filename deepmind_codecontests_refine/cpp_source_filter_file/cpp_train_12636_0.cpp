#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long M = 1e6 + 5;
const long long maxn = 5e6 + 5;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f3f;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long ksm(long long x, long long y = mod - 2, long long z = mod) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % z;
    x = (x * x) % z;
    y >>= 1;
  }
  return ret;
}
long long inv[N], fac[N], ifc[N];
void Init(long long n) {
  inv[1] = 1;
  for (register signed i = 2; i <= n; i++)
    inv[i] = inv[mod % i] * (mod - mod / i) % mod;
  fac[0] = 1;
  for (register signed i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  ifc[0] = 1;
  for (register signed i = 1; i <= n; i++) ifc[i] = ifc[i - 1] * inv[i] % mod;
}
long long C(long long n, long long m) {
  if (m > n || m < 0) return 0;
  return fac[n] * ifc[m] % mod * ifc[n - m] % mod;
}
long long f(long long b, long long n) {
  if (b == 0 || b == 1) return -1;
  if (n < b) return n;
  return f(b, n / b) + n % b;
}
long long n;
long long a[N];
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = i;
  for (long long k = 2; k <= n; k++) {
    a[n + k - 1] = a[n + k - 1 - (n - (n / k) * k)];
    for (long long i = (n / k) * k + k - 1; i >= k - 1; i -= k) a[i] = a[i - k];
  }
  for (long long i = n; i < 2 * n; i++) cout << a[i] << " ";
  cout << endl;
}
