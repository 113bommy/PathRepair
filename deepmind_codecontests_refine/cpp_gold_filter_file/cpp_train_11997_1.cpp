#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int a[60][60];
int up[60][60];
int lft[60][60];
int rht[60][60];
int dwn[60][60];
int m, n;
struct pointer {
  int i, j;
};
void Init() {
  int i, j;
  for (i = 1; i <= n; i++) {
    lft[i][1] = 1;
    for (j = 2; j <= m; j++)
      if (a[i][j] == a[i][j - 1])
        lft[i][j] = lft[i][j - 1];
      else
        lft[i][j] = j;
    rht[i][m] = m;
    for (j = m - 1; j >= 0; j--)
      if (a[i][j] == a[i][j + 1])
        rht[i][j] = rht[i][j + 1];
      else
        rht[i][j] = j;
  }
  for (j = 1; j <= m; j++) {
    up[1][j] = 1;
    for (i = 1; i <= n; i++)
      if (a[i][j] == a[i - 1][j])
        up[i][j] = up[i - 1][j];
      else
        up[i][j] = i;
    dwn[n][j] = n;
    for (i = n - 1; i >= 0; i--)
      if (a[i][j] == a[i + 1][j])
        dwn[i][j] = dwn[i + 1][j];
      else
        dwn[i][j] = i;
  }
}
int main() {
  pointer bp;
  int tmp, cp = -1;
  int dp = 1;
  int i, j, nn;
  char s[60];
  scanf("%d%d", &n, &nn);
  memset(a, 0, sizeof(a));
  for (i = 1; i <= n; i++) {
    scanf("%s", s);
    m = strlen(s);
    for (j = 0; j < m; j++) a[i][j + 1] = s[j] - '0';
  }
  Init();
  bp.i = 1;
  bp.j = 1;
  for (int cnt = 0; cnt < nn; cnt++) {
    i = bp.i;
    j = bp.j;
    switch (dp) {
      case 0:
        i = up[i][j];
        break;
      case 1:
        j = rht[i][j];
        break;
      case 2:
        i = dwn[i][j];
        break;
      case 3:
        j = lft[i][j];
    }
    tmp = (dp + cp + 4) % 4;
    switch (tmp) {
      case 0:
        i = up[i][j];
        break;
      case 1:
        j = rht[i][j];
        break;
      case 2:
        i = dwn[i][j];
        break;
      case 3:
        j = lft[i][j];
    }
    switch (dp) {
      case 0:
        i--;
        break;
      case 1:
        j++;
        break;
      case 2:
        i++;
        break;
      case 3:
        j--;
    }
    if (a[i][j]) {
      bp.i = i;
      bp.j = j;
    } else if (cp == -1)
      cp = 1;
    else {
      cp = -1;
      dp = (dp + 1) % 4;
    }
  }
  printf("%d\n", a[bp.i][bp.j]);
  return 0;
}
