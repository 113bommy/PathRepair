#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000006;
char s[maxn], n;
void read() {
  scanf("%s", s);
  n = strlen(s);
}
int dp[maxn][2];
void solve() {
  dp[0][0] = 0;
  dp[0][1] = 2;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      dp[i + 1][0] = min(dp[i][0] + 1, dp[i][1]);
      dp[i + 1][1] = min(dp[i][0] + 2, dp[i][1]);
    } else {
      dp[i + 1][0] = min(dp[i][0], dp[i][1]);
      dp[i + 1][1] = min(dp[i][0] + 2, dp[i][1] + 1);
    }
  }
  cout << min(dp[n][0], dp[n][1]) << endl;
  ;
}
int main() {
  read();
  solve();
  return 0;
}
