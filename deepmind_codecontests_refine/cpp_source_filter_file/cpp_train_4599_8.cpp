#include <bits/stdc++.h>
using namespace std;
long long jx[51], bag1[51][51 * 51], bag23[51][51][51 * 51], dp[51][51][51][4],
    ans;
vector<int> g[4];
int n, t, w, id;
void solve() {
  jx[0] = 1;
  for (int i = (1); i <= (50); i++) jx[i] = jx[i - 1] * i % 1000000007;
  int m1 = g[1].size(), m2 = g[2].size(), m3 = g[3].size();
  bag1[0][0] = 1, bag23[0][0][0] = 1, dp[1][0][0][1] = m1 ? 1 : 0,
  dp[0][1][0][2] = m2 ? 1 : 0, dp[0][0][1][3] = m3 ? 1 : 0;
  for (int id = (0); id <= (m1 - 1); id++)
    for (int sz = (id); sz >= (0); sz--)
      for (int w = (t); w >= (g[1][id]); w--)
        (bag1[sz + 1][w] += bag1[sz][w - g[1][id]]) %= 1000000007;
  for (int i = (0); i <= (m1); i++)
    for (int j = (0); j <= (m2); j++)
      for (int k = (0); k <= (m3); k++)
        for (int id = (1); id <= (3); id++) {
          (dp[i + 1][j][k][1] += id != 1 ? dp[i][j][k][id] : 0) %= 1000000007;
          (dp[i][j + 1][k][2] += id != 2 ? dp[i][j][k][id] : 0) %= 1000000007;
          (dp[i][j][k + 1][3] += id != 3 ? dp[i][j][k][id] : 0) %= 1000000007;
          dp[i][j][k][0] =
              (dp[i][j][k][1] + dp[i][j][k][2] + dp[i][j][k][3]) % 1000000007;
        }
  for (int id = (0); id <= (m2 - 1); id++)
    for (int sz = (id); sz <= (0); sz++)
      for (int w = (t); w >= (g[2][id]); w--)
        (bag23[sz + 1][0][w] += bag23[sz][0][w - g[2][id]]) %= 1000000007;
  for (int id = (0); id <= (m3 - 1); id++)
    for (int i = (id); i <= (0); i++)
      for (int j = (0); j <= (m2); j++)
        for (int w = (t); w >= (g[3][id]); w--)
          (bag23[j][i + 1][w] += bag23[j][i][w - g[3][id]]) %= 1000000007;
  for (int i = (0); i <= (m1); i++)
    for (int j = (0); j <= (m2); j++)
      for (int k = (0); k <= (m3); k++)
        for (int tt = (0); tt <= (t); tt++)
          (ans += dp[i][j][k][0] * bag1[i][tt] % 1000000007 *
                  bag23[j][k][t - tt] % 1000000007 * jx[i] % 1000000007 *
                  jx[j] % 1000000007 * jx[k] % 1000000007) %= 1000000007;
  cout << ans << endl;
}
int main() {
  cin >> n >> t;
  for (int i = (1); i <= (n); i++) scanf("%d%d", &w, &id), g[id].push_back(w);
  solve();
  return 0;
}
