#include <bits/stdc++.h>
using namespace std;
long long dp[(int)1e+7], ans[(int)1e+7];
int main() {
  string s;
  cin >> s;
  long long l = s.size();
  ans[0] = ans[1] = (long long)1;
  for (long long i = 0; i < l; i++) {
    if (i == 0)
      dp[i + 1] = (s[0] == '9') ? 1 : 0;
    else {
      if (s[i] == '9') {
        dp[i + 1] = dp[i] + 1;
        ans[i + 1] = ans[i];
      } else {
        int a = s[i] - '0', b = s[i - 1] - '0';
        if (a + b == 9) {
          dp[i + 1] = max(dp[i], dp[i - 1] + 1);
          if (dp[i + 1] > dp[i])
            ans[i + 1] = ans[i - 1];
          else if (dp[i + 1] > dp[i - 1] + 1)
            ans[i + 1] = ans[i];
          else
            ans[i + 1] = ans[i - 1] + ans[i];
        } else {
          dp[i + 1] = dp[i];
          ans[i + 1] = ans[i];
        }
      }
    }
  }
  cout << ans[l] << endl;
  return 0;
}
