#include <bits/stdc++.h>
using namespace std;
long long n, m, a, b, i, M = 1000000007;
long long s[1000005], ans;
inline long long read() {
  long long x = 0, tag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') tag = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * tag;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, y, x);
  y -= -a / b * x;
  return g;
}
long long ni(long long a) {
  long long x, y;
  exgcd(a, M, x, y);
  return x;
}
long long C(long long x, long long y) {
  return s[x] * ni(s[y]) % M * ni(s[x - y]) % M;
}
long long Qpow(long long a, long long b) {
  long long s = a, ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * s % M;
    s = s * s % M;
    b >>= 1;
  }
  return ans;
}
signed main() {
  n = read(), m = read(), a = read(), b = read();
  s[0] = 1;
  for (i = 1; i <= 1000000; i++) s[i] = s[i - 1] * i % M;
  for (i = 0; i <= n - 2 && i <= m - 1; i++)
    if (i == n - 2)
      ans = (ans + C(m - 1, i) * C(n - 2, i) % M * s[i] % M *
                       Qpow(m, n - 2 - i) % M) %
            M;
    else
      ans =
          (ans + C(m - 1, i) * C(n - 2, i) % M * s[i] % M * Qpow(n, n - 3 - i) %
                     M * (i + 2) % M * Qpow(m, n - 2 - i) % M) %
          M;
  printf("%lld\n", (ans % M + M) % M);
}
