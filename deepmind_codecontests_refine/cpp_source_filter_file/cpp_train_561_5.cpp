#include <bits/stdc++.h>
using namespace std;
int n, m, k, s, r;
bool grid[500][500];
bool visit[500][500];
bool seen[500][500];
void dfs(int x, int y) {
  if (visit[x][y]) return;
  visit[x][y] = true;
  if (0 <= y && y < m && 0 <= x && x < n) {
    if (grid[x][y]) {
      if (r + k < s) {
        seen[x][y] = true;
        r++;
      }
      dfs(x + 1, y);
      dfs(x - 1, y);
      dfs(x, y + 1);
      dfs(x, y - 1);
    }
  }
  return;
}
int main() {
  cin >> n >> m >> k;
  int x0, y0;
  string t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    for (int j = 0; j < m; j++) {
      grid[i][j] = t[j] == '.';
      if (grid[i][j]) {
        x0 = i;
        y0 = j;
        s++;
      }
    }
  }
  dfs(x0, y0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      if (!grid[i][j]) {
        c = '#';
      } else if (seen[i][j]) {
        c = '.';
      } else {
        c = 'X';
      }
      cout << c;
    }
    cout << endl;
  }
  return 0;
}
