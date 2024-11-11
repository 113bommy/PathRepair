#include <bits/stdc++.h>
using namespace std;
int components[50][50];
char input[50][50];
bool cycle();
bool dfs(int, int, int, int, char);
int m, z;
char t;
int main() {
  cin >> m >> z;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < z; j++) {
      cin >> input[i][j];
    }
  }
  if (cycle())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
bool cycle() {
  int x = 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < z; j++) {
      if (components[i][j] == 0) {
        if (dfs(i, j, x, -1, input[i][j])) return true;
        x++;
      }
    }
  return false;
}
bool dfs(int x, int y, int n, int q, char color) {
  if (input[x][y] == color && components[x][y] == n) return true;
  if (components[x][y] == n || components[x][y] == -n) return false;
  if (input[x][y] != color) return false;
  if (x >= m || x < 0 || y >= z || y < 0) return false;
  components[x][y] = n;
  if (q == -1)
    return (dfs(x - 1, y, n, 1, color) || dfs(x + 1, y, n, 0, color) ||
            dfs(x, y + 1, n, 2, color) || dfs(x, y - 1, n, 3, color));
  if (q == 0)
    return (dfs(x + 1, y, n, 0, color) || dfs(x, y + 1, n, 2, color) ||
            dfs(x, y - 1, n, 3, color));
  if (q == 1)
    return (dfs(x - 1, y, n, 1, color) || dfs(x, y + 1, n, 2, color) ||
            dfs(x, y - 1, n, 3, color));
  if (q == 2)
    return (dfs(x + 1, y, n, 0, color) || dfs(x, y + 1, n, 2, color) ||
            dfs(x - 1, y, n, 1, color));
  if (q == 3)
    return (dfs(x + 1, y, n, 0, color) || dfs(x, y + 1, n, 1, color) ||
            dfs(x - 1, y, n, 3, color));
  components[x][y] = -n;
  return false;
}
