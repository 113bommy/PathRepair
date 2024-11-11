#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 1000 + 100, modd = 1000 * 1000 * 1000 + 7;
int N, M, dp[maxn][2];
int main() {
  for (; scanf("%d%d", &N, &M) != EOF;) {
    dp[1][0] = M;
    dp[1][1] = M;
    int tt = 0;
    for (int i = (2), _i = (N); i <= _i; i++) {
      dp[i][0] = (long long)M * (dp[i - 1][0] + dp[i - 1][1]) % modd;
      dp[i][1] = (long long)(M - 1) *
                 ((long long)dp[i - 1][0] + dp[i - 1][1] - tt + modd) % modd;
      dp[i][1] = (dp[i][1] + dp[i - 1][1]) % modd;
      tt = ((long long)tt * (M - 1) + dp[i - 1][1]) % modd;
    }
    int ans = (dp[N][0] + dp[N][1]) % modd;
    printf("%d\n", ans);
  }
  return 0;
}
