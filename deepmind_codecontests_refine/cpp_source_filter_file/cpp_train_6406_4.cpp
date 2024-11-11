#include <bits/stdc++.h>
using namespace std;
int n;
int dp[10005][4];
string str;
set<string> se;
set<string>::iterator it;
int cnt(int i, int len) {
  int j, k;
  if (len == 2) {
    if (i > n - 2) return 0;
    if (i == n - 2) return 1;
    if (dp[i][len] != -1) return dp[i][len];
    if (i <= n - 4) {
      if (str[i] == str[i + 2] && str[i + 1] == str[i + 3])
        dp[i][len] = cnt(i + 2, 3);
      else
        dp[i][len] = (cnt(i + 2, 2) | cnt(i + 2, 3));
    } else
      dp[i][len] = (cnt(i + 2, 2) | cnt(i + 2, 3));
    return dp[i][len];
  } else {
    if (i > n - 3) return 0;
    if (i == n - 3) return 1;
    if (dp[i][len] != -1) return dp[i][len];
    if (i <= n - 6) {
      if (str[i] == str[i + 3] && str[i + 1] == str[i + 4] &&
          str[i + 2] == str[i + 5])
        dp[i][len] = cnt(i + 2, 2);
      else
        dp[i][len] = (cnt(i + 2, 2) | cnt(i + 2, 3));
    } else
      dp[i][len] = (cnt(i + 3, 2) | cnt(i + 3, 3));
    return dp[i][len];
  }
}
int main() {
  int i, j, k, p, q, x, y;
  string tem;
  cin >> str;
  n = str.size();
  for (i = 0; i < 10005; i++) dp[i][2] = dp[i][3] = -1;
  for (i = 5; i < n - 1; i++) {
    if (cnt(i, 2) == 1) {
      tem = "";
      tem += str[i];
      tem += str[i + 1];
      se.insert(tem);
    }
    if (cnt(i, 3) == 1) {
      tem = "";
      tem += str[i];
      tem += str[i + 1];
      tem += str[i + 2];
      se.insert(tem);
    }
  }
  p = se.size();
  cout << p << endl;
  for (it = se.begin(); it != se.end(); ++it) cout << *it << endl;
  return 0;
}
