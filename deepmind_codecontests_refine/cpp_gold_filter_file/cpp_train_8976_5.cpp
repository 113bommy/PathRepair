#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 7;
const long long mod = 998244353;
const int INF = 1e9 + 2e7;
int a[maxn];
int dp[maxn][1000 + 7];
int main() {
  int n, m, G, R;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d%d", &G, &R);
  sort(a + 1, a + 1 + m);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= G; j++) {
      dp[i][j] = -1;
    }
  }
  deque<pair<int, int> > q;
  while (!q.empty()) q.pop_front();
  q.push_front({1, 0});
  dp[1][0] = 0;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop_front();
    if (y == G && dp[x][0] == -1) {
      dp[x][0] = dp[x][y] + 1;
      q.push_back({x, 0});
    }
    if (x < m && y + a[x + 1] - a[x] <= G &&
        dp[x + 1][y + a[x + 1] - a[x]] == -1) {
      dp[x + 1][y + a[x + 1] - a[x]] = dp[x][y];
      q.push_front({x + 1, y + a[x + 1] - a[x]});
    }
    if (x > 1 && y + a[x] - a[x - 1] <= G &&
        dp[x - 1][y + a[x] - a[x - 1]] == -1) {
      dp[x - 1][y + a[x] - a[x - 1]] = dp[x][y];
      q.push_front({x - 1, y + a[x] - a[x - 1]});
    }
  }
  int ans = INT_MAX;
  for (int i = 1; i <= G; i++) {
    if (dp[m][i] != -1) {
      ans = min(ans, dp[m][i] * (G + R) + i);
    }
  }
  if (ans == INT_MAX) ans = -1;
  printf("%d\n", ans);
  return 0;
}
