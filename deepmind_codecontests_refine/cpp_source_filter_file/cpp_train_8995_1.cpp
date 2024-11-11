#include <bits/stdc++.h>
using namespace std;
const int maxn = 6;
long long t, tmp[maxn][maxn], res[maxn][maxn], now[maxn][maxn], g[maxn][maxn];
int n, sx, sy, dx, dy, mod;
void multi(long long a[maxn][maxn], long long b[maxn][maxn]) {
  memset(tmp, 0, sizeof(tmp));
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      for (int k = 0; k < 6; k++)
        tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j] % mod) % mod;
  memcpy(a, tmp, sizeof(tmp));
}
void qpow(long long a[maxn][maxn], long long y) {
  memset(res, 0, sizeof(res));
  for (int i = 0; i < 6; i++) res[i][i] = 1;
  while (y) {
    if (y & 1) multi(res, a);
    multi(a, a);
    y >>= 1;
  }
}
int main() {
  scanf("%d%d%d%d%d%lld", &mod, &sx, &sy, &dx, &dy, &t);
  sx--;
  sy--;
  memset(now, 0, sizeof(now));
  memset(g, 0, sizeof(g));
  now[0][1] = now[0][2] = now[0][4] = 1;
  now[0][0] = now[0][5] = 2;
  now[1][0] = now[1][3] = now[1][4] = 1;
  now[1][1] = now[1][5] = 2;
  now[2][0] = now[2][1] = now[2][2] = now[2][4] = 1;
  now[2][5] = 2;
  now[3][0] = now[3][1] = now[3][3] = now[3][4] = 1;
  now[3][5] = 2;
  now[4][4] = now[4][5] = now[5][5] = 1;
  g[0][0] = 1LL * sx;
  g[1][0] = 1LL * sy;
  g[2][0] = (dx % mod + mod) % mod;
  g[3][0] = ((dy % mod + mod) % mod);
  g[4][0] = g[5][0] = 1LL;
  qpow(now, t);
  multi(res, g);
  printf("%lld %lld\n", res[0][0] + 1, res[1][0] + 1);
  return 0;
}
