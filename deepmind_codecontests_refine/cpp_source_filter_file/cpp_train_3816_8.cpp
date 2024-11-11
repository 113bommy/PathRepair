#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[505][505];
int main() {
  scanf("%d%d", &n, &m);
  char c = getchar();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      c = getchar();
      if (c == 'S')
        s[i][j] = 0;
      else if (c == 'W')
        s[i][j] = 1;
      else
        s[i][j] = 2;
    }
    getchar();
  }
  bool f = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 1) {
        if (i > 1 && s[i - 1][j] == 0) f = 1;
        if (j > 1 && s[i][j - 1] == 0) f = 1;
        if (i < n && s[i + 1][j] == 0) f = 1;
        if (j < n && s[i][j + 1] == 0) f = 1;
      }
    }
  }
  if (f) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 0) {
        printf("S");
      } else if (s[i][j] == 1)
        printf("W");
      else
        printf("D");
    }
    printf("\n");
  }
  return 0;
}
