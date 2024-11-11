#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) { return a > b ? b : a; }
int main() {
  ios::sync_with_stdio(false);
  long long n;
  string s;
  long long dp[100];
  cin >> n;
  cin >> s;
  int len = s.length();
  long long sum = 0ll;
  dp[len] = 0;
  for (int i = 0; i <= len; ++i) dp[i] = 1e18;
  for (int i = 0; i < len; ++i) {
    sum = sum * 10 + s[i] - '0';
    if (sum >= n) break;
    dp[i] = sum;
  }
  for (int i = 1; i < len; ++i) {
    sum = 0ll;
    for (int j = i; j < len; ++j) {
      sum = sum * 10 + s[j] - '0';
      if (sum >= n) break;
      if (s[i] == '0' && j > i) break;
      if (dp[i - 1] * 1.0 + sum >= 1e18) continue;
      dp[j] = min(dp[j], dp[i - 1] * n + sum);
    }
  }
  cout << dp[len - 1] << endl;
  return 0;
}
