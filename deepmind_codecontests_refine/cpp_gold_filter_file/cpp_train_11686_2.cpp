#include <bits/stdc++.h>
using namespace std;
template <typename G>
struct triple {
  G first, second, T;
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> sa(26, vector<int>(n + 2));
    vector<vector<int>> sb(26, vector<int>(n + 2));
    for (int i = n; i >= 0; i--) {
      if (i > 0) {
        sa[a[i - 1] - 'a'][i] = 1;
        sb[b[i - 1] - 'a'][i] = 1;
      }
      for (int j = 0; j < 26; j++) {
        sa[j][i] += sa[j][i + 1];
        sb[j][i] += sb[j][i + 1];
      }
    }
    bool ok = true;
    for (int i = 0; i < 26; i++) ok &= (sa[i][0] == sb[i][0]);
    if (!ok) {
      cout << "-1\n";
      continue;
    }
    const int oo = 1e8;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, oo));
    dp[0][0] = 0;
    for (int j = 1; j <= n; j++)
      for (int i = 0; i <= j; i++) {
        if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        if (i < j && sa[b[j - 1] - 'a'][i + 1] >= sb[b[j - 1] - 'a'][j])
          dp[i][j] = min(dp[i][j], dp[i][j - 1]);
        if (i > 0 && a[i - 1] == b[j - 1])
          dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
      }
    cout << dp[n][n] << '\n';
  }
  return 0;
}
