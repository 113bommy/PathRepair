#include <bits/stdc++.h>
#pragma comment(linker, "/stack:16000000")
int main() {
  bool g[2000][2000] = {}, row[2000], col[2000];
  int i, j, k, n, res = 0;
  char ch;
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%c", &ch);
      g[i][j] = ch == '0';
    }
    scanf("\n");
  }
  memset(row, 0, 2000 * sizeof(bool));
  memset(col, 0, 2000 * sizeof(bool));
  for (i = 0; i < n; i++) {
    for (j = n - 1; j > i; j--)
      if (g[i][j] ^ col[i] ^ row[j]) {
        res++;
        col[i] ^= 1;
        row[j] ^= 1;
      }
    g[i][i] ^= col[i] ^ row[i];
  }
  memset(row, 0, 2000 * sizeof(bool));
  memset(col, 0, 2000 * sizeof(bool));
  for (i = n - 1; i >= 0; i--) {
    for (j = 0; j < i; j++)
      if (g[i][j] ^ col[i] ^ row[j]) {
        res++;
        col[i] ^= 1;
        row[j] ^= 1;
      }
    g[i][i] ^= col[i] ^ row[i];
  }
  for (i = 0; i < n; i++)
    if (g[i][i]) res++;
  printf("%d", res);
  return 0;
}
