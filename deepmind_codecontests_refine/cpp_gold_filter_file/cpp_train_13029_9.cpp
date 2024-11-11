#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
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
int n, m, A[1010100], W[1010100], S0, S1, f[3030][3030];
inline long long ksm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
inline int pls(int a, int b) {
  a += b;
  return a >= mod ? a - mod : a;
}
inline int mns(int a, int b) {
  a -= b;
  return a < 0 ? a + mod : a;
}
inline void Init() {
  f[0][0] = 1;
  for (register int i = 0; i < m; ++i) {
    for (register int j = 0; j <= i; ++j) {
      f[i + 1][j] =
          pls(f[i + 1][j],
              1ll * (S1 + i - j + mod) % mod *
                  ksm(((long long)S0 + S1 + i - 2 * j + mod) % mod, mod - 2) %
                  mod * f[i][j] % mod);
      f[i + 1][j + 1] =
          pls(f[i + 1][j + 1],
              1ll * (S0 - j) *
                  ksm(((long long)S0 + S1 + i - 2 * j + mod) % mod, mod - 2) %
                  mod * f[i][j] % mod);
    }
  }
}
int main() {
  n = read(), m = read();
  for (register int i = 1; i <= n; ++i) A[i] = read();
  for (register int i = 1; i <= n; ++i) {
    W[i] = read();
    if (A[i] == 0)
      S0 = pls(S0, W[i]);
    else
      S1 = pls(S1, W[i]);
  }
  Init();
  int tmp1 = 0, tmp2 = 0;
  for (register int i = 0; i <= m; ++i)
    tmp1 = pls(tmp1,
               1ll * f[m][i] * (S0 - i + mod) % mod * ksm(S0, mod - 2) % mod);
  for (register int i = 0; i <= m; ++i)
    tmp2 =
        pls(tmp2, 1ll * f[m][m - i] * (S1 + i) % mod * ksm(S1, mod - 2) % mod);
  for (register int i = 1; i <= n; ++i) {
    if (A[i] == 0)
      cout << 1ll * W[i] * tmp1 % mod << "\n";
    else
      cout << 1ll * W[i] * tmp2 % mod << "\n";
  }
  return 0;
}
