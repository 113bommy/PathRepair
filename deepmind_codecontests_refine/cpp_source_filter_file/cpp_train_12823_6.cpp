#include <bits/stdc++.h>
using namespace std;
const int N = 12, K = 20;
const int mod = 998244353, mod2 = 1e9 + 9;
const int MX = 2011;
vector<int> graph[N];
int dp[N + 1][1 << N + 1][2];
int grid[N + 1][MX];
vector<pair<int, int> > col;
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(dp, 0, sizeof dp);
    col.clear();
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &grid[i][j]);
    for (int i = 0; i < m; i++) {
      int mx = 0;
      for (int j = 0; j < n; j++) mx = max(mx, grid[j][i]);
      col.push_back(make_pair(mx, i));
    }
    sort(col.rbegin(), col.rend());
    int s = min(n, m);
    for (int i = s - 1; i >= 0; i--)
      for (int j = (1 << n) - 1; j >= 0; j--) {
        dp[i][j][0] = dp[i + 1][j][0];
        for (int k = 0; k < n; k++) {
          dp[k][j][1] = 0;
          for (int v = 0; v < s; v++)
            if (~j & (1 << v)) {
              int val = grid[(v + k) % n][col[i].second];
              int mask = j | (1 << v);
              dp[k][j][1] = max(dp[k][j][1],
                                val + max(dp[k][mask][1], dp[i + 1][mask][0]));
            }
          dp[i][j][0] = max(dp[i][j][0], dp[k][j][1]);
        }
      }
    printf("%d\n", dp[0][0][0]);
  }
}
