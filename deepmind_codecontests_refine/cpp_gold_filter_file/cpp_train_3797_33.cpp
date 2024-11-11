#include <bits/stdc++.h>
using namespace std;
char s[55], t[55];
int f[55][55][26], g[55][55][26];
int h[55][55];
int a[55][3];
int n, m;
int an;
int main() {
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);
  scanf("%d", &an);
  for (int i = 0; i < an; i++) {
    char buf[10];
    scanf("%s", buf);
    a[i][0] = buf[0] - 'a';
    a[i][1] = buf[3] - 'a';
    a[i][2] = buf[4] - 'a';
  }
  for (int i = 0; i < n; i++) f[i][i][s[i] - 'a'] = 1;
  for (int l = 2; l <= n; l++)
    for (int i = 0; i + l <= n; i++) {
      int j = i + l - 1;
      for (int p = 0; p < an; p++)
        for (int k = i; k < j; k++)
          if (f[i][k][a[p][1]] && f[k + 1][j][a[p][2]]) {
            f[i][j][a[p][0]] = 1;
            break;
          }
    }
  for (int i = 0; i < m; i++) g[i][i][t[i] - 'a'] = 1;
  for (int l = 2; l <= m; l++)
    for (int i = 0; i + l <= m; i++) {
      int j = i + l - 1;
      for (int p = 0; p < an; p++)
        for (int k = i; k < j; k++)
          if (g[i][k][a[p][1]] && g[k + 1][j][a[p][2]]) {
            g[i][j][a[p][0]] = 1;
            break;
          }
    }
  memset(h, -1, sizeof(h));
  h[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      for (int c = 0; c < 26; c++)
        for (int k = 0; k < i; k++)
          for (int l = 0; l < j; l++)
            if (h[k][l] > -1) {
              if (f[k][i - 1][c] && g[l][j - 1][c])
                if (h[i][j] == -1 || h[k][l] + 1 < h[i][j])
                  h[i][j] = h[k][l] + 1;
            }
    }
  printf("%d\n", h[n][m]);
  return 0;
}
