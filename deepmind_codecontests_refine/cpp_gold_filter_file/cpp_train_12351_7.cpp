#include <bits/stdc++.h>
using namespace std;
int n, i, j;
long long a, b, A, B, cp[2222][2222], f[2222], st[2222], pwa[2222], pwb[2222];
long long Pw(long long a, long long b) {
  long long v = 1;
  for (; b; b >>= 1, a = a * a % 998244353)
    if (b & 1) v = v * a % 998244353;
  return v;
}
int main() {
  scanf("%d%I64d%I64d", &n, &a, &b);
  A = a * Pw(b, 998244353 - 2) % 998244353;
  B = (1 - A + 998244353) % 998244353;
  for (pwa[0] = pwb[0] = i = 1; i <= n; i++)
    pwa[i] = pwa[i - 1] * A % 998244353, pwb[i] = pwb[i - 1] * B % 998244353;
  for (i = 1; i <= n; i++)
    for (cp[i][0] = cp[i][i] = j = 1; j < i; j++)
      cp[i][j] =
          (cp[i - 1][j - 1] * pwa[i - j] + cp[i - 1][j] * pwb[j]) % 998244353;
  for (i = 1; i <= n; i++)
    for (st[i] = j = 1; j < i; j++)
      st[i] = (st[i] - st[j] * cp[i][j] % 998244353 + 998244353) % 998244353;
  for (i = 1; i <= n; i++) {
    f[i] = i * (i - 1) / 2 * st[i] % 998244353;
    for (j = 1; j < i; j++)
      f[i] = (f[i] + st[j] * cp[i][j] % 998244353 *
                         (j * (i - j) % 998244353 + j * (j - 1) / 2 + f[j] +
                          f[i - j])) %
             998244353;
    f[i] = f[i] * Pw(998244353 + 1 - st[i], 998244353 - 2) % 998244353;
  }
  printf("%I64d", f[n]);
}
