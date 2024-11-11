#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, adam[2005][2005], vis[2005][2005];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
pair<int, int> dp[2005][2005];
vector<string> vs;
bool valid(int x, int y) { return x >= 0 and x < n and y >= 0 and y < m; }
void solve(int sx, int sy) {
  memset(vis, 0, sizeof vis);
  memset(dp, 0, sizeof dp);
  deque<pair<int, int> > dq;
  dq.push_front({sx, sy});
  vis[sx][sy] = 1;
  dp[sx][sy] = {a, b};
  while (!dq.empty()) {
    auto f = dq.front();
    dq.pop_front();
    int x = f.first, y = f.second;
    if (dp[x][y].first < 0 || dp[x][y].second < 0) continue;
    adam[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (valid(xx, yy) and !vis[xx][yy] and vs[xx][yy] == '.') {
        if (dy[i] != 0)
          dq.push_back({xx, yy});
        else
          dq.push_front({xx, yy});
        vis[xx][yy] = 1;
        dp[xx][yy] = dp[x][y];
        dp[xx][yy].first -= (dy[i] == -1);
        dp[xx][yy].second -= (dy[i] == 1);
      }
    }
  }
}
int main() {
  cout.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int x, y;
  cin >> x >> y;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vs.push_back(s);
  }
  solve(x - 1, y - 1);
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) res += adam[i][j];
  cout << res << endl;
  return 0;
}
