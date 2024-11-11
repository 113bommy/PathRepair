#include <bits/stdc++.h>
using namespace std;
const int maxn = 400 + 10;
int mark[maxn][maxn], cyc;
int d[maxn][maxn], hh[maxn], ht[maxn], th[maxn], tt[maxn], ans, n, m, h, t, r,
    dp[maxn][maxn];
inline void bfs(int x, int y) {
  vector<pair<int, int> > u;
  u.push_back(pair<int, int>(x, y));
  mark[x][y] = 1;
  for (int i = 0; i < u.size(); i++) {
    int first = u[i].first, second = u[i].second;
    if (!first && !second) {
      cout << "Ivan\n" << d[first][second];
      exit(0);
    }
    for (int j = 1; j <= n && first >= j; j++) {
      if (!mark[first - j + hh[j]][second + ht[j]] &&
          first - j + hh[j] + second + ht[j] <= r) {
        mark[first - j + hh[j]][second + ht[j]] = 1;
        d[first - j + hh[j]][second + ht[j]] = d[first][second] + 1;
        u.push_back(pair<int, int>(first - j + hh[j], second + ht[j]));
      }
    }
    for (int j = 1; j <= m && j <= second; j++) {
      if (!mark[first + th[j]][second - j + tt[j]] &&
          first + th[j] + second - j + tt[j] <= r) {
        mark[first + th[j]][second - j + tt[j]] = 1;
        d[first + th[j]][second - j + tt[j]] = d[first][second] + 1;
        u.push_back(pair<int, int>(first + th[j], second - j + tt[j]));
      }
    }
  }
}
inline void dfs(int x, int y) {
  if (mark[x][y] == 1) {
    cout << "Draw";
    exit(0);
  }
  mark[x][y] = 1;
  for (int i = 1; i <= n; i++)
    if (x >= i && x - i + hh[i] + y + ht[i] <= r)
      if (mark[x - i + hh[i]][y + ht[i]] != 2) dfs(x - i + hh[i], y + ht[i]);
  for (int i = 1; i <= m; i++)
    if (y >= i && x + th[i] + y - i + tt[i] <= r)
      if (mark[x + th[i]][y - i + tt[i]] != 2) dfs(x + th[i], y - i + tt[i]);
  mark[x][y] = 2;
}
inline int zmey(int x, int y) {
  if (dp[x][y]) return dp[x][y];
  for (int i = 1; i <= n && i <= x; i++)
    if (x - i + hh[i] + y + ht[i] <= r)
      dp[x][y] = max(dp[x][y], zmey(x - i + hh[i], y + ht[i]) + 1);
    else
      dp[x][y] = max(dp[x][y], 1);
  for (int i = 1; i <= m && i <= y; i++)
    if (x + th[i] + y - i + tt[i] <= r)
      dp[x][y] = max(dp[x][y], zmey(x + th[i], y - i + tt[i]) + 1);
    else
      dp[x][y] = max(dp[x][y], 1);
  return dp[x][y];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> h >> t >> r;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> hh[i + 1] >> ht[i + 1];
  cin >> m;
  for (int i = 0; i < m; i++) cin >> th[i + 1] >> tt[i + 1];
  bfs(h, t);
  memset(mark, 0, sizeof mark);
  dfs(h, t);
  memset(mark, 0, sizeof mark);
  cout << "Zmey\n" << zmey(h, t);
}
