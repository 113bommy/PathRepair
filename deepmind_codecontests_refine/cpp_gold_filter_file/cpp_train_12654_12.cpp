#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, x, y;
long long a[505][505], s, s1, s2;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      scanf("%d", a[i] + j);
      if (a[i][j] == 0) x = i, y = j;
    }
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  if (x == 0) k = 1;
  for (i = 0; i < n; i++) s += a[k][i];
  for (i = 0; i < n; i++) s1 += a[x][i];
  a[x][y] = s - s1;
  if (a[x][y] < 1) {
    printf("-1\n");
    return 0;
  }
  for (i = 0; i < n; i++) {
    s1 = 0;
    s2 = 0;
    for (j = 0; j < n; j++) {
      s1 += a[i][j];
      s2 += a[j][i];
    }
    if (s1 != s || s2 != s) {
      printf("-1\n");
      return 0;
    }
  }
  s1 = 0;
  s2 = 0;
  for (i = 0; i < n; i++) {
    s1 += a[i][i];
    s2 += a[i][n - 1 - i];
  }
  if (s1 != s || s2 != s) {
    printf("-1\n");
    return 0;
  }
  printf("%I64d\n", a[x][y]);
  return 0;
}
