#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int q;
    cin >> q;
    string s, ss;
    cin >> s >> ss;
    vector<vector<int>> dp(2, vector<int>(s.length(), -1));
    dp[0][0] = 1;
    int y;
    if (s[0] == '3' || s[0] == '4' || s[0] == '5' || s[0] == '6') {
      if (ss[0] == '3' || ss[0] == '4' || ss[0] == '5' || ss[0] == '6')
        dp[1][0] = 2, y = 1;
      else {
        cout << "NO\n";
        continue;
      }
    } else
      dp[1][0] = 0, y = 0;
    bool isfound = false;
    for (int i = 1; i < s.length(); ++i) {
      if (!y) {
        if ((s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6')) {
          if (ss[i] == '3' || ss[i] == '4' || ss[i] == '5' || ss[i] == '6') {
            y = 1;
            dp[0][i] = dp[0][i - 1] + 1;
            dp[1][i] = dp[0][i] + 1;
          } else {
            isfound = true;
            break;
          }
        } else if (dp[0][i - 1] > dp[1][i - 1])
          dp[0][i] = dp[0][i - 1] + 1;
        else {
          isfound = true;
          break;
        }
      } else {
        if ((s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6')) {
          if (ss[i] == '3' || ss[i] == '4' || ss[i] == '5' || ss[i] == '6') {
            y = 0;
            dp[1][i] = dp[1][i - 1] + 1;
            dp[0][i] = dp[1][i] + 1;
          } else {
            isfound = true;
            break;
          }
        } else if (dp[1][i - 1] > dp[0][i - 1])
          dp[1][i] = dp[1][i - 1] + 1;
        else {
          isfound = true;
          break;
        }
      }
    }
    if (isfound) {
      cout << "NO\n";
    } else {
      if (dp[1][s.length() - 1] > dp[0][s.length() - 1])
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
