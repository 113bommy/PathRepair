#include <bits/stdc++.h>
using namespace std;
int a[2001][2001];
int maxdp[10][2001], mindp[10][2001];
int T[10][10];
int main() {
  int n, m, x, k, second;
  cin >> n >> m >> k >> second;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i + 1][j + 1]);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 2001; j++) {
      mindp[i][j] = 1e8;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      x = a[i][j];
      mindp[x][i] = min(mindp[x][i], j);
      maxdp[x][i] = max(maxdp[x][i], j);
    }
  }
  int ans = 0;
  int r;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      r = T[i][j];
      for (int x1 = 1; x1 <= n; x1++) {
        for (int x2 = 1; x2 <= n; x2++) {
          if (x1 >= x2) {
            if (maxdp[i][x1] != 0 and mindp[j][x2] != 1e8 and
                maxdp[i][x1] > mindp[j][x2]) {
              r = max(r, x1 - x2 + maxdp[i][x1] - mindp[j][x2]);
            }
          }
          if (x1 <= x2) {
            if (mindp[i][x1] != 1e8 and maxdp[j][x2] != 0 and
                mindp[i][x1] < maxdp[j][x2]) {
              r = max(r, x2 - x1 + maxdp[j][x2] - mindp[i][x1]);
            }
          }
          if (x1 <= x2) {
            if (maxdp[i][x1] != 0 and mindp[j][x2] != 1e8 and
                maxdp[i][x1] > mindp[j][x2]) {
              r = max(r, x2 - x1 + maxdp[i][x1] - mindp[j][x2]);
            }
          }
          if (x1 >= x2) {
            if (mindp[i][x1] != 1e8 and maxdp[j][x2] != 0 and
                mindp[i][x1] < maxdp[j][x2]) {
              r = max(r, x1 - x2 + maxdp[j][x2] - mindp[i][x1]);
            }
          }
        }
      }
      T[i][j] = r;
    }
  }
  int q[second];
  for (int i = 0; i < second; i++) scanf("%d", &q[i]);
  ans = 0;
  for (int i = 1; i < second; i++) {
    ans = max(ans, T[q[i - 1]][q[i]]);
  }
  cout << ans;
}
