#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
bool cmp(pair<int, int> p1, pair<int, int> p2) { return p1.second < p2.second; }
char grid[507][507];
int vis[507][507];
int m, n, k;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool ok(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.';
}
void dfs(int x, int y) {
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (ok(nx, ny) && !vis[nx][ny]) dfs(nx, ny);
  }
  if (k) grid[x][y] = 'x', k--;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!vis[i][j] && grid[i][j] == '.') dfs(i, j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}
