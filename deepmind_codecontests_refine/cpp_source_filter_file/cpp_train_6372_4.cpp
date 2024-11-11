#include <bits/stdc++.h>
using namespace std;
void In_Out() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long n, k;
  string s;
  char ch;
  set<char> alpha;
  cin >> n >> k;
  cin >> s;
  for (long i = 0; i < k; i++) {
    cin >> ch;
    alpha.insert(ch);
  }
  long dp[n];
  memset(dp, 0, sizeof(dp));
  if (alpha.find(s[0]) != alpha.end()) {
    dp[0] = 1;
  }
  for (long i = 1; i < n; i++) {
    if (alpha.find(s[i]) != alpha.end()) {
      dp[i] = 1 + dp[i - 1];
    }
  }
  for (long i = 1; i < n; i++) dp[i] += dp[i - 1];
  cout << dp[n - 1];
}
