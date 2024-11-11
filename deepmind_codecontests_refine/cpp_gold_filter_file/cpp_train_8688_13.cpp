#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e2 + 13;
int h, t, R, n, m, dp[maxN][maxN], hh[maxN], ht[maxN], th[maxN], tt[maxN],
    dis[maxN][maxN];
bool draw = 0;
queue<pair<int, int>> qu;
bool mark[maxN][maxN], anc[maxN][maxN], seen[maxN][maxN];
void dfs(int x, int y) {
  anc[x][y] = true;
  mark[x][y] = true;
  for (int i = 1; i <= min(x, n); i++) {
    if (x - i + hh[i] + y + ht[i] <= R) {
      if (anc[x - i + hh[i]][y + ht[i]]) {
        draw = 1;
        return;
      } else if (!mark[x - i + hh[i]][y + ht[i]]) {
        mark[x - i + hh[i]][y + ht[i]] = true;
        dfs(x - i + hh[i], y + ht[i]);
      }
    }
  }
  for (int i = 1; i <= min(y, m); i++) {
    if (x + th[i] + y + tt[i] - i <= R) {
      if (anc[x + th[i]][y + tt[i] - i]) {
        draw = 1;
        return;
      } else if (!mark[x + th[i]][y + tt[i] - i]) {
        mark[x + th[i]][y + tt[i] - i] = true;
        dfs(x + th[i], y + tt[i] - i);
      }
    }
  }
  anc[x][y] = false;
}
int solve(int x, int y) {
  if (x + y > R) return 0;
  if (dp[x][y] != -1) return dp[x][y];
  for (int i = 1; i <= min(x, n); i++) {
    int cur = solve(x - i + hh[i], y + ht[i]);
    dp[x][y] = max(dp[x][y], cur + 1);
  }
  for (int i = 1; i <= min(y, m); i++) {
    int cur = solve(x + th[i], y + tt[i] - i);
    dp[x][y] = max(dp[x][y], cur + 1);
  }
  return dp[x][y];
}
int main() {
  cin >> h >> t >> R;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> hh[i] >> ht[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> th[i] >> tt[i];
  }
  memset(dis, -1, sizeof dis);
  qu.push({h, t});
  dis[h][t] = 0;
  while (!qu.empty()) {
    auto u = qu.front();
    int curdis = dis[u.first][u.second];
    if (u.first == 0 && u.second == 0)
      return cout << "Ivan\n" << curdis << endl, 0;
    qu.pop();
    for (int i = 1; i <= min(u.first, n); i++) {
      if (u.first - i + hh[i] + u.second + ht[i] <= R &&
          dis[u.first - i + hh[i]][u.second + ht[i]] == -1) {
        dis[u.first - i + hh[i]][u.second + ht[i]] = curdis + 1;
        qu.push({u.first - i + hh[i], u.second + ht[i]});
      }
    }
    for (int i = 1; i <= min(u.second, m); i++) {
      if (u.first + th[i] + u.second + tt[i] - i <= R &&
          dis[u.first + th[i]][u.second + tt[i] - i] == -1) {
        dis[u.first + th[i]][u.second + tt[i] - i] = curdis + 1;
        qu.push({u.first + th[i], u.second + tt[i] - i});
      }
    }
  }
  dfs(h, t);
  if (draw) return cout << "Draw" << endl, 0;
  memset(dp, -1, sizeof dp);
  cout << "Zmey\n";
  cout << solve(h, t) << endl;
}
