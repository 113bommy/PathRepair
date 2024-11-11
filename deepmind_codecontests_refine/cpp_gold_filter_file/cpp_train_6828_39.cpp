#include <bits/stdc++.h>
using namespace std;
int f[100005][105], a[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int m = 100;
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= m; ++j) {
      int k = i + a[i] + j;
      if (k > n)
        f[i][j] = 1;
      else
        f[i][j] = f[k][j] + 1;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int p, k;
    scanf("%d%d", &p, &k);
    if (k > m) {
      int ans = 0;
      while (p <= n) {
        p += a[p] + k;
        ++ans;
      }
      printf("%d\n", ans);
    } else
      printf("%d\n", f[p][k]);
  }
  return 0;
}
