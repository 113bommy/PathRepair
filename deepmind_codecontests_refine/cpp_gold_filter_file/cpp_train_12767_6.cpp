#include <bits/stdc++.h>
using namespace std;
int n;
string dp[4][(1 << 8)];
bool cmp(const string &a, const string &b) {
  if (a == "") return 1;
  return a.length() == b.length() ? a > b : a.length() > b.length();
}
int main() {
  dp[3][240] = "x";
  dp[3][204] = "y";
  dp[3][170] = "z";
  while (1) {
    bool f = 0;
    for (int i = 0; i < (1 << 8); i++) {
      if (dp[1][i] != "" && cmp(dp[3][i], "(" + dp[1][i] + ")")) {
        dp[3][i] = "(" + dp[1][i] + ")";
        f = 1;
      }
      if (dp[3][i] != "" && cmp(dp[3][i ^ (1 << 8) - 1], "!" + dp[3][i])) {
        dp[3][i ^ ((1 << 8) - 1)] = "!" + dp[3][i];
        f = 1;
      }
    }
    for (int i = 0; i < (1 << 8); i++) {
      if (cmp(dp[2][i], dp[3][i]) && dp[3][i] != "") {
        dp[2][i] = dp[3][i];
        f = 1;
      }
      for (int j = 0; j < (1 << 8); j++) {
        if (cmp(dp[2][i & j], dp[2][i] + "&" + dp[2][j]) && dp[2][i] != "" &&
            dp[2][j] != "") {
          dp[2][i & j] = dp[2][i] + "&" + dp[2][j];
          f = 1;
        }
      }
    }
    for (int i = 0; i < (1 << 8); i++) {
      if (cmp(dp[1][i], dp[2][i]) && dp[2][i] != "") {
        dp[1][i] = dp[2][i];
        f = 1;
      }
      for (int j = 0; j < (1 << 8); j++) {
        if (cmp(dp[1][i | j], dp[1][i] + "|" + dp[1][j]) && dp[1][i] != "" &&
            dp[1][j] != "") {
          dp[1][i | j] = dp[1][i] + "|" + dp[1][j];
          f = 1;
        }
      }
    }
    if (f == 0) break;
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string a;
    int now = 0;
    cin >> a;
    for (int j = 7; j >= 0; j--) now = (now << 1) + a[j] - '0';
    cout << dp[1][now] << endl;
  }
  return 0;
}
