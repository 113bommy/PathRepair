#include <bits/stdc++.h>
using namespace std;
int64_t n, m;
int64_t visited[100][100];
char ar[100][100];
bool ans = false;
void dfs(int64_t i, int64_t j, int64_t di, char c) {
  if (i < 0 || i >= n || j < 0 || j >= m) return;
  if (ar[i][j] != c) return;
  if (visited[i][j]) {
    ans = true;
    return;
  }
  visited[i][j] = 1;
  for (int64_t k = 1; k <= 4; k++) {
    if (k != 5 - di) {
      if (k == 1)
        dfs(i + 1, j, 1, c);
      else if (k == 2)
        dfs(i, j + 1, 2, c);
      else if (k == 3)
        dfs(i, j - 1, 3, c);
      else
        dfs(i - 1, j, 4, c);
    }
  }
}
int32_t main() {
  cin >> n >> m;
  for (int64_t i = 0; i < n; i++)
    for (int64_t j = 0; j < m; j++) cin >> ar[i][j];
  for (int64_t i = 0; i < n; i++) {
    for (int64_t j = 0; j < m; j++) {
      if (!visited[i][j]) dfs(i, j, 0, ar[i][j]);
    }
  }
  if (ans)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
