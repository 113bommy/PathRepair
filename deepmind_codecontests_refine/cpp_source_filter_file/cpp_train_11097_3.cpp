#include <bits/stdc++.h>
const int mod = 1000000007;
int f[33][2][2][2], g[33][2][2][2];
int calc(int x, int y, int k) {
  for (int i = 0; i <= 30; i++)
    for (int sx = 0; sx < 2; sx++)
      for (int sy = 0; sy < 2; sy++)
        for (int sk = 0; sk < 2; sk++) {
          f[i][sx][sy][sk] = g[i][sx][sy][sk] = 0;
          if (!i)
            f[i][sx][sy][sk] = !sx && !sy && !sk;
          else
            for (int dx = 0; dx < 2; dx++)
              for (int dy = 0; dy < 2; dy++) {
                if (sx && dx > (x >> i - 1 & 1) ||
                    sy && dy > (y >> i - 1 & 1) ||
                    (sk && (dx ^ dy) > (k >> i - 1 & 1)))
                  continue;
                int tx = sx && dx == (x >> i - 1 & 1),
                    ty = sy && dy == (y >> i - 1 & 1),
                    tk = sk && (dx ^ dy) == (k >> i - 1 & 1);
                (f[i][sx][sy][sk] += f[i - 1][tx][ty][tk]) %= mod;
                (g[i][sx][sy][sk] += g[i - 1][tx][ty][tk]) %= mod;
                if (dx ^ dy)
                  (g[i][sx][sy][sk] +=
                   (1ll << i - 1) * f[i - 1][tx][ty][tk] % mod) %= mod;
              }
        }
  return (f[30][1][1][1] + g[30][1][1][1]) % mod;
}
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int x1, y1, x2, y2, k, s;
    scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
    s = (calc(x2, y2, k) - calc(x2, y1 - 1, k) - calc(x1 - 1, y2, k) +
         calc(x1 - 1, y1 - 1, k)) %
        mod;
    printf("%d\n", s < 0 ? s + mod : s);
  }
}
