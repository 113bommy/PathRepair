#include <bits/stdc++.h>
using namespace std;
bool dp[4010][4010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> p[i];
    vector<int> c;
    int temp = 0;
    set<int> s;
    for (int i = 1; i <= 2 * n; i++) s.insert(i);
    int m = 2 * n;
    for (int i = 2 * n - 1; i >= 0; i--) {
      temp++;
      s.erase(p[i]);
      if (p[i] == m) {
        c.push_back(temp);
        temp = 0;
        if (s.size() > 0) m = *s.rbegin();
      }
    }
    sort(c.begin(), c.end());
    for (int i = 0; i <= 2 * n; i++) {
      for (int j = 0; j <= 2 * n; j++) {
        dp[i][j] = 0;
      }
    }
    dp[0][0] = 1;
    for (int i = 0; i < c.size(); i++) {
      for (int j = 0; j <= 2 * n; j++) dp[i + 1][j] = dp[i][j];
      for (int j = 0; j <= 2 * n; j++) {
        if (j - c[i] >= 0) dp[i + 1][j] |= dp[i][j - c[i]];
      }
    }
    if (dp[n][n] == 1) {
      cout << "YES\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
