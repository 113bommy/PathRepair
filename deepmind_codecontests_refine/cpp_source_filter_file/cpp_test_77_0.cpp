#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m, res[N], idx = -1, step;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
bool book[N][N];
int a[N][N];
void dfs(int x, int y) {
  bool flag = 0;
  int xx = a[x][y];
  for (int i = 0; i < 4; i++) {
    if ((xx >> i) & 1 == 1) continue;
    int tx = x + dx[i];
    int ty = y + dy[i];
    if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
      continue;
    }
    if (!book[tx][ty]) {
      flag = 1;
      book[tx][ty] = 1;
      step++;
      dfs(tx, ty);
    }
  }
  if (!flag) return;
}
int main() {
  idx = -1;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!book[i][j]) {
        step = 1;
        book[i][j] = 1;
        dfs(i, j);
        res[++idx] = step;
      }
  sort(res, res + idx + 1);
  for (int i = idx; i >= 0; i--) cout << res[i] << ' ';
  puts("");
  return 0;
}
