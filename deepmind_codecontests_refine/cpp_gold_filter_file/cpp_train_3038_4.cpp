#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n][n], cur = 0;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i % 4 == 0 && j == 0)
        a[i][j] = cur, cur += 4 * n;
      else if (j == 0)
        a[i][j] = a[i - 1][j] + 4;
      else if (j % 4 == 0)
        a[i][j] = a[i][j - 1] + 13;
      else
        a[i][j] = a[i][j - 1] + 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) printf("%d ", a[i][j]);
    printf("\n");
  }
  return 0;
}
