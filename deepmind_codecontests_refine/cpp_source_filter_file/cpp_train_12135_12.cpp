#include <bits/stdc++.h>
using namespace std;
int a[25][25];
bool check(int r, int c) {
  int n, i, j;
  for (i = 1; i <= r; i++) {
    n = 0;
    for (j = 1; j <= c; j++)
      if (a[r][j] != j) n++;
    if (n > 2) return false;
  }
  return true;
}
int main() {
  int r, c, n, i, j, k, t;
  scanf("%d%d", &r, &c);
  for (i = 1; i <= r; i++) {
    for (j = 1; j <= c; j++) scanf("%d", &a[i][j]);
  }
  if (check(r, c)) {
    printf("YES\n");
    return 0;
  }
  int flag = 1;
  for (i = 1; i <= c; i++)
    for (j = i + 1; j <= c; j++) {
      for (k = 1; k <= r; k++) swap(a[k][i], a[k][j]);
      if (check(r, c)) {
        printf("YES\n");
        return 0;
      }
      for (k = 1; k <= r; k++) swap(a[k][i], a[k][j]);
    }
  printf("NO\n");
  return 0;
}
