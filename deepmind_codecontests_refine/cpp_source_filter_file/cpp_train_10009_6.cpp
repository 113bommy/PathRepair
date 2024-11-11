#include <bits/stdc++.h>
using namespace std;
const int N = 1009;
int a[N][N];
int R[N], C[N], r[N][N], c[N][N], x[N];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) x[j] = a[i][j];
    sort(x + 1, x + m + 1);
    int temp = unique(x + 1, x + m + 1) - x - 1;
    R[i] = temp;
    for (int j = 1; j <= m; ++j)
      r[i][j] = lower_bound(x + 1, x + m + 1, a[i][j]) - x;
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) x[i] = a[i][j];
    sort(x + 1, x + n + 1);
    int temp = unique(x + 1, x + n + 1) - x - 1;
    C[j] = temp;
    for (int i = 1; i <= n; ++i)
      c[i][j] = lower_bound(x + 1, x + n + 1, a[i][j]) - x;
  }
  int ans;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int cc = c[i][j], rr = r[i][j];
      ans = 10000000;
      if (cc >= rr) ans = min(ans, max(C[j], R[i] + cc - rr));
      if (rr >= cc) ans = min(ans, max(R[i], C[j] + rr - cc));
      printf("%d ", ans);
    }
    printf("\n");
  }
  return 0;
}
