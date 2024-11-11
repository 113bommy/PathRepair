#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 50;
int h, t, r, n, m;
bool doro = 0;
int mark[402][402];
int heg[402][402];
int dp[402][402];
pair<int, int> sar[402];
pair<int, int> dom[402];
int dfs(int x, int y) {
  mark[x][y] = 1;
  for (int i = 1; i <= min(n, x); i++) {
    int xx = x + sar[i].first - i;
    int yy = y + sar[i].second;
    if (xx + yy <= r) {
      if (mark[xx][yy] == 1) {
        doro = 1;
      } else if (mark[xx][yy] == 0) {
        dfs(xx, yy);
      }
      dp[x][y] = max(dp[xx][yy] + 1, dp[x][y]);
    }
  }
  for (int i = 1; i <= min(y, m); i++) {
    int xx = x + dom[i].first;
    int yy = y + dom[i].second - i;
    if (xx + yy <= r) {
      if (mark[xx][yy] == 1) {
        doro = 1;
      } else if (mark[xx][yy] == 0) {
        dfs(xx, yy);
      }
      dp[x][y] = max(dp[xx][yy] + 1, dp[x][y]);
    }
  }
  mark[x][y] = 2;
  if (doro) return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> h >> t >> r;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> sar[i].first;
    cin >> sar[i].second;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> dom[i].first;
    cin >> dom[i].second;
  }
  queue<pair<int, int> > q;
  q.push(make_pair(h, t));
  mark[h][t] = 1;
  while (q.size() != 0) {
    int x = q.front().first;
    int y = q.front().second;
    for (int i = 1; i <= min(x, n); i++) {
      int xx = x - i + sar[i].first;
      int yy = y + sar[i].second;
      if (xx + yy <= r) {
        if (mark[xx][yy] == 0) {
          q.push(make_pair(xx, yy));
          mark[xx][yy] = 1;
          heg[xx][yy] = heg[x][y] + 1;
        }
      }
    }
    for (int i = 1; i <= min(y, m); i++) {
      int xx = x + dom[i].first;
      int yy = y - i + dom[i].second;
      if (xx + yy <= r) {
        if (mark[xx][yy] == 0) {
          q.push(make_pair(xx, yy));
          mark[xx][yy] = 1;
          heg[xx][yy] = heg[x][y] + 1;
        }
      }
    }
    if (mark[0][0] == 1) {
      cout << "Ivan" << endl;
      cout << heg[0][0];
      return 0;
    }
    q.pop();
  }
  for (int i = 0; i <= 400; i++) {
    for (int j = 0; j <= 400; j++) mark[i][j] = 0;
  }
  dfs(h, t);
  if (doro == 1)
    cout << "Draw";
  else {
    cout << "Zmey" << endl;
    cout << dp[h][t] + 1;
  }
}
