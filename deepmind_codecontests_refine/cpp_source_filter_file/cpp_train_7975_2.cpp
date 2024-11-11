#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int n;
int t[102], d[102], p[102];
int dp[102][2002];
int dp2[102][2002];
int main() {
  cin >> n;
  vector<pair<int, int>> rk;
  rk.clear();
  int maxd = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &t[i], &d[i], &p[i]);
    rk.push_back(make_pair(d[i], i));
    maxd = max(maxd, d[i]);
  }
  sort(rk.begin(), rk.end());
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= maxd; ++j) {
      if (dp[i][j] >= 0) {
        for (int k = i + 1; k <= n; ++k) {
          int id = rk[k - 1].second;
          if (j + t[id] < d[id]) {
            if (dp[i][j] + p[id] > dp[k][j + t[id]]) {
              dp[k][j + t[id]] = dp[i][j] + p[id];
              dp2[k][j + t[id]] = id;
            }
          }
        }
      }
    }
  }
  int ans = 0;
  int ai = -1;
  int aj = -1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= maxd; ++j) {
      if (dp[i][j] > ans) {
        ans = dp[i][j];
        ai = i;
        aj = j;
      }
    }
  }
  vector<int> ids;
  ids.clear();
  while (ai >= 1) {
    ids.push_back(rk[ai - 1].second);
    int id = rk[ai - 1].second;
    int i;
    for (i = ai - 1; i >= 1; --i) {
      int j;
      for (j = 0; j <= maxd; ++j) {
        if (dp[i][j] >= 0 && dp[i][j] + p[id] == dp[ai][aj] &&
            j + t[id] == aj) {
          ai = i;
          aj = j;
          break;
        }
      }
      if (j <= maxd) break;
    }
    if (i < 1) break;
  }
  cout << ans << endl;
  printf("%d\n", (int)ids.size());
  sort(ids.begin(), ids.end());
  for (int i = 0; i < ids.size(); ++i) {
    printf("%d", ids[i]);
    if (i < ids.size() - 1)
      cout << " ";
    else
      cout << endl;
  }
  return 0;
}
