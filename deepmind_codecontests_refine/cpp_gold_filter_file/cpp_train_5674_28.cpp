#include <bits/stdc++.h>
const int M = 105;
using namespace std;
int main() {
  int n, m, a[105][105], b[10005];
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= m; i++) {
      int k = -1, flag = -1;
      for (int j = 1; j <= n; j++) {
        if (a[i][j] > flag) {
          flag = a[i][j];
          k = j;
        }
      }
      b[k]++;
    }
    int k = -1, ans;
    for (int i = 1; i <= n * m; i++) {
      if (b[i] > k) {
        k = b[i];
        ans = i;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
