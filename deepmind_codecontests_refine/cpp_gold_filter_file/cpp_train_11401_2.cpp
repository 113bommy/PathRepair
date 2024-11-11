#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = int(1e9);
const int MAX = 100007;
int dp[MAX][3], n;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> s;
  dp[0][1] = dp[0][0] = dp[0][2] = 1;
  for (int i = 1; i < s.size(); i++) {
    dp[i][0] = dp[i - 1][0] + (s[i] != s[i - 1]);
    dp[i][1] = max(dp[i - 1][0] + (s[i] == s[i - 1]),
                   dp[i - 1][1] + (s[i] != s[i - 1]));
    dp[i][2] = max(dp[i - 1][1] + (s[i] == s[i - 1]),
                   dp[i - 1][2] + (s[i] != s[i - 1]));
  }
  cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
  return 0;
}
