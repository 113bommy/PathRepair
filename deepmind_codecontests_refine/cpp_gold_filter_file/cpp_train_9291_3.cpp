#include <bits/stdc++.h>
const int N = 1000010;
const int MOD = 1e9 + 7;
using namespace std;
int n, m;
int f[310][310], a[310];
int main() {
  int _ = 1;
  scanf("%d", &_);
  while (_--) {
    memset(f, 0, sizeof(f));
    scanf("%d %d", &n, &m);
    if (m % n == 0)
      printf("0\n");
    else
      printf("2\n");
    if (m <= n)
      for (int i = 1; i <= m; ++i) f[i][i] = 1;
    else {
      for (int i = 1; i <= n; ++i) f[i][i] = 1;
      for (int i = 1; i <= n; ++i) a[i] = i;
      for (int i = 1; i <= (m - n) / n; ++i)
        for (int j = 1; j <= n; ++j) a[j] = a[j] % n + 1, f[j][a[j]] = 1;
      for (int j = 1; j <= m % n; ++j) a[j] = a[j] % n + 1, f[j][a[j]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) printf("%d", f[i][j]);
      printf("\n");
    }
  }
  return 0;
}
