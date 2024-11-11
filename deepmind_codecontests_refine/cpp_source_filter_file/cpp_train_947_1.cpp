#include <bits/stdc++.h>
using namespace std;
int dp[3][2000][3];
int pre[2000][3];
int MOD = 998244353;
int n;
int a[200010];
void Build() {
  memset(pre, 0, sizeof(pre));
  for (int i = 1; i <= 200; i++) {
    pre[i][0] = (dp[0][i][0] + pre[i - 1][0]) % MOD;
    pre[i][1] = (dp[0][i][1] + pre[i - 1][1]) % MOD;
  }
  return;
}
int Query(int st, int en, int type) {
  if (st == 0 || st > en) return 0;
  return ((pre[en][type] - pre[st - 1][type]) % MOD);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  if (a[1] == -1) {
    for (int i = 1; i <= 200; i++) dp[0][i][1] = 1;
  } else
    dp[0][a[1]][1] = 1;
  Build();
  for (int i = 2; i <= n; i++) {
    if (a[i] == -1) {
      for (int j = 1; j <= 200; j++) {
        dp[1][j][0] = (Query(j, 200, 0) + dp[1][j][0]) % MOD;
        dp[1][j][1] = (Query(1, j - 1, 1) + dp[1][j][1]) % MOD;
        dp[1][j][1] = (Query(1, j - 1, 0) + dp[1][j][1]) % MOD;
        dp[1][j][0] = (dp[1][j][0] + dp[0][j][1]) % MOD;
      }
    } else {
      dp[1][a[i]][0] = (Query(a[i], 200, 0) + dp[1][a[i]][0]) % MOD;
      dp[1][a[i]][1] = (Query(1, a[i] - 1, 1) + dp[1][a[i]][1]) % MOD;
      dp[1][a[i]][1] = (Query(1, a[i] - 1, 0) + dp[1][a[i]][1]) % MOD;
      dp[1][a[i]][0] = (dp[1][a[i]][0] + dp[0][a[i]][1]) % MOD;
    }
    for (int j = 1; j <= 200; j++) {
      dp[0][j][0] = dp[1][j][0];
      dp[0][j][1] = dp[1][j][1];
    }
    memset(dp[1], 0, sizeof(dp[1]));
    Build();
  }
  cout << Query(1, 200, 0) << endl;
  return 0;
}
