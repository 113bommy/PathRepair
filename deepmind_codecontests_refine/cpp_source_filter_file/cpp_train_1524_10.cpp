#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
int n, m, f[N], jc[N], njc[N], ans;
int qpow(int x, int y) {
  if (!x) return 0;
  int res = 1;
  for (; y; x = 1ll * x * x % mod, y >>= 1)
    if (y & 1) res = 1ll * res * x % mod;
  return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int C(int x, int y) { return 1ll * jc[x] * njc[x - y] % mod * njc[y] % mod; }
int main() {
  scanf("%d%d", &n, &m);
  jc[0] = njc[0] = 1;
  for (int i = 1, iE = n; i <= iE; i++)
    jc[i] = 1ll * jc[i - 1] * i % mod, njc[i] = ny(jc[i]);
  ans = n;
  f[0] = 1;
  int sum = 1;
  for (int i = 1, iE = n - 1; i <= iE; i++) {
    f[i] = sum, f[i] = 1ll * f[i] * ny(i) % mod, (sum += f[i]) % mod;
    if (i >= m) (sum += mod - f[i - m]) %= mod;
  }
  for (int i = 0, iE = n - 1; i <= iE; i++) (ans += mod - f[i]) %= mod;
  ans = 1ll * ans * jc[n - 1] % mod;
  printf("%d\n", ans);
  return 0;
}
