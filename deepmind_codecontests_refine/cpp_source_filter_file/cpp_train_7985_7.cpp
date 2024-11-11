#include <bits/stdc++.h>
using namespace std;
void Open() {
  freopen("Input.txt", "r", stdin);
  freopen("Output.txt", "w", stdout);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void madesetprobblem() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, n, m, inf = 1e8;
  cin >> a >> n >> m;
  vector<int> rain(a + 1);
  vector<int> cost(m + 1);
  vector<pair<int, int>> ump(a + 1, make_pair(inf, -1));
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j < r; ++j) rain[j] = 1;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    cost[i] = y;
    ump[x] = min(ump[x], make_pair(y, i));
  }
  vector<vector<int>> dp(a + 1, vector<int>(m + 1, inf));
  dp[0][m] = 0;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j <= m; j++) {
      if (dp[i][j] == inf) continue;
      if (rain[i] == 0) {
        dp[i + 1][m] = min(dp[i][j], dp[i + 1][m]);
      }
      if (j < m) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + cost[j]);
      }
      if (ump[i].first != inf) {
        dp[i + 1][ump[i].second] =
            min(dp[i + 1][ump[i].second], dp[i][j] + ump[i].first);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i <= m; i++) {
    ans = min(ans, dp[a][i]);
  }
  cout << (ans == inf ? -1 : ans);
}
