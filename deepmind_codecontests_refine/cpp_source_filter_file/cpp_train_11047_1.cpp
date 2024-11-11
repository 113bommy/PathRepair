#include <bits/stdc++.h>
using namespace std;
int n, m, c, d;
int aa[10007];
int bb[10007];
int cc[10007];
int dd[10007];
int dp[1057][1057];
int solve(int r, int s) {
  if (s > m || r < 0) {
    return 0;
  }
  if (dp[r][s] != -1) {
    return dp[r][s];
  }
  dp[r][s] = 0;
  if (s == 0) {
    for (int y = 0; y <= 100; y++) {
      if ((r - (c * y)) >= 0)
        dp[r][s] = max(dp[r][s], solve(r - (c * y), s + 1) + d * y);
    }
  } else
    for (int y = 0; y <= 100; y++) {
      if ((r - (cc[s] * y)) >= 0)
        if (aa[s] - (bb[s] * y) >= 0)
          dp[r][s] = max(dp[r][s], solve(r - (cc[s] * y), s + 1) + dd[s] * y);
    }
  return dp[r][s];
}
int main() {
  cin >> n >> m >> c >> d;
  for (int i = 0; i <= n + 7; i++) {
    for (int j = 0; j <= m + 7; j++) {
      dp[i][j] = -1;
    }
  }
  for (int i = 1; i <= m; i++) {
    cin >> aa[i];
    cin >> bb[i];
    cin >> cc[i];
    cin >> dd[i];
  }
  cout << solve(n, 0) << endl;
}
