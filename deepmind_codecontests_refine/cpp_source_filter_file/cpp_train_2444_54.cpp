#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
char arr[51][51];
bool cycle = 0;
long long int n, m;
bool vis[51][51];
long long int row[4] = {0, 0, 1, -1};
long long int col[4] = {1, -1, 0, 0};
bool isvalid(long long int x, long long int y, char color) {
  if (x >= 0 and y >= 0 and x < n and y < m and arr[x][y] == color) return true;
  return false;
}
void dfs(long long int i, long long int j, long long int par_x,
         long long int par_y, char color) {
  if (!isvalid(i, j, color)) return;
  if (vis[i][j]) {
    cycle = 1;
    return;
  }
  vis[i][j] = true;
  for (long long int b = 0; b < 4; b++) {
    long long int x = i + row[b];
    long long int y = j + col[b];
    if (x == par_x and y == par_y) continue;
    dfs(x, y, i, j, color);
  }
}
int32_t main() {
  cin >> n >> m;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  memset(vis, 0, sizeof vis);
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        cycle = 0;
        dfs(i, j, -1, -1, arr[i][j]);
        if (cycle) {
          cout << "YES" << '\n';
          return 0;
        }
      }
    }
  }
  cout << "NO" << '\n';
  return 0;
}
