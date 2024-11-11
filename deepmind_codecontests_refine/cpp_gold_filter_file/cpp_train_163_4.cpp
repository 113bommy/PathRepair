#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, q;
  while (~scanf("%d%d%d", &n, &m, &q)) {
    int i, j, l, k, a[5050], b[5050];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < m; i++) scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + m);
    int ans = 0x7fffffff;
    for (i = 0; i <= m - n; i++) {
      int ma = 0;
      for (j = 0; j < n; j++) {
        ma = max(ma, abs(a[j] - b[i + j]) + abs(b[i + j] - q));
      }
      ans = min(ans, ma);
    }
    printf("%d\n", ans);
  }
  return 0;
}
