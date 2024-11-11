#include <bits/stdc++.h>
using namespace std;
int n, dp[(int)(700 + 10)][(int)(700 + 10)][2], answer, po[(int)(700 + 10)];
string s;
inline void add(int &a, int b) { a = (a + b) % (int)(1e9 + 7); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  po[0] = 1;
  for (int i = 1; i < (int)(700 + 10); i++)
    po[i] = (po[i - 1] * 10) % (int)(1e9 + 7);
  cin >> s;
  n = s.size();
  for (int d = 1; d <= 9; d++) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        add(dp[i + 1][j][1], (1ll * dp[i][j][1] * (d)) % (int)(1e9 + 7));
        add(dp[i + 1][j + 1][1],
            (1ll * dp[i][j][1] * (10 - d)) % (int)(1e9 + 7));
        add(dp[i + 1][j + ((s[i] - '0') >= d)][0], dp[i][j][0]);
        add(dp[i + 1][j][1],
            (1ll * dp[i][j][0] * min(d, s[i] - '0')) % (int)(1e9 + 7));
        add(dp[i + 1][j + 1][1],
            (1ll * dp[i][j][0] * max(0, s[i] - '0' - d)) % (int)(1e9 + 7));
      }
    }
    for (int i = n; i; i--) {
      add(dp[n][i][1], dp[n][i + 1][1] + dp[n][i][0]);
      add(answer, (1ll * po[i - 1] * (dp[n][i][1])) % (int)(1e9 + 7));
    }
  }
  cout << answer << endl;
  return 0;
}
