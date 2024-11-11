#include <bits/stdc++.h>
using namespace std;
int n, m, a[102][102], k;
pair<long long, int> dp[102][102][12];
int main() {
  cin >> n >> m >> k;
  k++;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] - '0';
      for (int t = 0; t < k; t++) dp[i][j][t] = make_pair(-1, -1);
    }
  }
  for (int i = 0; i < m; i++)
    dp[n - 1][i][a[n - 1][i] % k] = make_pair(a[n - 1][i], 0);
  for (int i = n - 2; i >= 0; i--)
    for (int j = 0; j < m; j++)
      for (int t = 0; t < k; t++) {
        if (j && dp[i + 1][j - 1][(5 * k + t - a[i][j] % k) % k].first != -1)
          dp[i][j][t] = make_pair(
              a[i][j] + dp[i + 1][j - 1][(5 * k + t - a[i][j]) % k].first, -1);
        if (j != m - 1 &&
            dp[i + 1][j + 1][(5 * k + t - a[i][j] % k) % k].first != -1)
          dp[i][j][t] = max(
              make_pair(
                  a[i][j] + dp[i + 1][j + 1][(5 * k + t - a[i][j]) % k].first,
                  1),
              dp[i][j][t]);
      }
  int d = 0;
  for (int i = 0; i < m; i++)
    if (dp[0][i][0].first > dp[0][d][0].first) d = i;
  cout << dp[0][d][0].first << endl;
  if (dp[0][d][0].first != -1) {
    string p;
    int mn = 0;
    for (int i = 0; i < n; i++) {
      int D = dp[i][d][mn].second;
      if (D == 1)
        p += 'L';
      else if (D == -1)
        p += 'R';
      mn = (mn - a[i][d] % k + 5 * k) % k;
      d += D;
    }
    cout << d + 1 << endl;
    reverse(p.begin(), p.end());
    cout << p << endl;
  }
  return 0;
}
