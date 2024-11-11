#include <bits/stdc++.h>
using namespace std;
bool a[3][102];
int x, y, ans;
int main() {
  int i, j;
  char s1[102], s2[102];
  scanf("%s", s1);
  scanf("%s", s2);
  for (i = 0; i < strlen(s1); i++) {
    if (s1[i] == '0') a[0][i] = 1;
    if (s2[i] == '0') a[1][i] = 1;
  }
  while (y <= strlen(s1)) {
    if (a[x][y] && a[x + 1][y] && a[x][y + 1]) {
      ans++, a[x][y] = a[x + 1][y] = a[x][y + 1] = 0, y++, x = 1;
      continue;
    }
    if (a[x][y] && a[x + 1][y] && a[x + 1][y + 1]) {
      ans++, a[x][y] = a[x + 1][y] = a[x + 1][y + 1] = 0, y++, x = 0;
      continue;
    }
    if (a[x][y] && a[x][y + 1] && a[x + 1][y + 1]) {
      ans++, a[x][y] = a[x][y + 1] = a[x + 1][y + 1] = 0, y += 2, x = 0;
      continue;
    }
    if (x == 1 && a[x][y] && a[x][y + 1] && a[x - 1][y + 1]) {
      ans++, a[x][y] = a[x][y + 1] = a[x - 1][y + 1] = 0, y += 2, x = 0;
      continue;
    }
    if (x == 0)
      x++;
    else
      y++, x = 0;
  }
  printf("%d", ans);
}
