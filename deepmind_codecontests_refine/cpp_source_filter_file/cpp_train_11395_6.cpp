#include <bits/stdc++.h>
using namespace std;
int ans[200][200];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 1 && m == 1) {
    printf("1\n");
    return 0;
  }
  if (n * m <= 2 || n == 2 && m == 2) {
    printf("-1\n");
    return 0;
  }
  int x, y;
  x = 1;
  y = 0;
  bool f = 0;
  if (n > m) {
    swap(n, m);
    f = 1;
  }
  if (n == 2 && m == 3) {
    ans[0][0] = 3;
    ans[0][1] = 6;
    ans[0][2] = 2;
    ans[1][0] = 5;
    ans[1][1] = 1;
    ans[1][2] = 4;
  } else {
    if (n == 1 && m == 4) {
      ans[0][0] = 3;
      ans[0][1] = 1;
      ans[0][2] = 4;
      ans[0][3] = 2;
    } else {
      for (int i = 1; i <= n * m; i++) {
        ans[y / m][y % m] = x;
        y += 2;
        x++;
        if (i == (n * m + 1) / 2) y = 1;
      }
    }
  }
  if (f == 1) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (j != 0) printf(" ");
        printf("%d", ans[j][i]);
      }
      printf("\n");
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (j != 0) printf(" ");
        printf("%d", ans[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
