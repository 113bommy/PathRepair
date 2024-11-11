#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, a[maxn], dp[22][maxn], lc[22];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (int j = 0; j <= 20; j++)
      if ((a[i] >> j) & 1)
        dp[j][i] = i;
      else
        dp[j][i] = n + 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 20; j++)
      if (lc[j] && ((a[i] >> j) & 1)) {
        for (int k = 0; k <= 20; k++) dp[k][i] = min(dp[k][i], dp[k][lc[j]]);
      }
    for (int j = 0; j <= 20; j++)
      if ((a[i] >> j) & 1) lc[j] = i;
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    bool ok = 0;
    scanf("%d%d", &l, &r);
    for (int j = 0; j <= 20; j++)
      if (((a[l] >> j) & 1) && dp[j][r] <= l) ok = 1;
    printf(ok ? "Shi\n" : "Fou\n");
  }
  return 0;
}
