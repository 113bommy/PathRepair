#include <bits/stdc++.h>
using namespace std;
const long long N = 60, OO = 1e9 + 100, M = 1e9 + 7, P = 6151, SQ = 100,
                lg = 21;
long long dp[N][N], dis[N][N], mx[N], mn[N];
bool g[N], b[N], s[N];
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  memset(dis, 63, sizeof(dis));
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    dis[x][y] = z;
    dis[y][x] = z;
  }
  long long g1, g2, s1, s2;
  cin >> g1 >> g2 >> s1 >> s2;
  for (long long i = 1; i <= n; i++) dis[i][i] = 0;
  for (long long k = 1; k <= n; k++)
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  for (long long i = 1; i <= n; i++) {
    sort(dis[i] + 1, dis[i] + n + 1);
    for (long long j = 0; j < n; j++) dis[i][j] = dis[i][j + 2];
    for (long long j = 0; j < n - 1; j++) dis[i][j] = dis[i][j] * 100 + i;
    mn[i] = dis[i][0], mx[i] = dis[i][n - 2];
  }
  long long ans = 0;
  for (long long st = 1; st <= n; st++)
    for (long long en = 1; en <= n; en++)
      if (st != en && mn[st] < mx[en]) {
        fill(g, g + n + 10, false), fill(b, b + n + 10, false),
            fill(s, s + n + 10, false);
        memset(dp, 0, sizeof(dp));
        for (long long i = 1; i <= n; i++) {
          if (mn[i] < mn[st]) g[i] = true;
          if (mx[i] > mx[en]) b[i] = true;
          for (long long j = 0; j < n - 1; j++)
            if (dis[i][j] > mn[st] && dis[i][j] < mx[en]) s[i] = true;
        }
        g[st] = true;
        s[st] = false;
        b[st] = false;
        g[en] = false;
        s[en] = false;
        b[en] = true;
        dp[0][0] = 1;
        for (long long k = 1; k <= n; k++) {
          for (long long i = n; i >= 0; i--) {
            for (long long j = n; j >= 0; j--) {
              if (g[k]) dp[i + 1][j] += dp[i][j];
              if (s[k]) dp[i][j + 1] += dp[i][j];
              if (b[k] == false) dp[i][j] = 0;
            }
          }
        }
        for (long long i = g1; i <= g2; i++)
          for (long long j = s1; j <= s2; j++) ans += dp[i][j];
      }
  cout << ans << endl;
  return 0;
}
