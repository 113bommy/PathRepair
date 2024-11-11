#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<int>> dp(2, vector<int>(n, -2));
  vector<vector<int>> res(2, vector<int>(n, -2));
  dp[0][0] = 1000000;
  dp[1][0] = -1;
  for (int i = 0; i < n - 1; i++) {
    if (dp[0][i] != -2 && a[i] < a[i + 1]) {
      dp[0][i + 1] = dp[0][i];
      res[0][i + 1] = 0;
    }
    if (dp[0][i] != -2 && a[i + 1] < dp[0][i]) {
      dp[1][i + 1] = a[i];
      res[1][i + 1] = 0;
    }
    if (dp[1][i] != -2 && a[i + 1] > dp[1][i] &&
        (dp[0][i + 1] == -2 || a[i] > dp[0][i + 1])) {
      dp[0][i + 1] = a[i];
      res[0][i + 1] = 1;
    }
    if (dp[1][i] != -2 && a[i] > a[i + 1] &&
        (dp[1][i + 1] == -2 || a[i] < dp[1][i + 1])) {
      dp[1][i + 1] = dp[1][i];
      res[1][i + 1] = 1;
    }
  }
  int s = -1;
  for (int j = 0; j < 2; j++)
    if (dp[j][n - 1] != -2) s = j;
  if (s == -1) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES\n";
  int cur = s;
  vector<int> r(n);
  for (int i = n - 1; i >= 0; --i) {
    r[i] = cur;
    cur = res[cur][i];
  }
  for (const auto &c : r) cout << c << " ";
  cout << endl;
}
