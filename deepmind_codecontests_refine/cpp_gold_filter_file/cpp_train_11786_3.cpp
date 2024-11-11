#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char> > c(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &c[i][j]);
    }
  }
  queue<pair<int, int> > q;
  for (int i = 0; i < n; i++) {
    q.push(make_pair(i, -1));
    q.push(make_pair(i, m));
  }
  for (int i = 0; i < m; i++) {
    q.push(make_pair(-1, i));
    q.push(make_pair(n, i));
  }
  vector<vector<int> > dst(n, vector<int>(m, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '.') {
        q.push(make_pair(i, j));
        dst[i][j] = 0;
      }
    }
  }
  int maxd = 0;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    int d = 0;
    if (0 <= x && x < n && 0 <= y && y < m) {
      d = dst[x][y];
      if (c[x][y] == 'X') {
        maxd = max(maxd, d);
      }
    }
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx == 0 && dy == 0) {
          continue;
        }
        int nx = x + dx;
        int ny = y + dy;
        if (0 <= nx && nx < n && 0 <= ny && ny < m && dst[nx][ny] == -1) {
          dst[nx][ny] = d + 1;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
  int l = 1;
  int r = maxd;
  while (l != r) {
    int md = (l + r + 1) >> 1;
    queue<pair<int, int> > q;
    vector<vector<int> > ds(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (c[i][j] == 'X' && dst[i][j] >= md) {
          q.push(make_pair(i, j));
          ds[i][j] = 0;
        }
      }
    }
    bool ok = true;
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      int d = ds[x][y];
      if (c[x][y] == 'X' && d > md - 1) {
        ok = false;
        break;
      }
      for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
          if (dx == 0 && dy == 0) {
            continue;
          }
          int nx = x + dx;
          int ny = y + dy;
          if (0 <= nx && nx < n && 0 <= ny && ny < m && ds[nx][ny] == -1) {
            ds[nx][ny] = d + 1;
            q.push(make_pair(nx, ny));
          }
        }
      }
    }
    if (ok) {
      l = md;
    } else {
      r = md - 1;
    }
  }
  cout << l - 1 << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c[i][j] == '.' || dst[i][j] < l) {
        printf(".");
      } else {
        printf("X");
      }
    }
    printf("\n");
  }
}
