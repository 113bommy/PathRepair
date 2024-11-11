#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int K = 777;
int n, m, p;
int a[321][321];
int dp[321][321];
int ndp[321][321];
vector<pair<int, int> > wh[MaxN], q[MaxN];
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
      wh[a[i][j]].push_back(make_pair(i, j));
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = INF;
    }
  }
  dp[wh[p].back().first][wh[p].back().second] = 0;
  for (int it = p; it > 1; --it) {
    if (wh[it - 1].size() > K) {
      int mval = INF;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          mval = min(mval, dp[i][j]);
          ndp[i][j] = INF;
        }
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (dp[i][j] < INF) {
            dp[i][j] -= mval;
            q[dp[i][j]].push_back(make_pair(i, j));
          }
        }
      }
      for (int i = 0; i <= p + 5; ++i) {
        for (int j = 0; j < (int)q[i].size(); ++j) {
          int x = q[i][j].first, y = q[i][j].second;
          for (int dx = -1; dx <= +1; ++dx) {
            for (int dy = -1; dy <= +1; ++dy) {
              if (abs(dx) + abs(dy) != 1 || x + dx < 1 || x + dx > n ||
                  y + dy < 1 || y + dy > m) {
                continue;
              }
              int nx = x + dx, ny = y + dy;
              if (dp[nx][ny] > dp[x][y] + 1) {
                dp[nx][ny] = dp[x][y] + 1;
                q[dp[nx][ny]].push_back(make_pair(nx, ny));
              }
            }
          }
        }
        q[i].clear();
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          dp[i][j] += mval;
        }
      }
      vector<pair<int, int> > &v = wh[it - 1];
      for (int i = 0; i < (int)v.size(); ++i) {
        int x = v[i].first, y = v[i].second;
        ndp[x][y] = dp[x][y];
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          dp[i][j] = ndp[i][j];
        }
      }
    } else {
      vector<pair<int, int> > &v = wh[it];
      vector<pair<int, int> > &u = wh[it - 1];
      for (int i = 0; i < (int)v.size(); ++i) {
        int x = v[i].first, y = v[i].second;
        if (dp[x][y] < INF) {
          for (int j = 0; j < (int)u.size(); ++j) {
            int nx = u[j].first, ny = u[j].second;
            int val = dp[x][y] + abs(x - nx) + abs(y - ny);
            if (dp[nx][ny] > val) {
              dp[nx][ny] = val;
            }
          }
          dp[x][y] = INF;
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i < (int)wh[1].size(); ++i) {
    ans = min(ans, dp[wh[1][i].first][wh[1][i].second] +
                       abs(1 - wh[1][i].first) + abs(1 - wh[1][i].second));
  }
  printf("%d\n", ans);
  return 0;
}
