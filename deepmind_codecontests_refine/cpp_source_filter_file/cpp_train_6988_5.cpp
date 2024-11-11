#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const long long mod = 998244353;
const int inf = 0x3f3f3f3f;
int co[20][maxn], cha[20][20], chaa[20][20];
int dp[(1 << 17)][20][20];
vector<int> ff;
map<int, int> last;
set<int> s;
const int qq = 5e5;
int main() {
  int n, m, k, t = 0, a, b, c;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &co[i][j]);
  if (n == 1) {
    int ans = inf;
    for (int i = 2; i <= m; i++) ans = min(co[1][i] - co[1][i - 1], ans);
    cout << ans;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int minn = inf;
      for (int k = 1; k <= m; k++) {
        minn = min(minn, abs(co[j][k] - co[i][k]));
      }
      cha[i][j] = cha[j][i] = minn;
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int qwq = inf;
      for (int k = 2; k <= m; k++) qwq = min(qwq, abs(co[i][k] - co[j][k - 1]));
      chaa[i][j] = qwq;
    }
  for (int i = 0; i < (1 << n); i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) dp[i][j][k] = -1;
  for (int i = 1; i < (1 << n); i++) {
    if (!(i & (i - 1))) {
      for (int j = 0; j < n; j++)
        if (i & (1 << j)) dp[i][j][j] = inf;
    }
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        for (int k = 0; k < n; k++)
          if (dp[i][j][k] != -1) {
            for (int u = 0; u < n; u++) {
              if (i & (1 << u)) continue;
              dp[i | (1 << u)][j][u] = max(dp[i | (1 << u)][j][u],
                                           min(dp[i][j][k], cha[k + 1][u + 1]));
            }
          }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (i != j)
        ans = max(min(dp[(1 << n) - 1][i][j], chaa[i + 1][j + 1]), ans);
  }
  cout << ans;
}
