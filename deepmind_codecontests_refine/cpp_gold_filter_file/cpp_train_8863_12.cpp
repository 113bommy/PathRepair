#include <bits/stdc++.h>
using namespace std;
const int N = 2007;
const int mod = 998244353;
template <class I>
inline void read(I &x) {
  int f = 1;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9';
       x = (x << 3) + (x << 1) + (c & 15), c = getchar())
    ;
  x *= f;
}
long long ksm(int x, int y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    y >>= 1;
    x = 1ll * x * x % mod;
  }
  return res;
}
long long f[2 * N][N][2], jc[N * 2];
int main() {
  int n, l, k;
  read(n), read(k), read(l);
  f[0][0][0] = 1;
  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= i; j++)
      for (int o = 0; o <= 1; o++) {
        if (j > n) continue;
        f[i + 1][j + 1][o] = (f[i + 1][j + 1][o] + f[i][j][o]) % mod;
        if (o == 0 && j >= k)
          f[i + 1][j][1] = (f[i + 1][j][1] + f[i][j][o]) % mod;
        if (j) f[i + 1][j - 1][o] = (f[i + 1][j - 1][o] + f[i][j][o] * j) % mod;
      }
  jc[0] = 1;
  for (int i = 1; i <= 2 * n + 1; i++) jc[i] = jc[i - 1] * i % mod;
  long long ans = f[2 * n + 1][0][1] * ksm(2, n) % mod * jc[n] % mod *
                  ksm(jc[2 * n + 1], mod - 2) % mod * l % mod;
  printf("%lld\n", ans);
  return 0;
}
