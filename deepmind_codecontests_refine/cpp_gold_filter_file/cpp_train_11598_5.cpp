#include <bits/stdc++.h>
using namespace std;
bool dp[100];
bool isMagicNumber(const string& s) {
  memset(dp, false, sizeof(dp));
  int n = s.length();
  dp[0] = true;
  for (int i = 1; i <= n; i++) {
    dp[i] = (dp[i - 1] && (s[i - 1] == '1')) ||
            (i >= 2 && dp[i - 2] && s[i - 2] == '1' && s[i - 1] == '4') ||
            (i >= 3 && dp[i - 3] && s[i - 3] == '1' && s[i - 2] == '4' &&
             s[i - 1] == '4');
  }
  return dp[n];
}
void solve(const string& s) {
  if (isMagicNumber(s)) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return;
}
int main() {
  string s;
  cin >> s;
  solve(s);
  return 0;
}
