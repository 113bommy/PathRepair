#include <bits/stdc++.h>
const int p = 1000000007;
int c[60][60], f[60][60][60][2], g[60], h[60][60][60][60];
int i, j, k, l, n, o, q, r, t, t1, t2;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &g[i]);
  for (i = 0; i <= n; i++)
    for (j = 0; j <= i; j++)
      if ((j == 0) || (j == i))
        c[i][j] = 1;
      else
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
  h[0][0][0][0] = 1;
  for (i = 0; i <= n; i++)
    for (j = 0; i + 2 * j <= n; j++)
      for (k = 0; k <= i + j; k++)
        for (l = 0; l <= j; l++)
          if (h[i][j][k][l]) {
            if (!j) {
              if (k)
                h[i + 1][j][k - 1][l] =
                    (h[i + 1][j][k - 1][l] + 1LL * k * h[i][j][k][l]) % p;
              h[i + 1][j][k + 1][l] =
                  (h[i + 1][j][k + 1][l] + h[i][j][k][l]) % p;
            }
            if (k > 1)
              h[i][j + 1][k - 2][l] =
                  (h[i][j + 1][k - 2][l] + 1LL * c[k][2] * h[i][j][k][l]) % p;
            if (l > 1)
              h[i][j + 1][k + 2][l - 2] =
                  (h[i][j + 1][k + 2][l - 2] + 1LL * c[l][2] * h[i][j][k][l]) %
                  p;
            if ((k) && (l))
              h[i][j + 1][k][l - 1] =
                  (h[i][j + 1][k][l - 1] + 1LL * k * l * h[i][j][k][l]) % p;
            if (k)
              h[i][j + 1][k][l] =
                  (h[i][j + 1][k][l] + 1LL * k * h[i][j][k][l]) % p;
            if (l)
              h[i][j + 1][k + 2][l - 1] =
                  (h[i][j + 1][k + 2][l - 1] + 1LL * l * h[i][j][k][l]) % p;
            h[i][j + 1][k][l + 1] = (h[i][j + 1][k][l + 1] + h[i][j][k][l]) % p;
          }
  if (g[1] == 2)
    f[1][0][1][0] = 1;
  else
    f[1][0][0][1] = 1;
  for (i = 1; i <= n; i++)
    for (j = 0; i + j <= n; j++)
      for (k = 0; i + j + 2 * k <= n; k++)
        for (l = 0; (l <= 1) && (i + j + 2 * k + 3 * l <= n); l++)
          if ((j + 2 * k + 3 * l) && (f[i][j][k][l])) {
            r = f[i][j][k][l], t = 0;
            for (o = 1; o <= j; o++) r = 1LL * r * c[t + 1][t] % p, t++;
            for (o = 1; o <= k; o++) r = 1LL * r * c[t + 2][t] % p, t++, t++;
            for (o = 1; o <= l; o++)
              r = 1LL * r * c[t + 3][t] % p, t++, t++, t++;
            t1 = 0, t2 = 0;
            for (o = i + 1; o <= i + j + 2 * k + 3 * l; o++)
              if (g[o] == 2)
                t1++;
              else
                t2++;
            for (o = 0; o <= t1 + 2 * t2; o++)
              for (q = 0; o + 2 * q <= t1 + 2 * t2; q++)
                f[i + j + 2 * k + 3 * l][o][q][0] =
                    (f[i + j + 2 * k + 3 * l][o][q][0] +
                     1LL * r * h[t1][t2][o][q]) %
                    p;
          }
  printf("%d", f[n][0][0][0]);
  return 0;
}
