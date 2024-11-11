#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
  x *= f;
}
const int mod = 998244353;
long long frac[6100], inv[6100];
long long Pow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod, y >>= 1;
  }
  return res;
}
void predo(int n) {
  frac[0] = 1;
  for (int i = 1; i <= n; ++i) frac[i] = frac[i - 1] * i % mod;
  inv[n] = Pow(frac[n], mod - 2);
  for (int i = n - 1; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % mod;
}
long long C(int n, int m) {
  if (n < 0 || m < 0) return 0;
  return frac[n] * inv[m] % mod * inv[n - m] % mod;
}
long long solve(int s, int n, int m) {
  if (!n) return !s;
  if (n * m < s) return 0;
  long long ans = 0, f = -1;
  for (int i = 0; i <= n; ++i)
    f = -f, ans = (ans + f * C(n, i) * C(s - i * (m + 1) + n - 1, n - 1)) % mod;
  return ans;
}
int main() {
  int p, s, r;
  read(p), read(s), read(r);
  if (p == 1) return puts("1"), 0;
  predo(p + s);
  long long ans = 0;
  for (int j = r; j <= s; ++j)
    for (int k = 1; k * j <= s && k <= p; ++k)
      ans = (ans + solve(s - (k * j), p - k, j - 1) * C(p - 1, k - 1) % mod *
                       Pow(k, mod - 2)) %
            mod;
  ans = ans * Pow(C(s - r + p - 1, p - 1), mod - 2) % mod;
  printf("%lld\n", (ans + mod) % mod);
  return 0;
}
