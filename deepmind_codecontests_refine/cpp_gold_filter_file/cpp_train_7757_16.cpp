#include <bits/stdc++.h>
using namespace std;
long long dp[2001][2001], n, m, ans;
string s;
void precompute() {
  dp[0][0] = 1;
  for (int i = 1; i < 2001; i++) {
    dp[i][0] = dp[i - 1][1];
    for (int j = 1; j <= i; j++) {
      dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % 1000000007;
    }
  }
}
int main() {
  int opreq = 0, clreq = 0;
  precompute();
  cin >> n >> m >> s;
  for (int i = 0; i < m; i++) {
    if (s[i] == '(')
      clreq++;
    else if (s[i] == ')' && clreq == 0)
      opreq++;
    else
      clreq--;
  }
  for (int i = 0; i <= n - m; i++)
    for (int j = opreq; j <= i; j++) {
      if (n - m - i >= j + clreq - opreq) {
        ans += (dp[i][j] * dp[n - m - i][j + clreq - opreq]) % 1000000007;
        ans %= 1000000007;
      }
    }
  cout << ans << endl;
  return 0;
}
