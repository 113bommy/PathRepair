#include <bits/stdc++.h>
int field[600][600];
int main() {
  int x, y, x0, y0;
  char s[100001];
  int i, cnt = 1;
  scanf("%d %d %d %d\n", &x, &y, &x0, &y0);
  gets(s);
  printf("1 ");
  field[x0][y0] = 1;
  for (i = 0; s[i] != 0; i++) {
    if (s[i] == 'U' && x0 > 1)
      --x0;
    else if (s[i] == 'D' && x0 < x)
      ++x0;
    else if (s[i] == 'L' && y0 > 1)
      --y0;
    else if (s[i] == 'R' && y0 < y)
      ++y0;
    if (s[i + 1] == 0)
      printf("%d ", x * y - cnt);
    else if (!field[x0][y0]) {
      printf("1 ");
      field[x0][y0] = 1;
      ++cnt;
    } else if (field[x0][y0])
      printf("0 ");
  }
  return 0;
}
