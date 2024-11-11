#include <bits/stdc++.h>
using namespace std;
char grid[2010][2010] = {0};
int cnt[2010][2010] = {0};
int adj[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", grid[i] + 1);
  }
  int rem = 0;
  queue<pair<int, int> > Q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < 4; k++) {
        int x = i + adj[k][0];
        int y = j + adj[k][1];
        cnt[i][j] += grid[x][y] == '.';
      }
      if (grid[i][j] == '.') {
        if (cnt[i][j] == 1) {
          Q.push(pair<int, int>(i, j));
        }
        rem++;
      }
    }
  }
  while (!Q.empty()) {
    pair<int, int> f = Q.front();
    Q.pop();
    int i = f.first, j = f.second;
    if (grid[i][j] != '.' || cnt[i][j] != 1) continue;
    int k = 0;
    while (grid[i + adj[k][0]][j + adj[k][1]] != '.') {
      k++;
    }
    int ii = i + adj[k][0], jj = j + adj[k][1];
    if (k > 1) {
      swap(ii, i);
      swap(jj, j);
      k -= 2;
    }
    if (k == 0) {
      grid[i][j] = '<';
      grid[ii][jj] = '>';
    } else {
      grid[i][j] = '^';
      grid[ii][jj] = 'v';
    }
    for (int k = 0; k < 4; k++) {
      int iii = i + adj[k][0], jjj = j + adj[k][1];
      if (grid[iii][jjj] == '.') {
        if ((cnt[iii][jjj] -= 1) == 1) {
          Q.push(pair<int, int>(iii, jjj));
        }
      }
      iii = ii + adj[k][0];
      jjj = jj + adj[k][1];
      if (grid[iii][jjj] == '.') {
        if ((cnt[iii][jjj] -= 1) == 1) {
          Q.push(pair<int, int>(iii, jjj));
        }
      }
    }
    rem -= 2;
  }
  if (rem)
    puts("Not unique");
  else
    for (int i = 1; i <= n; i++) puts(grid[i] + 1);
  return 0;
}
