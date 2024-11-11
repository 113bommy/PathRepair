#include <bits/stdc++.h>
const int maxn = 100;
int k;
bool a[maxn + 10][maxn + 10];
int main() {
  scanf("%d", &k);
  for (int i = 1; i <= maxn; ++i)
    for (int j = 1; j < i; ++j) {
      int now = 0;
      for (int k = 1; k <= maxn; ++k)
        if (a[i][k] && a[k][j]) ++now;
      if (k >= now) k -= now, a[i][j] = a[j][i] = 1;
    }
  printf("%d\n", maxn);
  for (int i = 1; i <= maxn; ++i) {
    for (int j = 1; j <= maxn; ++j) printf("%d", a[i][j]);
    printf("\n");
  }
  return 0;
}
