#include <bits/stdc++.h>
char map[105][105];
int main() {
  int n, m;
  int i, j, k;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 0; i < m; i++) {
      scanf("%s", map[i]);
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        printf("%c%c", map[j][i], map[j][i]);
      }
      puts("");
      for (j = 0; j < m; j++) {
        printf("%c%c", map[j][i], map[j][i]);
      }
      puts("");
    }
  }
  return 0;
}
