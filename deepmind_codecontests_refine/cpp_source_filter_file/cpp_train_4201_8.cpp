#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int dp[MAXN][2];
int main() {
  string s;
  cin >> s;
  dp[0][0] = (s[0] >= 'a' && s[0] <= 'z');
  dp[0][1] = (s[0] >= 'A' && s[0] <= 'z');
  for (int i = 1; i < (int)s.size(); ++i) {
    dp[i][0] = dp[i - 1][0] + (s[i] >= 'a' && s[i] <= 'z');
    dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + (s[i] >= 'A' && s[i] <= 'Z');
  }
  cout << min(dp[s.size() - 1][0], dp[s.size() - 1][1]);
}
