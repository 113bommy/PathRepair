#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  char a[52][52] = {{0}};
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) a[i][j] = '.';
  for (i = 0; i < n; i = i + 2)
    for (j = 0; j < m; j++) a[i][j] = '#';
  for (i = 1; i < n; i = i + 4) {
    a[i][m - 1] = '#';
  }
  for (i = 3; i < n; i++) a[i][0] = '#';
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%c", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
