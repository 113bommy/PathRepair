#include <bits/stdc++.h>
using namespace std;
int n;
char ch[105];
long long dp[55][2], ans;
int main() {
  dp[0][0] = 0;
  dp[0][1] = 1;
  for (int i = 1; i < 51; i++)
    dp[i][0] = dp[i - 1][1], dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
  cin >> ch;
  for (n = 0; ch[n]; n++)
    ;
  for (int i = 0; i < n; i++) ch[n + i] = ch[i];
  int s = 0, t, len;
  ans = 1;
  if (ch[0] != ch[n - 1])
    while (ch[s] != ch[s + 1] && s < n - 1) s++;
  while (ans && s < n) {
    t = s;
    while (ch[t] != ch[t + 1] && t - s + 1 < n) t++;
    len = (t - s + 1) >> 1;
    if (t - s + 1 == n && !(n % 2)) {
      ans = max((long long)1, 2 * dp[len - 1][0]) + dp[len - 1][1];
      break;
    }
    if (ch[s] == ch[t])
      ans *= dp[len][1];
    else if (ch[s] == 'B')
      ans *= dp[len][0] + dp[len][1];
    else {
      if (len > 1)
        ans *= dp[len - 2][1];
      else
        ans = 0;
    }
    s = t + 1;
  }
  cout << ans << endl;
  return 0;
}
