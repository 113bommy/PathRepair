#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 3010;
const int MOD = 998244353;
int qpow(int a, int b) {
  int base = 1;
  while (b) {
    if (b & 1) base = 1ll * base * a % MOD;
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return base;
}
int n, m, A[MAXN], W[MAXN], F[MAXM][MAXM], G[MAXM][MAXM], Inv[MAXM << 1],
    sum[10];
namespace io {
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch))
    if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
char buf[1 << 15];
inline void write(int x) {
  if (x == 0) {
    putchar('0');
    return;
  }
  int tmp = x < 0 ? -x : x;
  if (x < 0) putchar('-');
  int cnt = 0;
  while (tmp > 0) {
    buf[cnt++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (cnt > 0) putchar(buf[--cnt]);
}
}  // namespace io
using namespace io;
int main() {
  n = read(), m = read();
  for (register int i = 1; i <= n; ++i) A[i] = read();
  for (register int i = 1; i <= n; ++i)
    W[i] = read(), sum[A[i]] += W[i], sum[2] += W[i];
  for (register int i = 0 > m - sum[0] ? 0 : m - sum[0]; i <= 2 * m; ++i)
    Inv[i] = qpow(sum[2] + i - m, MOD - 2);
  for (register int i = m; i >= 0; --i) {
    F[i][m - i] = G[i][m - i] = 1;
    for (register int j = m - i - 1 < sum[0] ? m - i - 1 : sum[0]; j >= 0;
         --j) {
      F[i][j] = (1ll * (sum[1] + i + 1) * F[i + 1][j] +
                 1ll * (sum[0] - j) * F[i][j + 1]) %
                MOD * Inv[i - j + m] % MOD;
      G[i][j] = (1ll * (sum[1] + i) * G[i + 1][j] +
                 1ll * (sum[0] - j - 1) * G[i][j + 1]) %
                MOD * Inv[i - j + m] % MOD;
    }
  }
  for (register int i = 1; i <= n; ++i)
    write(int(1ll * W[i] * (A[i] ? F[0][0] : G[0][0]) % MOD)), putchar('\n');
  return 0;
}
