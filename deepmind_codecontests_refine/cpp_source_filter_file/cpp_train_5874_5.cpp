#include <bits/stdc++.h>
using namespace std;
double PI = 3.1415926535897932384626433832795;
char arr[1001][1001];
int vis[1001][1001], dir[4] = {1, 0, -1, 0}, dirc[4] = {0, 1, 0, -1},
                     ans[1001][1001];
int n, m;
bool valid(int i, int j) { return i < n && j < m && i >= 0 && j >= 0; }
int dfs(int i, int j) {
  if (vis[i][j] == -1) return 1e7;
  if (vis[i][j] == 1) return ans[i][j];
  vis[i][j] = 1;
  ans[i][j] = 1;
  for (int k = 0; k < 4; ++k) {
    if (valid(dir[k] + i, dirc[k] + j)) {
      if (arr[i][j] == 'D' && arr[i + dir[k]][j + dirc[k]] == 'I')
        ans[i][j] = max(dfs(i + dir[k], j + dirc[k]) + 1, ans[i][j]);
      if (arr[i][j] == 'I' && arr[i + dir[k]][j + dirc[k]] == 'M')
        ans[i][j] = max(dfs(i + dir[k], j + dirc[k]) + 1, ans[i][j]);
      if (arr[i][j] == 'M' && arr[i + dir[k]][j + dirc[k]] == 'A')
        ans[i][j] = max(dfs(i + dir[k], j + dirc[k]) + 1, ans[i][j]);
      if (arr[i][j] == 'A' && arr[i + dir[k]][j + dirc[k]] == 'D')
        ans[i][j] = max(dfs(i + dir[k], j + dirc[k]) + 1, ans[i][j]);
    }
  }
  vis[i][j] = 1;
  return ans[i][j];
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> arr[i][j];
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      if (arr[i][j] == 'D') {
        mx = max(dfs(i, j), mx);
      }
  }
  if (mx >= 1e7)
    puts("Poor Inna!");
  else if (mx / 4 == 0)
    puts("Poor Dima!");
  else
    cout << mx / 4;
  return 0;
}
