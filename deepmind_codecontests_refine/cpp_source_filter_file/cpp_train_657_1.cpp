#include <bits/stdc++.h>
using namespace std;
int dp[27][27];
char s[1222];
int n;
int ans;
int main() {
  cin >> n;
  while (n--) {
    cin >> s;
    int l = strlen(s);
    int a = s[0] - 'a', b = s[l - 1] - 'a';
    for (int i = 0; i < 26; i++)
      if (dp[i][a]) dp[i][a] = max(dp[i][a], dp[i][b] + l);
    dp[a][b] = max(dp[a][b], l);
    ans = max(ans, dp[b][b]);
  }
  cout << ans << endl;
  return 0;
}
