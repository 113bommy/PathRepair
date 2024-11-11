#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6 + 10;
int total;
int saveori[3][maxn];
long long dp[3][maxn];
void solve() {
  int oriplace = 0;
  if (saveori[0][1]) oriplace = 0;
  if (saveori[1][1]) oriplace = 1;
  if (saveori[2][1]) oriplace = 2;
  dp[0][1] = dp[1][1] = dp[2][1] = 1;
  dp[oriplace][1]--;
  for (int i = 2; i <= total; i++) {
    if (saveori[0][i]) oriplace = 0;
    if (saveori[1][i]) oriplace = 1;
    if (saveori[2][i]) oriplace = 2;
    dp[0][i] = dp[0][i - 1] + 1;
    dp[1][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 1);
    dp[2][i] = min(dp[1][i - 1] + 1, min(dp[0][i - 1] + 1, dp[2][i - 1] + 1));
    dp[oriplace][i]--;
  }
}
int c[3];
int main() {
  scanf("%d %d %d", &c[0], &c[1], &c[2]);
  total = c[0] + c[1] + c[2];
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < c[j]; i++) {
      int num;
      scanf("%d", &num);
      saveori[j][num] = 1;
    }
  }
  solve();
  long long res = dp[0][total];
  res = min(res, dp[1][total]);
  res = min(res, dp[2][total]);
  cout << res << endl;
}
