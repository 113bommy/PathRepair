#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 25;
const int MAXS = (1 << 24) + 10;
pair<int, int> p[MAXN];
int dis[MAXN][MAXN];
int dp[MAXS];
int pre[MAXS];
int main() {
  cin >> p[0].first >> p[0].second;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dis[i][j] = (p[i].first - p[j].first) * (p[i].first - p[j].first) +
                  (p[i].second - p[j].second) * (p[i].second - p[j].second);
    }
  }
  memset(dp, INF, sizeof dp);
  dp[0] = 0;
  for (int i = 0; i < (1 << n); ++i) {
    for (int a = 0; a < n; ++a) {
      if (!(i & (1 << a))) {
        if (dp[i] + dis[0][a + 1] * 2 < dp[i | (1 << a)]) {
          dp[i | (1 << a)] = dp[i] + dis[0][a + 1] * 2;
          pre[i | (1 << a)] = i;
        }
        for (int b = 0; b < n; ++b) {
          if (!(i & (1 << b))) {
            int ndis =
                dp[i] + dis[0][a + 1] + dis[a + 1][b + 1] + dis[b + 1][0];
            int nst = (i | (1 << a) | (1 << b));
            if (ndis < dp[nst]) {
              dp[nst] = ndis;
              pre[nst] = i;
            }
            break;
          }
        }
      }
    }
  }
  cout << dp[(1 << n) - 1] << endl;
  int tmp = (1 << n) - 1;
  while (tmp > 0) {
    cout << 0 << ' ';
    int now = tmp - pre[tmp];
    while (now > 0) {
      cout << __builtin_ffs(now) << ' ';
      now -= (now & -now);
    }
    tmp = pre[tmp];
  }
  cout << 0 << endl;
  return 0;
}
