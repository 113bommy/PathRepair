#include <bits/stdc++.h>
using namespace std;
int a[105][105];
int main() {
  int ans, i, j, k, l, n, m, x, y, kk;
  scanf("%d%d%d", &n, &m, &kk);
  ans = n * m;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &a[i][j]);
  if (m > k) {
    for (k = 0; k < m; k++) {
      int sum = 0;
      for (j = 0; j < m; j++) {
        int now = 0;
        for (i = 0; i < n; i++) {
          if (a[i][j] == a[i][k]) now++;
        }
        sum += std::min(now, n - now);
      }
      ans = std::min(ans, sum);
    }
  } else {
    for (int w = 0; w < (1 << m); w++) {
      int sum = 0;
      for (i = 0; i < n; i++) {
        int now = 0;
        for (j = 0; j < m; j++) {
          if (a[i][j] == ((w >> j) & 1)) now++;
        }
        sum += std::min(now, m - now);
      }
      ans = min(ans, sum);
    }
  }
  if (ans > kk)
    puts("-1");
  else
    printf("%d\n", ans);
}
