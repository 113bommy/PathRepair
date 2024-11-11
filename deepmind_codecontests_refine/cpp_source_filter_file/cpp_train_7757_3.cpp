#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long dp[2009][2009];
string s;
void T() {
  dp[0][0] = 1;
  for (long long i = 1; i < 2009; i++) {
    for (long long j = 0; j <= i; j++) {
      if (j < i) dp[i][j] = dp[i - 1][j + 1];
      if (j > 0) dp[i][j] += dp[i - 1][j - 1];
      dp[i][j] %= 1000000009LL;
    }
  }
  long long bal = 0, minbal = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      bal++;
    else
      bal--;
    minbal = min(minbal, bal);
  }
  minbal *= -1;
  long long tot = 0;
  for (long long i = 0; i <= n - m; i++) {
    for (long long j = minbal; j <= i; j++) {
      long long qlen = n - m - i;
      long long qbal = j + bal;
      if (qbal <= qlen) {
        tot =
            (tot + ((dp[i][j] * dp[qlen][qbal]) % 1000000009LL)) % 1000000009LL;
      }
    }
  }
  cout << tot << endl;
}
int main(void) {
  cin >> n >> m;
  memset(dp, 0, sizeof dp);
  cin >> s;
  T();
}
