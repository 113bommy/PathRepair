#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
int wyn[N];
long long dp[N][N];
int tab[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", tab + i);
  wyn[0] = 1;
  for (int i = 1; i < n; i++) {
    wyn[i] = 1;
    for (int j = 0; j < i; j++)
      if (tab[j] < tab[i]) wyn[i] = max(wyn[i], wyn[j] + 1);
  }
  for (int i = 0; i < n; i++) wyn[n - 1] = max(wyn[i], wyn[n - 1]);
  for (int i = 1; i <= n; i++) dp[i][i] = dp[i][i - 1] = 1;
  for (int d = 1; d < n; d++)
    for (int i = 1; d + i < n; i++) {
      dp[i][i + d] = dp[i][i + d - 1];
      for (int j = i + d - 1; j > 0; j--) {
        if (tab[j] > tab[d + i]) continue;
        dp[i][i + d] += (dp[i][j] * dp[j + 1][i + d - 1]) % mod;
      }
      dp[i][i + d] %= mod;
    }
  printf("%lld\n", dp[1][n - 1] % mod);
}
