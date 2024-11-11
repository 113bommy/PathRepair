#include <bits/stdc++.h>
using namespace std;
const int MX = 21, maxmask = 1 << MX, MN = 1e5 + 10;
int dp[MX][maxmask];
int msk[MN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '1') msk[j] += (1 << i);
    }
  }
  for (int i = 0; i < m; i++) {
    dp[0][msk[i]] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int k = i; k > 0; k--) {
      for (int mask = 0; mask < (1 << n); mask++) {
        dp[k][mask] += dp[k - 1][mask ^ (1 << (i - 1))];
      }
    }
  }
  int ans = n * m;
  for (int mask = 0; mask < (1 << n); mask++) {
    int k = 0;
    for (int i = 0; i <= n; i++) {
      k += min(i, n - i) * dp[i][mask];
    }
    ans = min(ans, k);
  }
  cout << ans << endl;
  return 0;
}
