#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, p;
  cin >> s >> p;
  int n = s.size(), l = p.size();
  if (n < l) {
    cout << 0 << endl;
    return 0;
  }
  int m = n / l + 1;
  int dp[n + 1][m];
  int inf = 100000000;
  fill_n(dp[0], (n + 1) * m, inf);
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = n - l; i >= 0; i--) {
    if (s[i] == p[0]) {
      int index = i;
      int rem = 0;
      for (int j = 0; j < l; j++) {
        while (index < n && s[index] != p[j]) {
          index++;
          rem++;
        }
        index++;
        if (index > n) break;
      }
      if (index > n) continue;
      for (int j = 1; j < m; j++)
        dp[i][j] = min(dp[i + 1][j], rem + dp[index][j - 1]);
    } else {
      for (int j = 0; j < m; j++) {
        dp[i][j] = dp[i + 1][j];
      }
    }
  }
  vector<int> res(n + 1, 0);
  for (int k = 1; k < m; k++) {
    int mini = inf;
    for (int i = 0; i < n; i++) {
      mini = min(mini, dp[i][k]);
    }
    for (int i = mini; i <= n - k * l; i++) res[i] = k;
  }
  cout << res[0];
  for (int i = 1; i <= n; i++) cout << " " << res[i];
  cout << endl;
}
