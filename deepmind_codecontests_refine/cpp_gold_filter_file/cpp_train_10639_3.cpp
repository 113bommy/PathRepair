#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> l(n + 1), r(n + 1);
  l[0] = r[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int x, s;
    cin >> x >> s;
    l[i] = x - s;
    r[i] = x + s;
  }
  vector<int> dp(m + 1);
  dp[m] = 0;
  for (int x = m - 1; x >= 0; --x) {
    dp[x] = m - x;
    for (int i = 0; i <= n; ++i) {
      if (x < l[i]) {
        int d = l[i] - (x + 1);
        dp[x] = min(dp[x], d + dp[min(m, r[i] + d)]);
      } else if (l[i] <= x + 1 && x + 1 <= r[i]) {
        dp[x] = dp[x + 1];
        break;
      }
    }
  }
  cout << dp[0] << endl;
}
