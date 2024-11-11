#include <bits/stdc++.h>
using namespace std;
const int M = 2001;
const int Q = 1e9 + 7;
vector<long long> mas[M];
long long dp[M][M], ans;
int i, j, n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i % j == 0) mas[i].push_back(i / j);
    }
  }
  for (i = 1; i <= n; i++) dp[1][i] = 1;
  for (i = 2; i <= k; i++) {
    for (j = 1; j <= n; j++) {
      dp[i][j] = 0;
      for (k = 0; k < mas[j].size(); k++)
        dp[i][j] = (dp[i][j] + dp[i - 1][mas[j][k]]) % Q;
    }
  }
  ans = 0;
  for (i = 1; i <= n; i++) {
    ans = (ans + dp[k][i]) % Q;
  }
  printf("%I64d", ans);
  return 0;
}
