#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int queryn;
  string s;
  cin >> n >> queryn;
  cin >> s;
  int dp[6][n];
  int query[queryn][2];
  string com[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
  for (int i = 0; i < queryn; i++) {
    cin >> query[i][0] >> query[i][1];
  }
  for (int k = 0; k < 6; k++) {
    int cost = 0;
    for (int i = 0, it = 0; i < n; i++, it++) {
      it = it % 3;
      if (s[i] != com[k][it]) {
        dp[k][i] = ++cost;
      } else {
        dp[k][i] = cost;
      }
    }
  }
  for (int w = 0; w < queryn; w++) {
    int sum = 100000000;
    for (int k = 0; k < 6; k++) {
      sum = min(dp[k][query[w][1] - 1] -
                    ((query[w][0] - 2 > 0) ? dp[k][query[w][0] - 2] : 0),
                sum);
    }
    cout << sum << endl;
  }
  return 0;
}
