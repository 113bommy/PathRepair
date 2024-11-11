#include <bits/stdc++.h>
using namespace std;
int now[6];
int a[50005][6];
int ans[50005];
int main() {
  int n, m;
  int i, j, k;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 1; i <= n; ++i)
      for (j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
    for (i = 0; i <= m; ++i) now[i] = 0;
    for (i = 1; i <= n; ++i) {
      for (j = 1; j <= m; ++j) now[j] = max(now[j - 1], now[j]) + a[i][j];
      ans[i] = now[m];
    }
    for (i = 1; i <= n; ++i) {
      if (i != 1) printf(" ");
      printf("%d", ans[i]);
    }
    puts("");
  }
}
