#include <bits/stdc++.h>
using namespace std;
int mat[510][510], sum[510][510];
int n, m;
bool ok(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &mat[i][j]);
  memset(sum, 0, sizeof(sum));
  for (int i = n - 1; i >= 0; i--) {
    int t = 0;
    for (int j = m - 1; j >= 0; j--) {
      t += mat[i][j];
      sum[i][j] = sum[i + 1][j] + t;
    }
  }
  int ans = -1000000000;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      int x = i, y = j;
      int t = mat[i][j];
      int l = 1;
      while (true) {
        x--, y--;
        l += 2;
        if (ok(x, y) && (x + l - 1) < n && (y + l - 1) < m) {
          t += mat[x + 1][y];
          int s = sum[x][y] - sum[x + l][y] - sum[x][y + l] + sum[x + l][y + l];
          t = s - t;
          ans = max(ans, t);
        } else
          break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
