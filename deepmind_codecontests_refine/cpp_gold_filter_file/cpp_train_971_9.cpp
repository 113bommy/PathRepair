#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
int n, k;
char grid[2][100005];
bool vis[2][100005];
bool sol = 0;
bool valid(int x, int y) {
  if (y < 0 || y > n - 1) return 0;
  return 1;
}
void solve(int x, int y, int w) {
  vis[x][y] = 1;
  if (w >= y) return;
  if (y + k >= n) sol = 1;
  if (valid(1 - x, y + k)) {
    if (!vis[1 - x][y + k] && grid[1 - x][y + k] == '-')
      solve(1 - x, y + k, w + 1);
  }
  if (valid(x, y + 1)) {
    if (!vis[x][y + 1] && grid[x][y + 1] == '-') solve(x, y + 1, w + 1);
  }
  if (valid(x, y - 1)) {
    if (!vis[x][y - 1] && grid[x][y - 1] == '-') solve(x, y - 1, w + 1);
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) cin >> grid[i][j];
  }
  solve(0, 0, -1);
  if (sol)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
