#include <bits/stdc++.h>
using namespace std;
int n, q;
string s;
int dp[1505][1505][27], ans[1505][27];
int num;
char ch;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s >> q;
  for (int x = 0; x < 26; ++x)
    for (int i = 1; i <= n; ++i)
      for (int j = i; j <= n; ++j) {
        dp[i][j][x] = dp[i][j - 1][x] + (s[j - 1] != x + 'a');
        ans[dp[i][j][x]][x] = max(ans[dp[i][j][x]][x], j - i + 1);
      }
  for (int i = 1; i <= n; ++i)
    for (int x = 0; x < 26; ++x) ans[i][x] = max(ans[i][x], ans[i - 1][x]);
  char ch;
  while (q--) {
    cin >> n >> ch;
    cout << ans[n][ch - 'a'] << endl;
  }
  return 0;
}
