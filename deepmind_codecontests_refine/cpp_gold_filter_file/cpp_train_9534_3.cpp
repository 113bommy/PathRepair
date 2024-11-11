#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
const long long inf64 = (long long)inf * inf;
string x;
int dp[20][2];
string ans[20][2];
int main() {
  while (cin >> x) {
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 2; j++) {
        dp[i][j] = -inf;
        ans[i][j] = "";
      }
    }
    dp[0][0] = 0;
    for (int i = 0; i < x.size(); i++) {
      int num = x[i] - '0';
      dp[i + 1][0] = dp[i][0] + num;
      ans[i + 1][0] = ans[i][0] + (char)(num + '0');
      if (dp[i][1] >= 0) {
        dp[i + 1][1] = dp[i][1] + 9;
        ans[i + 1][1] = ans[i][1] + '9';
      }
      if (num > 0) {
        if (dp[i][0] + num - 1 >= dp[i + 1][1]) {
          dp[i + 1][1] = dp[i][0] + num - 1;
          ans[i + 1][1] = ans[i][0] + (char)(num - 1 + '0');
        }
      }
    }
    int n = x.size();
    if (dp[n][0] >= dp[n][1])
      cout << ans[n][0] << endl;
    else {
      long long num = 0;
      for (int i = 0; i < ans[n][1].size(); i++) {
        num = num * 10 + (ans[n][1][i] - '0');
      }
      cout << num << endl;
    }
  }
  return 0;
}
