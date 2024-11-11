#include <bits/stdc++.h>
using namespace std;
int l[103], r[103];
int dp[2][100004][2];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= k; i++) cin >> l[i] >> r[i];
  int u = 2 * n - r[k];
  for (int j = 0; j <= n; j++) {
    dp[0][j][1] = 1000000007;
    dp[0][j][0] = 1000000007;
  }
  int w1 = max(0, l[1] - 1);
  if (l[1] == 0) {
    if (r[1] == 0) {
      for (int i = 1; i < k; i++) l[i] = l[i + 1], r[i] = r[i + 1];
      k--;
    } else
      l[1] = 1;
  }
  if (w1 > n || k == 0) {
    cout << "Hungry" << '\n';
    return 0;
  }
  dp[0][0][1] = 0;
  r[0] = 0;
  for (int i = 1; i <= k; i++) {
    int r1 = l[i] - r[i - 1] - 1;
    int r2 = r[i] - l[i] + 1;
    int r3 = r2 + r1;
    set<pair<int, int> > s1, s2, s3, s4;
    for (int j = 0; j <= n; j++) {
      dp[1][j][0] = 1000000007;
      dp[1][j][1] = 1000000007;
      s1.insert(make_pair(dp[0][j][0], j));
      if (j - r1 - 1 >= 0)
        s2.insert(make_pair(dp[0][j - r1 - 1][1], j - r1 - 1));
      s4.insert(make_pair(dp[0][j][0], j));
      if (j - r1 - 1 >= 0)
        s3.insert(make_pair(dp[0][j - r1 - 1][1], j - r1 - 1));
      while (!s1.empty()) {
        if (j - s1.begin()->second >= r2) {
          s1.erase(s1.begin());
        } else
          break;
      }
      if (!s1.empty()) dp[1][j][1] = min(dp[1][j][1], s1.begin()->first + 1);
      while (!s2.empty()) {
        if (j - s2.begin()->second > r3) {
          s2.erase(s2.begin());
        } else
          break;
      }
      if (!s2.empty()) dp[1][j][1] = min(dp[1][j][1], s2.begin()->first + 2);
      if (j - r3 >= 0) dp[1][j][1] = min(dp[1][j][1], dp[0][j - r3][1]);
      while (!s3.empty()) {
        if (j - s3.begin()->second > r3) {
          s3.erase(s3.begin());
        } else
          break;
      }
      if (!s3.empty()) dp[1][j][0] = min(dp[1][j][0], s3.begin()->first + 1);
      while (!s4.empty()) {
        if (j - s4.begin()->second > r2 - 1) {
          s4.erase(s4.begin());
        } else
          break;
      }
      if (!s4.empty()) dp[1][j][0] = min(dp[1][j][0], s4.begin()->first + 2);
      dp[1][j][0] = min(dp[1][j][0], dp[0][j][0]);
    }
    for (int j = 0; j <= n; j++) {
      dp[0][j][1] = dp[1][j][1];
      dp[0][j][0] = dp[1][j][0];
    }
  }
  if (u > n) {
    cout << "Hungry";
    return 0;
  }
  int w = min(dp[1][n][0], dp[1][n - u][1]);
  if (w == 1000000007) {
    cout << "Hungry";
    return 0;
  }
  cout << "Full" << '\n';
  cout << w << '\n';
}
