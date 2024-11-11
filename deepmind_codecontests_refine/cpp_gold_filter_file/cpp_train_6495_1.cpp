#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, arr[10][10];
int memo[10][10][(1 << 9)][35];
int solve(int x, int y, int mask, int cnt) {
  if (x == n) {
    if (cnt == (n * m) / 2)
      return 0;
    else
      return INF;
  }
  if (y == m) return solve(x + 1, 0, mask, cnt);
  if (memo[x][y][mask][cnt] != -1) return memo[x][y][mask][cnt];
  int ret = 0;
  ret = solve(x, y + 1, mask >> 1, cnt);
  if (!(mask & 1) && x > 0) {
    ret = min(ret, solve(x, y + 1, (mask | (1 << m)) >> 1, cnt + 1) +
                       (arr[x][y] == arr[x - 1][y] ? (int)0 : (int)1));
  }
  if (y < m - 1)
    ret = min(ret, solve(x, y + 2, (mask | (3 << m)) >> 2, cnt + 1) +
                       (arr[x][y] == arr[x][y + 1] ? (int)0 : (int)1));
  return memo[x][y][mask][cnt] = ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  memset(memo, -1, sizeof(memo));
  printf("%d\n", solve(0, 0, 0, 0));
  return 0;
}
