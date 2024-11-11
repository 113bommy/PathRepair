#include <bits/stdc++.h>
using namespace std;
typedef struct ss {
  int x, y;
} S;
int main() {
  int i = 1, j;
  int n, m;
  int L, K = 0, x, y, z, k = 0;
  int q, t;
  int ans = 0, flag = 0, flag1 = 0, flag2 = 0;
  S p[110];
  char a[110][110];
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%s", &a[i]);
  for (i = 0; i < n; i++) {
    flag1 = 0;
    for (j = 0; j < n; j++) {
      if (a[i][j] == '.') {
        p[k].x = i + 1;
        p[k].y = j + 1;
        k++;
        flag1 = 1;
        break;
      }
    }
    if (flag1 == 0) break;
  }
  if (flag1 == 0) {
    k = 0;
    for (i = 0; i < n; i++) {
      flag2 = 0;
      for (j = 0; j < n; j++) {
        if (a[j][i] == '.') {
          p[k].x = j + 1;
          p[k].y = i + 1;
          k++;
          flag2 = 1;
          break;
        }
      }
      if (flag2 == 0) break;
    }
    if (flag2 == 0)
      printf("-1\n");
    else {
      for (i = 0; i < k; i++) printf("%d %d\n", p[i].x, p[i].y);
    }
  } else {
    for (i = 0; i < k; i++) printf("%d %d\n", p[i].x, p[i].y);
  }
}
