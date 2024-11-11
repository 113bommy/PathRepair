#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
const int N = 1000005;
char s[N];
int dp[N][2];
int one_cnts[N];
int main() {
  while (cin >> (s + 1)) {
    int len = strlen(s + 1);
    dp[0][0] = 0;
    dp[0][1] = 2;
    for (int i = 1; i <= len; ++i) {
      if (s[i] == '0') {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 2);
        dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
      } else {
        dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 2);
      }
    }
    cout << min(dp[len][0], dp[len][1] + 2) << endl;
  }
  return 0;
}
