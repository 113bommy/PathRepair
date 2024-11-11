#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5, maxm = 800;
int n, m, k;
long double inv[maxm + 3], dp[2][maxm + 3], ans;
int main() {
  scanf("%d %d", &n, &k);
  m = min(n + 1, maxm);
  for (int i = 1; i <= maxm + 1; i++) {
    inv[i] = (long double)1 / i;
  }
  int cur = 0, nxt = 1;
  dp[cur][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[nxt][j] = 0;
    }
    for (int j = 1; j <= m; j++) {
      long double x = inv[k] * inv[j + 1];
      dp[nxt][j] += dp[cur][j] * (1 - x);
      dp[nxt][j + 1] += dp[cur][j] * x;
      ans += dp[cur][j] * ((j + 1) * (j + 2) / 2 - 1) * inv[j + 1];
    }
    swap(cur, nxt);
  }
  double res = ans;
  printf("%.18lf\n", res);
  return 0;
}
