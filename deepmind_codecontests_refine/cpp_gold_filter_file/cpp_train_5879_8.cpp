#include <bits/stdc++.h>
const char *pat[] = {"#//.", "\\#.\\", "\\.#\\", ".//#", "....", "####"};
int n, m;
int a, b, c;
int chs[128][128];
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  scanf("%d%d", &a, &b, &c);
  int p = 0;
  for (i = 0; i < a; i++, p++) chs[p / m][p % m] = 5;
  int flag = p % m;
  for (i = 0; i < m; i++, p++)
    chs[p / m][p % m] = !((p % m - flag) % 2) ^ (p % m < flag) ? 0 : 1;
  for (i = 0; i < b; i++, p++) chs[p / m][p % m] = 4;
  for (; p < n * m; p++)
    for (i = 0; i < 4; i++) {
      int x = p / m, y = p % m;
      if ((chs[x - 1][y] ^ i) & 2 && (y == 0 || (chs[x][y - 1] ^ i) & 1)) {
        chs[p / m][p % m] = i;
        break;
      }
    }
  for (i = 0; i < 2 * n; i++) {
    for (j = 0; j < 2 * m; j++)
      printf("%c", pat[chs[i / 2][j / 2]][i % 2 * 2 + j % 2]);
    printf("\n");
  }
  return 0;
}
