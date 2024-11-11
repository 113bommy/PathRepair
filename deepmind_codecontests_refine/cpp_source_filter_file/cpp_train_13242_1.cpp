#include <bits/stdc++.h>
using namespace std;
long long dp[2000 + 5][2000 + 5];
long long ques[2000 + 5];
long long mod = 998244353;
long long poww(long long a, long long b) {
  long long tmp = 1;
  while (b) {
    if (b & 1) tmp = (tmp * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return tmp;
}
int main(void) {
  string str;
  cin >> str;
  str = " " + str;
  int n = str.size() - 1;
  for (int i = 1; i <= n; i++) {
    ques[i] = ques[i - 1] + (str[i] == '?');
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      if (str[i] != '(') dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
      if (str[j] != ')') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
      if (str[i] != '(' && str[j] != ')')
        dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % mod;
      if (str[i] != ')' && str[j] != '(') {
        dp[i][j] = ((dp[i][j] + dp[i + 1][j - 1]) % mod +
                    poww(2, ques[j - 1] - ques[i])) %
                   mod;
      }
    }
  }
  cout << dp[1][n] << '\n';
  return 0;
}
