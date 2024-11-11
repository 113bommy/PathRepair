#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxm = 105;
const int maxk = 105;
const long long mod = 1e9 + 7;
long long binom[maxn * 2][maxn * 2], wys[2][maxn][maxn][maxk];
void add(long long &x, long long y) {
  x += y;
  x -= (x >= mod) * mod;
  return;
}
int main() {
  binom[0][0] = 1;
  for (int i = 1; i <= 200; i++)
    for (int j = 0; j <= i; j++) {
      binom[i][j] = binom[i - 1][j];
      if (j) binom[i][j] += binom[i - 1][j - 1];
      binom[i][j] = min(binom[i][j], 101ll);
    }
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  if (n == 1 || m == 1 || k == 1) {
    puts("0");
    return 0;
  }
  for (int i = 2; i <= n; i += 2) wys[0][i][i / 2][2] = 1;
  long long ret = n / 2 * (m - 1) % mod;
  for (int i = 2; i < m; i++) {
    memset(wys[!(i & 1)], 0, sizeof(wys[!(i & 1)]));
    for (int j = 1; j <= n; j++)
      for (int x = 1; x <= j; x++)
        for (int y = 1; y <= k; y++) {
          if (wys[i & 1][j][x][y] == 0) continue;
          for (int z = 1; j + z * 2 <= n; z++) {
            int upd = y * binom[x + z - 1][z];
            if (upd > k) break;
            add(wys[!(i & 1)][j + z * 2][z][upd], wys[i & 1][j][x][y]);
          }
        }
    long long cur = 0;
    for (int j = 1; j <= n; j++)
      for (int x = 1; x <= j; x++)
        for (int y = 1; y <= k; y++) add(cur, wys[!(i & 1)][j][x][y]);
    ret = (ret + 1ll * (m - i) * cur) % mod;
  }
  printf("%lld\n", ret);
  return 0;
}
