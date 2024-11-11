#include <bits/stdc++.h>
using namespace std;
const int MAXN = 41;
long long dp[MAXN][3][3], t[3][3];
inline long long smin(long long &a, long long b) { return a = min(a, b); }
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  memset(dp, 63, sizeof dp);
  memset(dp[0], 0, sizeof dp[0]);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) cin >> t[i][j];
  int n;
  cin >> n;
  for (int s = 1; s <= n; s++) {
    for (int i = 0; i < 3; i++) {
      dp[s][i][i] = 0;
      int a = (i + 1) % 3, b = (i + 2) % 3;
      for (int j = 0; j < 2; j++) {
        smin(dp[s][i][a], dp[s - 1][i][b] + t[i][a] + dp[s - 1][b][a]);
        smin(dp[s][i][a], dp[s - 1][i][a] + t[i][b] + dp[s - 1][a][i] +
                              t[b][a] + dp[s - 1][i][a]);
        swap(a, b);
      }
    }
  }
  cout << dp[n][0][2];
}
