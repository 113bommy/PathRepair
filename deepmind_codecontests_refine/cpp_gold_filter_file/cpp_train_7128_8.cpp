#include <bits/stdc++.h>
using namespace std;
char t[2000 + 5][2000 + 5];
int grad[2000 + 5][2000 + 5];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int main() {
  int n, m, sol = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n + 2; i++)
    for (int j = 0; j < m + 2; j++) t[i][j] = '*', grad[i][j] = 0;
  getchar();
  queue<pair<int, int> > bfs;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      t[i][j] = getchar();
      if (t[i][j] == '.')
        sol++, grad[i - 1][j]++, grad[i + 1][j]++, grad[i][j - 1]++,
            grad[i][j + 1]++;
    }
    getchar();
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (t[i][j] == '.' and grad[i][j] == 1) bfs.push(make_pair(i, j));
  int x, y;
  while (!bfs.empty()) {
    x = bfs.front().first;
    y = bfs.front().second;
    bfs.pop();
    if (t[x][y + 1] == '.') {
      t[x][y] = '<', t[x][y + 1] = '>';
      y++;
      for (int i = 0; i < 4; i++)
        if (t[x + dx[i]][y + dy[i]] == '.') {
          grad[x + dx[i]][y + dy[i]]--;
          if (grad[x + dx[i]][y + dy[i]] == 1)
            bfs.push(make_pair(x + dx[i], y + dy[i]));
        }
      y--;
      sol -= 2;
    } else if (t[x][y - 1] == '.') {
      t[x][y] = '>', t[x][y - 1] = '<';
      y--;
      for (int i = 0; i < 4; i++)
        if (t[x + dx[i]][y + dy[i]] == '.') {
          grad[x + dx[i]][y + dy[i]]--;
          if (grad[x + dx[i]][y + dy[i]] == 1)
            bfs.push(make_pair(x + dx[i], y + dy[i]));
        }
      y++;
      sol -= 2;
    } else if (t[x + 1][y] == '.') {
      t[x][y] = '^', t[x + 1][y] = 'v';
      x++;
      for (int i = 0; i < 4; i++)
        if (t[x + dx[i]][y + dy[i]] == '.') {
          grad[x + dx[i]][y + dy[i]]--;
          if (grad[x + dx[i]][y + dy[i]] == 1)
            bfs.push(make_pair(x + dx[i], y + dy[i]));
        }
      x--;
      sol -= 2;
    } else if (t[x - 1][y] == '.') {
      t[x][y] = 'v', t[x - 1][y] = '^';
      x--;
      for (int i = 0; i < 4; i++)
        if (t[x + dx[i]][y + dy[i]] == '.') {
          grad[x + dx[i]][y + dy[i]]--;
          if (grad[x + dx[i]][y + dy[i]] == 1)
            bfs.push(make_pair(x + dx[i], y + dy[i]));
        }
      x++;
      sol -= 2;
    }
  }
  if (sol == 0) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) putchar(t[i][j]);
      cout << endl;
    }
  } else
    cout << "Not unique" << endl;
}
