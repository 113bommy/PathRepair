#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> move1 = {{-1, -1}, {-1, 0}, {0, -1}, {1, 0},
                                {0, 1},   {1, 1},  {-1, 1}, {1, -1}};
bool bfs(int x, int y, vector<vector<int>> m, int fix, int fiy) {
  vector<vector<int>> v = m;
  int n = m.size();
  v[x][y] = 2;
  queue<pair<int, int>> q;
  q.push({x, y});
  while (!q.empty()) {
    pair<int, int> i = q.front();
    q.pop();
    for (pair<int, int> j : move1) {
      if (i.first + j.first >= 0 && i.first + j.first < n &&
          j.second + i.second >= 0 && j.second + i.second < n &&
          m[i.first + j.first][j.second + i.second] != 1) {
        if (v[i.first + j.first][i.second + j.second] == 0) {
          v[i.first + j.first][i.second + j.second] = 2;
          q.push({i.first + j.first, j.second + i.second});
        }
      }
    }
  }
  return v[fix][fiy] == 2;
}
int main() {
  int n;
  cin >> n;
  int x, y;
  cin >> x >> y;
  --x;
  y = n - y;
  vector<vector<int>> m(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    m[i][x] = 1;
    m[y][i] = 1;
  }
  int x1 = x, y1 = y;
  while (x1 >= 0 && y1 >= 0) {
    m[y1][x1] = 1;
    --y1;
    --x1;
  }
  x1 = x;
  y1 = y;
  while (x1 >= 0 && y1 < n) {
    m[y1][x1] = 1;
    --x1;
    ++y1;
  }
  x1 = x;
  y1 = y;
  while (x1 < n && y1 >= 0) {
    m[y1][x1] = 1;
    ++x1;
    --y1;
  }
  while (x < n && y < n) {
    m[y][x] = 1;
    ++x;
    ++y;
  }
  cin >> x >> y;
  --x;
  y = n - y;
  cin >> x1 >> y1;
  --x1;
  y1 = n - y1;
  if (bfs(y, x, m, y1, x1))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
