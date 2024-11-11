#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
const long long MOD = 1000003;
char s[N];
long long dp[N + N];
int main() {
  cin >> s;
  int n = strlen(s), tot = 0;
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*' || s[i] == '/')
      if (i - 1 >= 0 && s[i - 1] < '0') return puts("0"), 0;
    if (s[i] < '0') {
      for (int j = ++tot; j; --j) dp[j] = dp[j - 1];
      dp[0] = 0;
    } else {
      for (int j = tot; j >= 0; --j) dp[j - 1] = (dp[j - 1] + dp[j]) % MOD;
      while (s[i] >= '0') i++;
      i--;
    }
  }
  cout << dp[0] << endl;
  return 0;
}
