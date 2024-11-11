#include <bits/stdc++.h>
using namespace std;
const int MAXn = 150 + 10, MAXs = MAXn * MAXn, INF = 1e9 + 7;
int dp[2][MAXs][MAXn], n, k, s, ar[MAXn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  s = min(s, MAXs - 3);
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) cin >> ar[i];
  bool flag = false;
  for (int i = 0; i < MAXs; i++)
    for (int j = 0; j < MAXn; j++) dp[0][i][j] = dp[1][i][j] = INF;
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    flag = !flag;
    for (int x = 0; x < MAXs; x++)
      for (int z = 0; z < min(i + 1, k); z++)
        if (dp[!flag][x][z] != INF && x + i - z < MAXs)
          dp[flag][x + i - z][z + 1] = dp[!flag][x][z] + ar[i];
    for (int x = 0; x < MAXs; x++)
      for (int z = 0; z < MAXn; z++)
        dp[flag][x][z] = min(dp[flag][x][z], dp[!flag][x][z]);
  }
  int ans = INF;
  for (int i = 0; i <= s; i++) {
    if (i >= MAXs) break;
    ans = min(ans, dp[flag][i][k]);
  }
  cout << ans;
}
