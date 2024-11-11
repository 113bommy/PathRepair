#include <bits/stdc++.h>
using namespace std;
int team[5005];
int pos[5005];
int dp[5005][5005];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> team[i];
  sort(team + 1, team + n + 1);
  int p = 1;
  for (int i = 1; i <= n; i++) {
    int p = lower_bound(team + 1, team + i + 1, team[i] - 5) - team;
    pos[i] = p;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[pos[i] - 1][j - 1] + (i - pos[i] + 1));
    }
  }
  cout << dp[n][k] << '\n';
}
