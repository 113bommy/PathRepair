#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  vector<vector<int>> neigh = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (int i = 0; i < t; ++i) {
    int m, n;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<int>> g(n * m);
    for (int j = 0; j < n; ++j) {
      cin >> v[j];
    }
    for (int j = 1; j < n - 1; ++j) {
      for (int k = 1; k < m - 1; ++k) {
        if (v[j][k] == 'X') {
          int c = 0;
          vector<int> cell;
          for (auto &d : neigh) {
            int dx = d[0], dy = d[1];
            if (v[j + dx][k + dy] == '.') {
              ++c;
              cell.push_back((j + dx) * m + k + dy);
            }
          }
          if (c % 2 != 0) {
            goto error;
          } else if (c == 2) {
            g[cell[0]].push_back(cell[1]);
            g[cell[1]].push_back(cell[0]);
          } else if (c == 4) {
            g[cell[0]].push_back(cell[3]);
            g[cell[3]].push_back(cell[0]);
            g[cell[1]].push_back(cell[2]);
            g[cell[2]].push_back(cell[1]);
          }
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        int id = j * m + k;
        if (v[j][k] == '.' && ans[j][k] == 0) {
          list<int> q;
          q.push_back(id);
          ans[j][k] = 1;
          while (!q.empty()) {
            int p = q.front();
            int x = p / m, y = p % m;
            q.pop_front();
            for (auto next : g[p]) {
              int nx = next / m, ny = next % m;
              if (ans[nx][ny] == 0) {
                ans[nx][ny] = 5 - ans[x][y];
                q.push_back(next);
              }
            }
          }
        }
      }
    }
    printf("YES\n");
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        if (ans[j][k] == 0) {
          for (auto &d : neigh) {
            int dx = d[0], dy = d[1];
            if (v[j + dx][k + dy] == '.') {
              ans[j][k] += ans[j + dx][k + dy];
            }
          }
        }
        printf("%d ", ans[j][k]);
      }
      printf("\n");
    }
    continue;
  error:
    printf("NO\n");
  }
  return 0;
}
