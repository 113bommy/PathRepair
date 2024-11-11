#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
int dp[maxn][maxn];
string second, t;
pair<int, int> pp[maxn][maxn];
string ps[maxn][maxn];
void pr(int i, int j) {
  if (i == 0) {
    for (int k = j; k > 0; k--)
      cout << "INSERT" << ' ' << 1 << ' ' << t[k - 1] << ' ';
    return;
  }
  if (j == 0) {
    for (int k = i; k > 0; k--) cout << "DELETE" << ' ' << 0 << ' ';
    return;
  }
  if (ps[i][j] == "DELETE")
    cout << ps[i][j] << ' ' << i << ' ';
  else if (ps[i][j] == "REPLACE")
    cout << ps[i][j] << ' ' << i << ' ' << t[j - 1] << ' ';
  else if (ps[i][j] == "INSERT")
    cout << ps[i][j] << ' ' << i + 1 << ' ' << t[j - 1] << ' ';
  pr(pp[i][j].first, pp[i][j].second);
  return;
}
int main() {
  cin >> second >> t;
  for (int i = 1; i <= (int)(second).size(); i++) dp[i][0] = i;
  for (int i = 1; i <= (int)(t).size(); i++) dp[0][i] = i;
  for (int i = 1; i <= (int)(second).size(); i++) {
    for (int j = 1; j <= (int)(t).size(); j++) {
      if (second[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
        pp[i][j] = {i - 1, j - 1};
        ps[i][j] = "0";
      } else {
        int mn = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        if (dp[i - 1][j - 1] == mn) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          pp[i][j] = {i - 1, j - 1};
          ps[i][j] = "REPLACE";
        } else if (dp[i - 1][j] == mn) {
          dp[i][j] = dp[i - 1][j] + 1;
          pp[i][j] = {i - 1, j};
          ps[i][j] = "DELETE";
        } else {
          dp[i][j] = dp[i][j - 1] + 1;
          pp[i][j] = {i, j - 1};
          ps[i][j] = "INSERT";
        }
      }
    }
  }
  cout << dp[(int)(second).size()][(int)(t).size()] << endl;
  pr((int)(second).size(), (int)(t).size());
  return false;
}
