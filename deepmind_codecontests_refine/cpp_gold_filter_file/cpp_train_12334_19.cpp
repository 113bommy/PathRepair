#include <bits/stdc++.h>
using namespace std;
int n, m, cnt[2010][2010];
vector<pair<int, int> > neighbors[2010][2010];
string ss[2010];
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> ss[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ss[i][j] == '.') {
        if (i && ss[i - 1][j] == '.') {
          cnt[i][j]++;
          neighbors[i][j].push_back(make_pair(i - 1, j));
        }
        if (j && ss[i][j - 1] == '.') {
          cnt[i][j]++;
          neighbors[i][j].push_back(make_pair(i, j - 1));
        }
        if (i < n - 1 && ss[i + 1][j] == '.') {
          cnt[i][j]++;
          neighbors[i][j].push_back(make_pair(i + 1, j));
        }
        if (j < m - 1 && ss[i][j + 1] == '.') {
          cnt[i][j]++;
          neighbors[i][j].push_back(make_pair(i, j + 1));
        }
      }
    }
  }
  vector<pair<int, int> > coors;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cnt[i][j] == 1) {
        coors.push_back(make_pair(i, j));
      }
    }
  }
  while (true) {
    while (coors.empty() == false &&
           ss[coors.back().first][coors.back().second] != '.') {
      coors.pop_back();
    }
    if (coors.empty()) break;
    pair<int, int> pos = coors.back();
    coors.pop_back();
    int x = pos.first;
    int y = pos.second;
    cnt[x][y]--;
    if (x && ss[x - 1][y] == '.') {
      cnt[x - 1][y]--;
      ss[x][y] = 'v';
      ss[x - 1][y] = '^';
      if (cnt[x - 1][y] == 1) {
        coors.push_back(make_pair(x - 1, y));
      }
      for (auto p : neighbors[x - 1][y]) {
        if (ss[p.first][p.second] == '.') {
          cnt[p.first][p.second]--;
          if (cnt[p.first][p.second] == 1) {
            coors.push_back(make_pair(p.first, p.second));
          }
        }
      }
    }
    if (y && ss[x][y - 1] == '.') {
      cnt[x][y - 1]--;
      ss[x][y] = '>';
      ss[x][y - 1] = '<';
      if (cnt[x][y - 1] == 1) {
        coors.push_back(make_pair(x, y - 1));
      }
      for (auto p : neighbors[x][y - 1]) {
        if (ss[p.first][p.second] == '.') {
          cnt[p.first][p.second]--;
          if (cnt[p.first][p.second] == 1) {
            coors.push_back(make_pair(p.first, p.second));
          }
        }
      }
    }
    if (x < n - 1 && ss[x + 1][y] == '.') {
      cnt[x + 1][y]--;
      ss[x][y] = '^';
      ss[x + 1][y] = 'v';
      if (cnt[x + 1][y] == 1) {
        coors.push_back(make_pair(x + 1, y));
      }
      for (auto p : neighbors[x + 1][y]) {
        if (ss[p.first][p.second] == '.') {
          cnt[p.first][p.second]--;
          if (cnt[p.first][p.second] == 1) {
            coors.push_back(make_pair(p.first, p.second));
          }
        }
      }
    }
    if (y < m - 1 && ss[x][y + 1] == '.') {
      cnt[x][y + 1]--;
      ss[x][y] = '<';
      ss[x][y + 1] = '>';
      if (cnt[x][y + 1] == 1) {
        coors.push_back(make_pair(x, y + 1));
      }
      for (auto p : neighbors[x][y + 1]) {
        if (ss[p.first][p.second] == '.') {
          cnt[p.first][p.second]--;
          if (cnt[p.first][p.second] == 1) {
            coors.push_back(make_pair(p.first, p.second));
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ss[i][j] == '.') {
        cout << "Not unique";
        exit(0);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ss[i] << endl;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
}
