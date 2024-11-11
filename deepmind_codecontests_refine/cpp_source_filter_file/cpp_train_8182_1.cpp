#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int read() {
  int w = 1, s = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return w * s;
}
inline long long ksm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
int n, A[1000100], Max, f[1000100];
int Sum;
int main() {
  n = read();
  for (register int i = 1; i <= n; ++i)
    A[i] = read(), Max = max(Max, A[i]), Sum = Sum + A[i];
  f[1] = 1ll * (Sum - 1) * (Sum - 1) % mod * ksm(Sum, mod - 2) % mod;
  f[2] = (2 * f[1] - 1) % mod;
  int delta = (f[2] - f[1] + mod) % mod;
  for (register int i = 3; i <= n; ++i) {
    delta += (mod - 1ll * (Sum - 1) * ksm(Sum - i + 1, mod - 2) % mod);
    delta %= mod;
    f[i] = f[i - 1] + delta;
    f[i] %= mod;
  }
  int res = 0;
  for (register int i = 1; i <= n; ++i) res += f[A[i]], res %= mod;
  cout << res;
  return 0;
}
