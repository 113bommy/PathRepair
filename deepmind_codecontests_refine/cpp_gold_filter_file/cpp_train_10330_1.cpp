#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    int m = t.length();
    bool f = false;
    for (int i = 1; i <= m; i++) {
      vector<int> dp(i + 1, -1);
      dp[0] = 0;
      for (char c : s) {
        for (int j = i; j >= 0; j--) {
          if (dp[j] >= 0) {
            if (j < i and t[j] == c) dp[j + 1] = max(dp[j + 1], dp[j]);
            if (dp[j] < (m - i) and t[i + dp[j]] == c) dp[j]++;
          }
        }
      }
      if (dp[i] >= m - i) {
        f = true;
        break;
      }
    }
    cout << (f ? "YES\n" : "NO\n");
  }
}
