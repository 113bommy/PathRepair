#include <bits/stdc++.h>
using namespace std;
char str[104][104];
int main() {
  int n, m, i, j, k;
  while (scanf("%d%d", &n, &m) == 2) {
    gets(str[0]);
    for (i = 0; i < n; i++) {
      gets(str[i]);
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        for (k = 0; k < n; k++) {
          if (k == j) continue;
          if (str[i][j] == str[i][k]) break;
        }
        if (k == n) {
          for (k = 0; k < m; k++) {
            if (k == i) continue;
            if (str[i][j] == str[k][j]) break;
          }
          if (k == m) printf("%c", str[i][j]);
        }
      }
    }
    printf("\n");
  }
  return 0;
}
