#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
long long dp[maxn][maxn], q;
bool is[maxn][maxn];
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  for (int i = 0; i < s.size(); ++i) {
    is[i][i] = 1;
    dp[i][i] = 1;
  }
  for (int sz = 2; sz < s.size(); ++sz) {
    for (int i = 0; i < s.size() - sz + 1; ++i) {
      int j = i + sz - 1;
      is[i][j] = (s[i] == s[j] && (j - i == 1 || is[i + 1][j - 1]));
      if (j - i == 1)
        dp[i][j] = dp[i][i] + dp[j][j] + is[i][j];
      else
        dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + is[i][j];
    }
  }
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    ;
    x--;
    y--;
    cout << dp[x][y] << '\n';
  }
  return 0;
}
