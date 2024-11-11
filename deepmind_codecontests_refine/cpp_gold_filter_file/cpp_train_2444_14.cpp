#include <bits/stdc++.h>
using namespace std;
bool ans, mark[61][61] = {false};
char grid[61][61];
int n, m;
void dfs(int i, int j, int pari, int parj) {
  if (i < n and grid[i][j] == grid[i + 1][j] and mark[i + 1][j] and
      i + 1 != pari)
    ans = true;
  if (i > 1 and grid[i][j] == grid[i - 1][j] and mark[i - 1][j] and
      i - 1 != pari)
    ans = true;
  if (j < m and grid[i][j] == grid[i][j + 1] and mark[i][j + 1] and
      j + 1 != parj)
    ans = true;
  if (j > 1 and grid[i][j] == grid[i][j - 1] and mark[i][j - 1] and
      j - 1 != parj)
    ans = true;
  mark[i][j] = true;
  if (i < n and grid[i][j] == grid[i + 1][j] and !mark[i + 1][j])
    dfs(i + 1, j, i, j);
  if (i > 1 and grid[i][j] == grid[i - 1][j] and !mark[i - 1][j])
    dfs(i - 1, j, i, j);
  if (j < m and grid[i][j] == grid[i][j + 1] and !mark[i][j + 1])
    dfs(i, j + 1, i, j);
  if (j > 1 and grid[i][j] == grid[i][j - 1] and !mark[i][j - 1])
    dfs(i, j - 1, i, j);
  return;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> grid[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!mark[i][j]) dfs(i, j, -1, -1);
  if (ans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
