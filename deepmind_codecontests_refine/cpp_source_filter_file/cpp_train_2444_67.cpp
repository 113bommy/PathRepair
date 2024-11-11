#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[50][50];
bool l[50][50];
const int w[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool check(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }
bool dfs(int x, int y, int px = -1, int py = -1) {
  l[x][y] = true;
  for (int i = 0; i < 4; i++)
    if (check(x + w[i][0], y + w[i][1]) &&
        !(x + w[i][0] == px && y + w[i][1] == py))
      if (a[x][y] == a[x + w[i][0]][y + w[i][1]])
        if (l[x + w[i][0]][y + w[i][1]])
          return true;
        else if (dfs(x + w[i][0], y + w[i][1], x, y))
          return true;
  return false;
}
int main() {
  char c;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> c;
      a[i][j] = c - 'A';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!l[i][j])
        if (dfs(i, j)) {
          cout << "YES";
          return 0;
        }
  cout << "NO";
  return 0;
}
