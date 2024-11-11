#include <bits/stdc++.h>
using namespace std;
int g[110][110];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (n * m == 2 || n * m == 3)
    printf("-1\n");
  else if (n == 2 && m == 2)
    printf("-1\n");
  else if (n * m == 4) {
    if (n == 4)
      printf("1\n3\n2\n4\n");
    else
      printf("1 3 2 4\n");
  } else {
    if (n > m) {
      int id = 0;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
          if ((i + j) % 2 == 0) g[i][j] = ++id;
        }
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
          if ((i + j) % 2 == 1) g[i][j] = ++id;
        }
    } else {
      int id = 0;
      for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
          if ((i + j) % 2 == 0) g[i][j] = ++id;
        }
      for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
          if ((i + j) % 2 == 1) g[i][j] = ++id;
        }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d", g[i][j]);
        if (j == m - 1)
          printf("\n");
        else
          printf(" ");
      }
    }
  }
  return 0;
}
