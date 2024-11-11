#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int s[1005][1005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(a, 0, sizeof(a));
  memset(s, 0, sizeof(a));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j == 1) {
        if (a[i][j] == 0) s[i][j] = 1;
      } else {
        if (a[i][j] == 0)
          s[i][j] = s[i][j - 1] + 1;
        else
          s[i][j] = s[i][j - 1];
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = -1;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1) {
        if (tmp == -1) {
          tmp = j;
          ans += s[i][m];
        } else {
          ans += s[i][j] - s[i][tmp - 1];
          tmp = j;
        }
      }
    }
  }
  memset(s, 0, sizeof(s));
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        if (a[i][j] == 0) s[i][j] = 1;
      } else {
        if (a[i][j] == 0)
          s[i][j] = s[i - 1][j] + 1;
        else
          s[i][j] = s[i - 1][j];
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    int tmp = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i][j] == 1) {
        if (tmp == -1) {
          tmp = i;
          ans += s[n][j];
        } else {
          ans += s[i][j] - s[tmp - 1][j];
          tmp = i;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
