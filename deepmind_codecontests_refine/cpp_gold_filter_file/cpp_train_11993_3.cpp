#include <bits/stdc++.h>
using namespace std;
long long ans = 1, dp[100005];
int main() {
  int i, n, ok = 1;
  char s[100005];
  cin >> s + 1;
  n = strlen(s + 1);
  i = 1;
  while (i <= n) {
    if (s[i] == 'm' || s[i] == 'w') ok = 0;
    if (s[i] == 'u' || s[i] == 'n') {
      dp[0] = 1;
      dp[1] = 1;
      int nr = 2;
      while (s[i] == s[i + 1]) {
        dp[nr] = (dp[nr - 1] + dp[nr - 2]) % 1000000007;
        nr++;
        i++;
      }
      if (dp[nr - 1] != 0) ans = (ans * dp[nr - 1]) % 1000000007;
    }
    i++;
  }
  if (ok == 0)
    cout << 0;
  else
    cout << ans;
  return 0;
}
