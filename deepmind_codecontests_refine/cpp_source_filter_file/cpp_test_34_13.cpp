#include <bits/stdc++.h>
using namespace std;
int a[(1 << 20)];
int dp[2][(1 << 14)];
int ans[(1 << 14)];
vector<int> val[(1 << 14)];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    val[a[i]].push_back(i);
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < (1 << 13); j++) {
      dp[i][j] = n;
    }
  }
  for (int i = 0; i < (1 << 13); i++) ans[i] = 0;
  dp[0][0] = -1;
  for (int i = 0; i < 5001; i++) {
    for (int j = 0; j < (1 << 14); j++) {
      dp[i & 1 ^ 1][j] = dp[i & 1][j];
      if (dp[i & 1][j] != n) {
        ans[j] = 1;
      }
    }
    for (int j = 0; j < (1 << 14); j++) {
      int pos = lower_bound(val[i].begin(), val[i].end(), dp[i & 1][j]) -
                val[i].begin();
      dp[i & 1 ^ 1][j ^ i] =
          min(dp[i & 1 ^ 1][j ^ i], (pos >= val[i].size() ? n : val[i][pos]));
    }
  }
  int sz = 0;
  for (int i = 0; i < (1 << 14); i++)
    if (ans[i] == 1) sz++;
  cout << sz << '\n';
  for (int i = 0; i < (1 << 14); i++)
    if (ans[i]) cout << i << ' ';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
