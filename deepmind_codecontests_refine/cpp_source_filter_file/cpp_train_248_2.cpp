#include <bits/stdc++.h>
int i, j, n, H[1005][1005], m, k, s;
char arr[1005][1005], adim;
void dfs(int i, int j) {
  if (i < 1 or i > n or j < 1 or j > m or H[i][j]) return;
  adim++;
  H[i][j] = 1;
  if (adim == s - k) {
    for (int t = 1; t <= n; t++, puts(""))
      for (int l = 1; l <= m; l++)
        if (H[t][l] and arr[t][l] == '.')
          printf(".");
        else if (!H[t][l] and arr[t][l] == '.')
          printf("X");
        else
          printf("#");
    exit(0);
  }
  if (arr[i + 1][j] == '.') dfs(i + 1, j);
  if (arr[i - 1][j] == '.') dfs(i - 1, j);
  if (arr[i][j + 1] == '.') dfs(i, j + 1);
  if (arr[i][j - 1] == '.') dfs(i, j - 1);
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      scanf(" %c", &arr[i][j]);
      s += (arr[i][j] == '.');
    }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (arr[i][j] == '.' and !H[i][j]) {
        adim = 0;
        dfs(i, j);
      }
  return 0;
}
