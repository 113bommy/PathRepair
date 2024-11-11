#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 7;
int sh, st, lim;
int n, m;
int addh[N][2], addt[N][2];
vector<pair<pair<int, int>, pair<int, int> > > ad, rad;
int dis[N][N];
bool ok(int x, int y) { return (x >= 0 && y >= 0 && x + y <= lim); }
void bfs() {
  queue<pair<int, int> > q;
  q.push({sh, st});
  dis[sh][st] = 1;
  while (q.size()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (x == 0 && y == 0) {
      cout << "Ivan" << endl << dis[0][0] - 1;
      exit(0);
    }
    for (auto p : ad) {
      int nx = x + p.first.first;
      int ny = y + p.first.second;
      int lx = p.second.first;
      int ly = p.second.second;
      if (x >= lx && y >= ly && ok(nx, ny) && !dis[nx][ny]) {
        q.push({nx, ny});
        dis[nx][ny] = dis[x][y] + 1;
      }
    }
  }
}
bool mrk[N][N];
int in[N][N];
vector<pair<int, int> > com;
void dfs(int x, int y) {
  mrk[x][y] = 1;
  com.push_back({x, y});
  for (auto p : ad) {
    int nx = x + p.first.first;
    int ny = y + p.first.second;
    int lx = p.second.first;
    int ly = p.second.second;
    if (x < lx || y < ly || !ok(nx, ny)) continue;
    if (!mrk[nx][ny]) {
      dfs(nx, ny);
    }
  }
}
int go[N][N];
int dp[N][N];
int main() {
  cin >> sh >> st >> lim;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> addh[i][0] >> addh[i][1];
    ad.push_back({{addh[i][0] - i, addh[i][1]}, {i, 0}});
    rad.push_back({{-addh[i][0] + i, -addh[i][1]}, {addh[i][0], 0}});
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> addt[i][0] >> addt[i][1];
    ad.push_back({{addt[i][0], addt[i][1] - i}, {0, i}});
    rad.push_back({{-addh[i][0] + i, -addh[i][1]}, {0, addt[i][1]}});
  }
  bfs();
  dfs(sh, st);
  for (auto p : com) {
    int x = p.first;
    int y = p.second;
    for (auto pp : ad) {
      int nx = x + pp.first.first;
      int ny = y + pp.first.second;
      int lx = pp.second.first;
      int ly = pp.second.second;
      if (x >= lx && y >= ly && ok(nx, ny)) {
        in[nx][ny]++;
        go[x][y]++;
      }
    }
  }
  queue<pair<int, int> > q;
  for (auto p : com) {
    if (!in[p.first][p.second]) q.push({p.first, p.second});
  }
  int cnt = 0;
  while (q.size()) {
    int x = q.front().first;
    int y = q.front().second;
    cnt++;
    q.pop();
    for (auto p : ad) {
      int nx = x + p.first.first;
      int ny = y + p.first.second;
      int lx = p.second.first;
      int ly = p.second.second;
      if (x >= lx && y >= ly && ok(nx, ny)) {
        in[nx][ny]--;
        if (!in[nx][ny]) q.push({nx, ny});
      }
    }
  }
  if (cnt < com.size()) {
    cout << "Draw";
    return 0;
  }
  for (auto p : com) {
    if (!go[p.first][p.second]) {
      q.push({p.first, p.second});
      dp[p.first][p.second] = 1;
    }
  }
  while (q.size()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (auto p : rad) {
      int nx = x + p.first.first;
      int ny = y + p.first.second;
      int lx = p.second.first;
      int ly = p.second.second;
      if (x >= lx && y >= ly && ok(nx, ny)) {
        go[nx][ny]--;
        dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
        if (!go[nx][ny]) q.push({nx, ny});
      }
    }
  }
  cout << "Zmey" << endl;
  cout << dp[sh][st];
  return 0;
}
