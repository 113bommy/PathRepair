#include <bits/stdc++.h>
char n;
int a[4][4];
int main(int argc, char *agv[]) {
  int i, j;
  for (i = 1; i <= 3; i++) {
    for (j = 1; j <= 3; j++) {
      scanf("%c ", &n);
      if (n == 'X')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  }
  if (a[1][1] == a[3][3] && a[1][2] == a[3][2] && a[1][3] == a[3][1] &&
      a[2][1] == a[2][3])
    printf("YES");
  else
    printf("NO");
  return 0;
}
