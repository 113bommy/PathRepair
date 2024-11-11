#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long f[105][105][105], g[105][105][105], c[105][105];
struct edge {
  int k, next;
} e[205];
int home[205], cnt = -1, n, siz[205];
void add(int x, int y) {
  cnt++;
  e[cnt].k = y;
  e[cnt].next = home[x];
  home[x] = cnt;
}
void dfs(int k, int F) {
  f[k][1][1] = 1;
  siz[k] = 1;
  for (int i = home[k]; ~i; i = e[i].next)
    if (e[i].k != F) {
      dfs(e[i].k, k);
      int x = e[i].k;
      for (int p = 1; p <= siz[k]; p++) {
        for (int S1 = 1; S1 + p - 1 <= siz[k]; S1++)
          g[k][p][S1] = f[k][p][S1], f[k][p][S1] = 0;
      }
      for (int p = 1; p <= siz[k]; p++) {
        for (int j = 1; j <= siz[e[i].k]; j++) {
          for (int S1 = 1; S1 + p - 1 <= siz[k]; S1++) {
            for (int S2 = 1; S2 + j - 1 <= siz[e[i].k]; S2++) {
              f[k][p + j - 1][S1 + S2] =
                  (f[k][p + j - 1][S1 + S2] + g[k][p][S1] * f[x][j][S2]) % mod;
              f[k][p + j][S1] =
                  (f[k][p + j][S1] + g[k][p][S1] * f[x][j][S2] % mod * S2) %
                  mod;
            }
          }
        }
      }
      siz[k] += siz[e[i].k];
    }
}
long long d[105];
long long quick_pow(long long a, long long b) {
  if (b < 0) b += mod - 1;
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ans = ans * a % mod;
  return ans;
}
int main() {
  memset(home, -1, sizeof(home));
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) {
    c[i][0] = 1;
    for (int p = 1; p <= i; p++)
      c[i][p] = (c[i - 1][p] + c[i - 1][p - 1]) % mod;
  }
  add(0, 1);
  add(1, 0);
  for (int i = 1, x, y; i < n; i++) {
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs(0, -1);
  for (int i = n - 1; ~i; i--) {
    d[i] = f[0][n - i + 1][1] * quick_pow(n, n - i - 2) % mod;
    for (int p = i + 1, op = -1; p < n; p++, op = -1) {
      d[i] = (d[i] + d[p] * op * c[p][i]) % mod;
    }
  }
  for (int i = 0; i < n; i++)
    printf((i == n - 1) ? "%I64d" : "%I64d ", (d[i] + mod) % mod);
  return 0;
}
