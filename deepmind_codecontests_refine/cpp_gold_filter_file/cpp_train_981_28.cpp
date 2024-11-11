#include <bits/stdc++.h>
int map[2001][2001] = {0};
int ans[2001] = {0};
int n, m, k;
char ss[2001];
void show() {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d", map[i][j]);
    }
    printf("\n");
  }
}
int main() {
  int i, j, k;
  scanf("%d %d %d", &n, &m, &k);
  for (i = 0; i < n; i++) {
    scanf("%s", ss);
    for (j = 0; j < m; j++) {
      if (ss[j] == '.') {
        map[i][j] = 0;
      } else if (ss[j] == 'L') {
        map[i][j] = 1;
      } else if (ss[j] == 'R') {
        map[i][j] = 2;
      } else if (ss[j] == 'U') {
        map[i][j] = 4;
      } else {
        map[i][j] = 8;
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (map[i][j] == 1) {
        if (i <= j) ans[j - i]++;
      } else if (map[i][j] == 2) {
        if (i < m - j) ans[i + j]++;
      } else if (map[i][j] == 4) {
        if (!(i & 1)) ans[j]++;
      } else if (map[i][j] == 8) {
      }
    }
  }
  printf("%d", ans[0]);
  for (i = 1; i < m; i++) {
    printf(" %d", ans[i]);
  }
  printf("\n");
  return 0;
}
