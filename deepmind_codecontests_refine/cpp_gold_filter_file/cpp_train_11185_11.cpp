#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
int up[N][N];
int down[N][N];
int Left[N][N];
int Right[N][N];
int num[N][N];
void solve(int ncase) {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &num[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      Left[i][j] = num[i][j] + Left[i][j - 1];
    }
    for (int j = m; j >= 1; j--) {
      Right[i][j] = num[i][j] + Right[i][j + 1];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      up[i][j] = num[i][j] + up[i - 1][j];
    }
    for (int i = n; i >= 1; i--) {
      down[i][j] = num[i][j] + down[i + 1][j];
    }
  }
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      num[x][y] ^= 1;
      for (int i = 1; i <= n; i++) up[i][y] = num[i][y] + up[i - 1][y];
      for (int i = n; i >= 1; i--) down[i][y] = num[i][y] + down[i + 1][y];
      for (int j = 1; j <= m; j++) Left[x][j] = num[x][j] + Left[x][j - 1];
      for (int j = m; j >= 1; j--) Right[x][j] = num[x][j] + Right[x][j + 1];
    } else {
      int ans = 0;
      if (num[x][y] == 0) {
        printf("%d\n", ans);
        continue;
      }
      int l = y, r = y;
      for (int u = 1; u <= x; u++) {
        if (up[x][l] - up[u - 1][l] < x - u + 1) {
          continue;
        }
        if (up[x][r] - up[u - 1][r] < x - u + 1) {
          continue;
        }
        while (l >= 1 && up[x][l] - up[u - 1][l] >= x - u + 1) l--;
        l++;
        while (r <= m && up[x][r] - up[u - 1][r] >= x - u + 1) r++;
        r--;
        ans = max(ans, (r - l + 1) * (x - u + 1));
      }
      l = y;
      r = y;
      for (int d = n; d >= x; d--) {
        if (down[x][l] - down[d + 1][l] < d - x + 1) continue;
        if (down[x][r] - down[d + 1][r] < d - x + 1) continue;
        while (l >= 1 && down[x][l] - down[d + 1][l] >= d - x + 1) l--;
        l++;
        while (r <= m && down[x][r] - down[d + 1][r] >= d - x + 1) r++;
        r--;
        ans = max(ans, (r - l + 1) * (d - x + 1));
      }
      int u = x, d = x;
      for (int l = 1; l <= y; l++) {
        if (Left[u][y] - Left[u][l - 1] < y - l + 1) continue;
        if (Left[d][y] - Left[d][l - 1] < y - l + 1) continue;
        while (u >= 1 && Left[u][y] - Left[u][l - 1] >= y - l + 1) u--;
        u++;
        while (d <= n && Left[d][y] - Left[d][l - 1] >= y - l + 1) d++;
        d--;
        ans = max(ans, (d - u + 1) * (y - l + 1));
      }
      u = x, d = x;
      for (int r = m; r >= y; r--) {
        if (Right[u][y] - Right[u][r + 1] < r - y + 1) continue;
        if (Right[d][y] - Right[d][r + 1] < r - y + 1) continue;
        while (u >= 1 && Right[u][y] - Right[u][r + 1] >= r - y + 1) u--;
        u++;
        while (d <= n && Right[d][y] - Right[d][r + 1] >= r - y + 1) d++;
        d--;
        ans = max(ans, (d - u + 1) * (r - y + 1));
      }
      printf("%d\n", ans);
    }
  }
}
int main() {
  int T = 1;
  int ncase = 0;
  while (T--) {
    solve(++ncase);
  }
}
