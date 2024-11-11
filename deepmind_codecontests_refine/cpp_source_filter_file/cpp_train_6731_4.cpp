#include <bits/stdc++.h>
using namespace std;
const int N = 104;
int c[N], k[N];
int sum[N][N];
int main() {
  int n, m, x;
  scanf("%d %d", &n, &m);
  int i, j;
  for (i = 1; i <= n; i++) scanf("%d", &c[i]);
  for (i = 1; i <= m; i++) scanf("%d", &k[i]);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      sum[i][j] = sum[i - 1][j] + ((c[i] == j) ? 1 : 0);
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      int f = 1;
      for (x = 1; x <= m; x++) {
        if ((sum[j][x] - sum[i - 1][x]) != k[x]) {
          f = 0;
          break;
        }
      }
      if (f) {
        printf("YES\n");
        return 0;
      }
    }
  }
  printf("NO\n");
  return 0;
}
