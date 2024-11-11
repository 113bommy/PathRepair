#include <bits/stdc++.h>
using namespace std;
string a[534567];
int dp[30][30];
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (dp[j][a[i][0] - 'a'])
        dp[j][a[i][a[i].size() - 1] - 'a'] =
            max(dp[j][a[i][a[i].size() - 1] - 'a'],
                dp[j][a[i][0] - 'a'] + int(a[i].size()));
    }
    dp[a[i][0] - 'a'][a[i][a[i].size() - 1] - 'a'] =
        max(dp[a[i][0] - 'a'][a[i][a[i].size() - 1]], int(a[i].size()));
  }
  for (int i = 0; i < n; ++i) {
    result = max(result, dp[i][i]);
  }
  cout << result;
  return 0;
}
