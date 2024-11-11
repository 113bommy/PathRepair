#include <bits/stdc++.h>
using namespace std;
const int inf(1010101010);
const int T(86400);
int n, k, start[4005], le[4005];
int dp[4005][4005];
int main() {
  cin >> n >> k;
  for (int i(0); i < (n); i++) cin >> start[i] >> le[i];
  for (int i(0); i < (n + 1); i++)
    for (int j(0); j < (n + 1); j++) dp[i][j] = inf;
  dp[0][0] = 0;
  for (int i(0); i < (n); i++) {
    dp[i + 1][0] = 0;
    for (int j(1); j <= (n); j++) {
      dp[i + 1][j] = min(dp[i][j], max(dp[i][j - 1] + 1, start[i]) + le[i] - 1);
    }
  }
  int mx(0);
  for (int tasks_L(0); tasks_L <= (n); tasks_L++) {
    for (int doen(0); doen <= (tasks_L); doen++)
      if (tasks_L - doen <= k) {
        int fin_L(dp[tasks_L][doen]);
        int tasks_R(n - tasks_L);
        int start_R(tasks_R == 0 ? T + 1 : start[n - tasks_R]);
        mx = max(mx, start_R - fin_L - 1);
      }
  }
  cout << mx << endl;
}
