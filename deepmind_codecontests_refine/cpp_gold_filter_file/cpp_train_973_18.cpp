#include <bits/stdc++.h>
using namespace std;
int a[110][40], n;
int b[110][110], ans[110];
int main() {
  scanf("%d", &n);
  int ma = 0, tmp, i;
  memset(a, 0, sizeof(a));
  for (i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
      ma = max(ma, b[i][j]);
    }
  i = 0;
  tmp = ma;
  while (ma) {
    for (int j = 0; j < n; j++)
      for (int k = j + 1; k < n; k++) {
        if (b[j][k] & (1 << i)) a[j][i] = 1, a[k][i] = 1;
      }
    i++;
    ma /= 2;
  }
  for (int j = 0; j < n; j++) {
    ans[j] = i = 0;
    ma = tmp;
    while (ma) {
      ans[j] += a[j][i] * (1 << i);
      i++;
      ma /= 2;
    }
  }
  for (int j = 0; j < n; j++) {
    printf("%d", ans[j]);
    if (j == n - 1)
      printf("\n");
    else
      printf(" ");
  }
}
