#include <bits/stdc++.h>
using namespace std;
int f[100][30002];
char a[100][30010];
int main() {
  int n, m;
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) {
    char b[10003];
    scanf("%s", b);
    a[i][0] = '\0';
    strcat(a[i], b);
    strcat(a[i], b);
    strcat(a[i], b);
  }
  int t;
  for (i = 0; i < n; i++) {
    t = INT_MAX;
    for (j = 0; j < 3 * m; j++) {
      {
        if (a[i][j] == '1') t = j;
        if (t == INT_MAX)
          f[i][j] = t;
        else
          f[i][j] = j - t;
      }
    }
  }
  for (i = 0; i < n; i++) {
    t = INT_MAX;
    for (j = 3 * m - 1; j > -1; j--) {
      {
        if (a[i][j] == '1') t = j;
        if (f[i][j] != INT_MAX && f[i][j] > t - j) f[i][j] = t - j;
      }
    }
  }
  int flag = 0, min = INT_MAX, sum;
  for (j = m; j < 2 * m; j++) {
    sum = 0;
    for (i = 0; i < n; i++) {
      if (f[i][j] == INT_MAX) {
        flag = 1;
        break;
      }
      sum += f[i][j];
    }
    if (flag == 1) break;
    if (sum < min) min = sum;
  }
  if (flag == 1)
    printf("-1\n");
  else
    printf("%d\n", min);
  return 0;
}
