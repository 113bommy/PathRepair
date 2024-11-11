#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
int t, n;
int p[N];
pair<int, bool> dp[N][2], dp2[N][2];
int ans[N];
void go(int i, bool b) {
  if (i < 0) return;
  ans[i] = b ? -p[i] : p[i];
  go(i - 1, dp[i][b].second);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> p[0];
    dp[0][0] = dp[0][1] = {-1e9, 0};
    if (n == 1) {
      cout << "YES\n1\n";
      continue;
    }
    for (int i = 1; i < n; i++) {
      cin >> p[i];
      for (int it = 0; it < 2; it++) {
        dp[i][it] =
            min({make_pair(p[i] > p[i - 1] ? dp[i - 1][0].first : n + 1, 0),
                 make_pair(p[i] > -p[i - 1] ? dp[i - 1][1].first : n + 1, 1),
                 make_pair(p[i] > dp[i - 1][0].first ? p[i - 1] : n + 1, 0),
                 make_pair(p[i] > dp[i - 1][1].first ? -p[i - 1] : n + 1, 1)});
        p[i] = -p[i];
      }
    }
    if (dp[n - 1][0].first == dp[n - 1][1].first &&
        dp[n - 1][0].first == n + 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (dp[n - 1][0].first < 1e9)
      go(n - 1, 0);
    else if (dp[n - 1][1].first < 1e9)
      go(n - 1, 1);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
