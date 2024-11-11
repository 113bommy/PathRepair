#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  string tmp = str.substr(5, str.length());
  str = tmp;
  long long n = str.length();
  long long dp[n + 1][2];
  memset(dp, 0, sizeof dp);
  for (long long i = n - 2; i >= 0; i--) {
    if ((i + 2) > n)
      continue;
    else {
      if ((i + 2) == n)
        dp[i][0] = 1;
      else {
        if ((i + 2 + 2) <= n) {
          if ((str[i] != str[i + 2]) || (str[i + 1] != str[i + 3]))
            dp[i][0] = dp[i + 2][0];
        }
        if ((i + 3 + 2) <= n) dp[i][0] = max(dp[i][0], dp[i + 2][1]);
      }
    }
    if ((i + 3) > n)
      continue;
    else {
      if ((i + 3) == n)
        dp[i][1] = 1;
      else {
        if ((i + 3 + 2) <= n) dp[i][1] = dp[i + 3][0];
        if ((i + 3 + 3) <= n) {
          if ((str[i] != str[i + 3]) || (str[i + 1] != str[i + 4]) ||
              (str[i + 2] != str[i + 5]))
            dp[i][1] = max(dp[i][1], dp[i + 3][1]);
        }
      }
    }
  }
  set<string> st;
  string tmp1 = "aa";
  string tmp2 = "aaa";
  for (long long i = 0; i < n; i++) {
    if (dp[i][0]) {
      tmp1[0] = str[i];
      tmp1[1] = str[i + 1];
      st.insert(tmp1);
    }
    if (dp[i][1]) {
      tmp2[0] = str[i];
      tmp2[1] = str[i + 1];
      tmp2[2] = str[i + 2];
      st.insert(tmp2);
    }
  }
  cout << st.size() << "\n";
  for (auto it : st) cout << it << "\n";
  return 0;
}
