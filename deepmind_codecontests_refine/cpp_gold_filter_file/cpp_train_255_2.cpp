#include <bits/stdc++.h>
using namespace std;
int n, m, a[25][25];
char s[25][25];
int nho[1500000], dp[1500000];
int mask[25][25], cp[25][25];
int calc(int x) {
  if (x == 0) return 0;
  if (nho[x]) return dp[x];
  nho[x] = 1;
  dp[x] = 2000000000;
  int k = 0;
  while ((x & (1 << k)) == 0) k++;
  for (int j = 0; j < m; j++) {
    dp[x] = min(dp[x], calc(x ^ (1 << k)) + a[k + 1][j]);
    dp[x] = min(dp[x], calc(x & (x ^ mask[k + 1][j])) + cp[k + 1][j]);
  }
  return dp[x];
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= n; i++) gets(s[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++) {
      mask[i][j] = 0;
      cp[i][j] = 0;
      int cpmax = 0;
      for (int k = 1; k <= n; k++)
        if (s[i][j] == s[k][j]) {
          mask[i][j] |= (1 << (k - 1));
          cp[i][j] += a[k][j];
          cpmax = max(cpmax, a[k][j]);
        }
      cp[i][j] -= cpmax;
    }
  memset(nho, 0, sizeof(nho));
  int ans = calc((1 << n) - 1);
  printf("%d", ans);
}
