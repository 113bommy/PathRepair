#include <bits/stdc++.h>
using namespace std;
const int INF = ~0u >> 2;
int n, m, a[21][21], r[2000001], c[21][21], p[21][21], f[2000001];
char s[21][21];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) r[1 << i - 1] = i, scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int maxcost = 0;
      for (int k = 1; k <= n; k++) {
        if (s[k][j] == s[i][j]) {
          maxcost = max(maxcost, a[k][j]);
          p[i][j] |= 1 << k - 1;
          c[i][j] += a[i][j];
        }
      }
      c[i][j] -= maxcost;
    }
  for (int i = 1; i < (1 << n); i++) f[i] = INF;
  for (int s = 0; s < (1 << n) - 1; s++) {
    int l = (~s) & -(~s), pos = r[l];
    for (int j = 1; j <= m; j++) {
      f[s | l] = min(f[s | l], f[s] + a[pos][j]);
      f[s | p[pos][j]] = min(f[s | p[pos][j]], f[s] + c[pos][j]);
      if (p[pos][j] == l) f[s | l] = min(f[s | l], f[s]);
    }
  }
  printf("%d\n", f[(1 << n) - 1]);
  return 0;
}
