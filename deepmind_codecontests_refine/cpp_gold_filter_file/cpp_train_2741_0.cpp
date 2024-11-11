#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
char s[5005], t[5005];
int main() {
  int i, j, ret = 0;
  cin >> s >> t;
  for (i = 0; s[i]; ++i) {
    for (j = 0; t[j]; ++j) {
      dp[i + 1][j + 1] =
          (dp[i + 1][j] + (s[i] == t[j]) * (dp[i][j] + 1)) % ((int)1e9 + 7);
    }
  }
  for (i = 0; s[i]; ++i) {
    ret = (ret + dp[i + 1][j]) % ((int)1e9 + 7);
  }
  cout << ret << endl;
  return 0;
}
