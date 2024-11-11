#include <bits/stdc++.h>
using namespace std;
int n, m, a[105][105];
int sum[2][105];
bool inv[2][105];
int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    memset(inv, false, sizeof(inv));
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", a[i] + j);
        sum[0][i] += a[i][j];
        sum[1][j] += a[i][j];
      }
    }
    while (1) {
      int idx = -1;
      for (int i = 0; i < n; i++) {
        if (sum[0][i] < 0) {
          idx = i;
          break;
        }
      }
      if (idx != -1) {
        inv[0][idx] ^= 1;
        sum[0][idx] = -sum[0][idx];
        for (int i = 0; i < m; i++) {
          sum[1][i] -= a[idx][i];
          a[idx][i] = -a[idx][i];
          sum[1][i] += a[idx][i];
        }
        continue;
      }
      for (int i = 0; i < m; i++) {
        if (sum[1][i] < 0) {
          idx = i;
          break;
        }
      }
      if (idx != -1) {
        inv[1][idx] ^= 1;
        sum[1][idx] = -sum[1][idx];
        for (int i = 0; i < n; i++) {
          sum[0][i] -= a[i][idx];
          a[idx][i] = -a[idx][i];
          sum[0][i] += a[i][idx];
        }
        continue;
      }
      break;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (inv[0][i]) cnt++;
    printf("%d", cnt);
    for (int i = 0; i < n; i++)
      if (inv[0][i]) printf(" %d", i + 1);
    printf("\n");
    cnt = 0;
    for (int i = 0; i < m; i++)
      if (inv[1][i]) cnt++;
    printf("%d", cnt);
    for (int i = 0; i < m; i++)
      if (inv[1][i]) printf(" %d", i + 1);
    printf("\n");
  }
  return 0;
}
