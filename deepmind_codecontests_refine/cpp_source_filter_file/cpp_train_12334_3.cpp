#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};
vector<char> d = {'<', '>', '^', 'v'};
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> v(n + 2, vector<char>(m + 2, '*'));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> v[i][j];
    }
  }
  vector<vector<int>> deg(n + 2, vector<int>(m + 2, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (v[i][j] == '.') {
        for (int k = 0; k < 4; k++) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (v[ni][nj] == '.') {
            deg[i][j]++;
          }
        }
      }
    }
  }
  int unused = 0;
  queue<pair<int, int>> onedeg;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (v[i][j] == '.') unused++;
      if (deg[i][j] == 1) onedeg.push({i, j});
    }
  }
  while (!onedeg.empty()) {
    int i = onedeg.front().first;
    int j = onedeg.front().second;
    onedeg.pop();
    if (deg[i][j] == 0) continue;
    for (int k = 0; k < 4; k++) {
      int ni = i + dx[k];
      int nj = j + dy[k];
      if (v[ni][nj] != '.') {
        continue;
      }
      v[i][j] = d[k];
      v[ni][nj] = d[k ^ 1];
      unused -= 2;
      deg[ni][nj]--;
      for (int k = 0; k < 4; k++) {
        int nni = ni + dx[k];
        int nnj = nj + dy[k];
        if (deg[nni][nnj] > 0) {
          deg[nni][nnj]--;
          if (deg[nni][nnj] == 1) {
            onedeg.push({nni, nnj});
          }
        }
      }
    }
  }
  if (unused > 0) {
    cout << "Not unique" << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << v[i][j];
    }
    cout << endl;
  }
}
