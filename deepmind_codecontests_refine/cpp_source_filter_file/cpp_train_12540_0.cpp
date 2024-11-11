#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
string s, p;
int dp[2001][2001];
int can[2001];
int Next[2001][26];
int calc(int i, int k) {
  if (i == s.size()) {
    if (k) return -(1 << 29);
    return 0;
  }
  if (dp[i][k] == -1) {
    dp[i][k] = calc(i + 1, k);
    if (k) dp[i][k] = max(dp[i][k], calc(i + 1, k - 1));
    if (can[i] != -1 && can[i] - i - (signed)p.size() <= k)
      dp[i][k] =
          max(dp[i][k], 1 + calc(can[i], k - (can[i] - i - (signed)p.size())));
  }
  return dp[i][k];
}
int main() {
  cin >> s >> p;
  memset(Next, -1, sizeof(Next));
  for (int i = s.size() - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) Next[i][j] = Next[i + 1][j];
    ;
    Next[i][s[i] - 'a'] = i;
  }
  memset(can, -1, sizeof(can));
  for (int i = 0; i + p.size() <= s.size(); ++i) {
    int cur = i;
    for (int j = 0; j < p.size(); ++j) {
      if (Next[cur][p[j] - 'a'] == -1) {
        cur = -2;
        break;
      }
      cur = Next[cur][p[j] - 'a'];
    }
    if (cur != -2) can[i] = cur + 1;
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i <= s.size(); ++i) printf("%d ", calc(0, i));
  return 0;
}
