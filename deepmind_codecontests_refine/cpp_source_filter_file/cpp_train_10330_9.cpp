#include <bits/stdc++.h>
using namespace std;
const long long int N = 100001;
const long long int M = 1;
struct point {
  long long int x, y;
  long long int i;
};
long long int fast_exp(long long int x, long long int n) {
  if (n == 0)
    return 1;
  else if (n & 1)
    return fast_exp(x, n - 1) * x % 998244353;
  else {
    long long int tmp = fast_exp(x, n >> 1);
    return tmp * tmp % 998244353;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int _ = 1;
  cin >> _;
  while (_--) {
    long long int n, m, x = 0, y, ans = 0;
    string s, goal;
    cin >> s >> goal;
    n = s.size();
    m = goal.size();
    long long int nxt[n][26];
    for (int i = n - 1; i > -1; i--) {
      if (i != n - 1)
        for (int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
      else
        for (int j = 0; j < 26; j++) nxt[i][j] = n;
      nxt[i][s[i] - 'a'] = i;
    }
    for (int i = 0; i < m; i++) {
      x = i + 1;
      y = m - x;
      long long int dp[x + 1][y + 1];
      for (int j = 0; j <= x; j++)
        for (int k = 0; k <= y; k++) dp[j][j] = n;
      dp[0][0] = -1;
      for (int j = 0; j <= x; j++) {
        for (int k = 0; k <= y; k++) {
          if (j > 0 && dp[j - 1][k] < n)
            dp[j][k] = nxt[dp[j - 1][k] + 1][goal[j - 1] - 'a'];
          if (k > 0 && dp[j][k - 1] < n)
            dp[j][k] =
                min(dp[j][k], nxt[dp[j][k - 1] + 1][goal[x + k - 1] - 'a']);
        }
      }
      if (dp[x][y] < n) ans = 1;
    }
    if (ans)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
