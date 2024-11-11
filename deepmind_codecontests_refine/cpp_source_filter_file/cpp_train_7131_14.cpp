#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
const int maxs = 5e4;
int dp[maxn][maxs];
int N, K, S;
int main() {
  scanf("%d %d %d", &N, &K, &S);
  int i, x, j, k, s;
  for (i = 0; i < maxn; i++)
    for (j = 0; j < maxs; j++) dp[i][j] = 1e9;
  for (i = 1; i < maxs; i++) dp[0][i] = 0;
  for (i = 1; i <= N; i++) {
    scanf("%d", &x);
    for (j = min(i, K); j >= 1; j--) {
      for (s = maxs - 1; s >= i; s--) {
        dp[j][s] = min(dp[j][s], dp[j - 1][s - i] + x);
      }
    }
  }
  printf("%d\n", dp[K][(K * (K + 1)) / 2 + min(S, (N * (N + 1)) / 2)]);
  return 0;
}
