#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int a[maxn][2];
int b[maxn];
int q[maxn][maxn];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    q[x][y] = 1;
    q[y][x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (q[i][j] == 0) {
        if ((a[i][0] && a[j][0]) || (a[i][1] && a[j][1])) {
          printf("No\n");
          return 0;
        }
        if (a[i][0] && a[j][1]) continue;
        if (a[i][1] && a[j][0]) continue;
        if (a[i][0])
          a[j][1] = 1;
        else if (a[i][1])
          a[j][0] = 1;
        else if (a[j][0])
          a[i][1] = 1;
        else if (a[j][1])
          a[i][0] = 1;
        else {
          a[i][0] = 1;
          a[j][1] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i][0] && a[i][1]) {
      printf("No\n");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (q[i][j]) continue;
      for (int k = 1; k <= n; k++) {
        if (k == i || k == j) continue;
        if (q[i][k] && q[j][k]) {
          if (a[k][0] || a[k][1]) {
            printf("No\n");
            return 0;
          }
          b[k] = 1;
        }
      }
    }
  }
  printf("Yes\n");
  for (int i = 1; i <= n; i++) {
    if (b[i])
      printf("b");
    else if (a[i][0])
      printf("a");
    else
      printf("c");
  }
  printf("\n");
  return 0;
}
