#include <bits/stdc++.h>
using namespace std;
unsigned int dp[100010][400];
vector<int> nima[100010];
int a[100010], b[100010];
int n, m, s, e;
int solve(int all = s, int c = e) {
  unsigned int INF = -1;
  vector<int> vt[100010];
  int cur = 0;
  memset(dp, -1, sizeof(dp));
  int cnt = (all + c - 1) / c;
  for (int i = 0; i < m; ++i) {
    vt[b[i]].push_back(i + 1);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    dp[cur][0] = 0;
    cur ^= 1;
    memset(dp[cur], -1, sizeof(dp[cur]));
    for (int j = 1; j < cnt + 1; ++j) {
      unsigned int pre = dp[cur ^ 1][j - 1];
      unsigned int p =
          upper_bound(vt[a[i]].begin(), vt[a[i]].end(), pre) - vt[a[i]].begin();
      if (p == vt[a[i]].size())
        p = INF;
      else
        p = vt[a[i]][p];
      dp[cur][j] = min(dp[cur ^ 1][j], p);
      if (dp[cur ^ 1][j] > p && p + i + j * c <= all) ans = max(ans, j);
    }
  }
  return ans;
}
int main() {
  while (cin >> n >> m >> s >> e) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d", &b[i]);
      nima[b[i]].push_back(i + 1);
    }
    int ans = 0;
    int cnt = s / e;
    for (int i = 0; i < n; ++i) {
      dp[i][0] = 0;
      if (nima[a[i]].size())
        dp[i][1] = nima[a[i]][0];
      else
        dp[i][1] = -1;
      if (i == 0) continue;
      for (int j = 1; j <= cnt; ++j) {
        unsigned int now = -1;
        int w = a[i];
        int last = dp[i - 1][j - 1];
        now =
            upper_bound(nima[w].begin(), nima[w].end(), last) - nima[w].begin();
        if (now == nima[w].size() || dp[i - 1][j - 1] == -1) {
          now = -1;
        } else {
          now = nima[w][now];
        }
        dp[i][j] = min(dp[i - 1][j], now);
      }
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < cnt + 1; ++j) {
        if (dp[i][j] != -1) {
          if (i + dp[i][j] + 1 + j * e <= s) ans = max(ans, j);
        }
      }
    cout << ans << endl;
    return 0;
  }
}
