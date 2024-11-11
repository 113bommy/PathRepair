#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main() {
  int dp[4] = {0};
  string s;
  cin >> s;
  int len = s.length();
  int cnt = 0, sum = 0, ans = 0;
  for (int i = 0; i < len; i++) {
    dp[cnt++] = s[i] - '0';
    sum += dp[cnt - 1];
    if (sum % 3 == 0 || dp[cnt - 1] % 3 == 0 || cnt >= 3) {
      cnt = 0;
      ans++;
      sum = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
