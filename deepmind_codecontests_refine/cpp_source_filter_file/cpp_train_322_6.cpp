#include <bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 998244353;
int n, s, r, inv[N], ans, C[N][N];
int ksm(int x, int y) {
  int s = 1;
  for (; y; y >>= 1, x = (long long)x * x % mod)
    if (y & 1) s = (long long)s * x % mod;
  return s;
}
void upd(int &x, int y) {
  x += y;
  x -= x >= mod ? mod : 0;
}
int calc(int n, int m, int lim) {
  if (n == 0) return m == 0;
  int res = 0;
  for (int i = 0, op = 1; i <= n && i * lim <= m; i++, op = mod - op)
    upd(res,
        (long long)op * C[m - i * lim + n - 1][n - 1] % mod * C[n][i] % mod);
  return res;
}
int main() {
  scanf("%d%d%d", &n, &s, &r);
  for (int i = (0); i <= (s + n); i++) C[i][0] = 1;
  for (int i = (1); i <= (s + n); i++)
    for (int j = (1); j <= (i); j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  inv[0] = inv[1] = 1;
  for (int i = (2); i <= (s); i++)
    inv[i] = (long long)inv[mod % i] * (mod - mod / i) % mod;
  for (int i = (r); i <= (s); i++)
    for (int j = 1, k = i; j <= n && k <= s; j++, k += i)
      upd(ans, (long long)calc(n - j, s - k, i) * C[n - 1][j - 1] % mod *
                   inv[j] % mod);
  ans = (long long)ans * ksm(C[s - r + n - 1][n - 1], mod - 2) % mod;
  printf("%d\n", ans);
  return 0;
}
