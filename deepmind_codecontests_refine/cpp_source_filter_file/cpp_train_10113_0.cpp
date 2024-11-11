#include <bits/stdc++.h>
using namespace std;
char c[5005];
int dp[5005];
int lcs[5005][5005];
int main() {
  ios::sync_with_stdio(false);
  int n, a, b;
  cin >> n >> a >> b;
  cin >> c + 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + a;
    for (int j = 1; j < i; j++) {
      if (c[i] == c[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
      if (lcs[i][j] != 0 && i - j >= lcs[i][j]) {
        dp[i] = min(dp[i], dp[i - j] + b);
      }
    }
  }
  cout << dp[n] << endl;
}
