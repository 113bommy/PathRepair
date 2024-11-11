#include <bits/stdc++.h>
char s[110][110];
int u[110][110];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(u, 0, sizeof(u));
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (k != i && s[k][j] == s[i][j]) {
          u[i][j] = 1, u[k][j] = 1;
        }
      }
      for (int k = 0; k < m; k++) {
        if (k != j && s[i][k] == s[i][j]) {
          u[i][j] = 1, u[i][k] = 1;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (u[i][j] == 0) printf("%c", s[i][j]);
    }
  }
  printf("\n");
  return 0;
}
