#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e6 + 5;
long long n, m, ans, P[N], sum[N], jc[N], inv[N];
char s[N];
inline long long read() {
  long long ret = 0, f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    ret = ret * 10 + c - 48;
    c = getchar();
  }
  if (f) return -ret;
  return ret;
}
long long C(long long n, long long m) {
  return jc[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main() {
  n = read();
  m = read();
  scanf("%s", s + 1);
  for (long long i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i] - '0';
  jc[0] = jc[1] = inv[0] = inv[1] = 1;
  for (long long i = 2; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
  for (long long i = 2; i <= n; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (long long i = 2; i <= n; i++) inv[i] = inv[i] * inv[i - 1] % mod;
  P[1] = 1;
  for (long long i = 2; i <= n; i++) P[i] = P[i - 1] * 10 % mod;
  for (long long i = 1; i <= n; i++) {
    if (n - i - 1 >= m - 1) {
      long long x = C(n - i - 1, m - 1);
      ans = (ans + sum[n - i] * P[i] % mod * x % mod) % mod;
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (n - i >= m) {
      long long x = C(n - i, m);
      ans = (ans + (s[n - i + 1] - '0') * P[i] % mod * x % mod) % mod;
    }
  }
  cout << (ans % mod + mod) % mod;
}
