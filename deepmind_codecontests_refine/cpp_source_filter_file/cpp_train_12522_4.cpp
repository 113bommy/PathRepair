#include <bits/stdc++.h>
using namespace std;
int dp[5010][5010];
string a, b;
int n, m;
void lcs() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (a[i - 1] == b[j - 1])
        dp[i][j] = max(0, dp[i - 1][j - 1] + 4 - 2);
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cin >> n >> m;
  cin >> a >> b;
  lcs();
  int resp = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      resp = max(dp[i][j], resp);
    }
  }
  cout << resp << "\n";
}
