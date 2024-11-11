#include <bits/stdc++.h>
int n, m;
int f[405][405][55];
int s[405];
void DISP(int k) {
  int i, j;
  printf("\n");
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) printf("%d ", f[i][j][k]);
    printf("\n");
  }
}
int G(int x, int y) { return x > y ? x - y : y - x; }
void DP() {
  int i, j, k, l, L, ans = 0;
  memset(f, 0, sizeof(f));
  for (i = 1, s[0] = 0; i <= n; i++) {
    scanf("%d", &s[i]);
    s[i] += s[i - 1];
  }
  for (k = 2; k <= m; k++)
    for (i = 2; i <= n; i++)
      for (j = i - 1; j >= k - 1; j--)
        for (l = j - 1; l >= k - 2; l--) {
          f[i][j][k] = f[i][j][k] > f[j][l][k - 1] + G(s[i] - s[j], s[j] - s[l])
                           ? f[i][j][k]
                           : f[j][l][k - 1] + G(s[i] - s[j], s[j] - s[l]);
        }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) ans = ans > f[i][j][m] ? ans : f[i][j][m];
  printf("%d\n", ans);
}
int main() {
  while (~scanf("%d%d", &n, &m)) DP();
  return 0;
}
