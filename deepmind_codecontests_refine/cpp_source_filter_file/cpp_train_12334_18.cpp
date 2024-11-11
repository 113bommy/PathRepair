#include <bits/stdc++.h>
using namespace std;
int Mx[] = {-1, 0, 1, 0}, My[] = {0, 1, 0, -1};
bool valid(int i, int j, vector<vector<bool> > &O) {
  int n = (int)(O).size(), m = (int)(O[0]).size();
  return (i >= 0 && i < n && j >= 0 && j < m);
}
int cnt_free(int i, int j, vector<vector<bool> > &O) {
  int cnt = 0;
  for (int t = (0); t <= (3); ++t) {
    int x = Mx[t] + i, y = My[t] + j;
    if (valid(x, y, O) && !O[x][y]) cnt++;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<bool> > O(n);
  for (int i = (0); i <= ((int)(O).size() - 1); ++i) O[i].resize(m, 0);
  vector<string> ans(n);
  for (int i = (0); i <= ((int)(ans).size() - 1); ++i) {
    cin >> ans[i];
    for (int j = (0); j <= ((int)(ans[i]).size() - 1); ++j)
      if (ans[i][j] == '*') O[i][j] = 1;
  }
  queue<pair<int, int> > Q;
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (n - 1); ++j)
      if (!O[i][j]) {
        int t = cnt_free(i, j, O);
        if (t == 0) {
          cout << "Not unique";
          return 0;
        } else if (t == 1)
          Q.push(make_pair(i, j));
      }
  while (!Q.empty()) {
    pair<int, int> q = Q.front();
    Q.pop();
    if (O[q.first][q.second]) continue;
    if (!cnt_free(q.first, q.second, O)) {
      cout << "Not unique";
      return 0;
    }
    for (int t = (0); t <= (3); ++t) {
      int x = q.first + Mx[t], y = q.second + My[t];
      if (valid(x, y, O) && !O[x][y]) {
        O[q.first][q.second] = O[x][y] = 1;
        if (t == 0) {
          ans[q.first][q.second] = 'v';
          ans[x][y] = '^';
        } else if (t == 1) {
          ans[q.first][q.second] = '<';
          ans[x][y] = '>';
        } else if (t == 2) {
          ans[q.first][q.second] = '^';
          ans[x][y] = 'v';
        } else {
          ans[q.first][q.second] = '>';
          ans[x][y] = '<';
        }
        for (int k = (0); k <= (3); ++k) {
          int nx = x + Mx[k], ny = y + My[k];
          if (valid(nx, ny, O) && !O[nx][ny] && (cnt_free(nx, ny, O) <= 1))
            Q.push(make_pair(nx, ny));
        }
        break;
      }
    }
  }
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (m - 1); ++j)
      if (!O[i][j]) {
        cout << "Not unique";
        return 0;
      }
  for (int i = (0); i <= ((int)(ans).size() - 1); ++i) cout << ans[i] << '\n';
  return 0;
}
