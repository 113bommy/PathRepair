#include <bits/stdc++.h>
const int N = 1e5 + 1, P = 1e1 + 7;
int i, j, k, n, q, r, d[N], f[N][20];
int main() {
  for (i = 2; i < N; ++i)
    if (!d[i])
      for (j = i; j < N; j += i) d[j] = i;
  for (i = 0; i < N; *f[i++] = 1)
    ;
  for (d[1] = i = 1; i < 20; f[0][i++] = 2)
    ;
  for (i = 1; i < N; ++i)
    for (j = 1; j < 20; ++j) f[i][j] = (f[i][j - 1] + f[i - 1][j]) % P;
  for (scanf("%d", &q); q--; printf("%d\n", r)) {
    scanf("%d%d", &k, &n);
    for (r = 1; n > 1; r = 1ll * r * f[k][i] % P)
      for (j = d[n], i = 0; n % j == 0; n /= j) ++i;
  }
}
