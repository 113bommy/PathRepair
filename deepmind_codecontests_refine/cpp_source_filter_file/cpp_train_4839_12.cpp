#include <bits/stdc++.h>
const int N = 2017;
char c[N][N];
int U[N][N], D[N][N], L[N][N], R[N][N], W[N][N];
int i, j, m, n;
long long s;
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%s", c[i] + 1);
  for (i = 1; i <= n; i++) L[i][0] = 1, R[i][m + 1] = 1;
  for (i = 1; i <= m; i++) U[0][i] = 1, D[n + 1][i] = 1;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (c[i][j] == '#')
        U[i][j] = 0;
      else
        U[i][j] = U[i - 1][j];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (c[i][j] == '#')
        L[i][j] = 0;
      else
        L[i][j] = L[i][j - 1];
  for (i = n; i > 0; i--)
    for (j = m; j > 0; j--)
      if (c[i][j] == '#')
        D[i][j] = 0;
      else
        D[i][j] = D[i + 1][j];
  for (i = n; i > 0; i--)
    for (j = m; j > 0; j--)
      if (c[i][j] == '#')
        R[i][j] = 0;
      else
        R[i][j] = R[i][j + 1];
  for (i = 2; i < n; i++)
    if (R[i][1]) s++;
  for (i = 2; i < m; i++)
    if (D[1][i]) s++;
  for (i = 2; i < n; i++)
    for (j = 2; j < m; j++)
      if ((U[i][j]) && (L[i][j])) s++;
  for (i = 2; i < n; i++)
    for (j = 2; j < m; j++)
      if ((U[i][j]) && (R[i][j])) s++;
  for (i = 2; i < n; i++)
    for (j = 2; j < m; j++)
      if ((D[i][j]) && (L[i][j])) s++;
  for (i = 2; i < n; i++)
    for (j = 2; j < m; j++)
      if ((D[i][j]) && (R[i][j])) s++;
  for (i = 2; i < n; i++)
    for (j = 2; j < m; j++) {
      W[i][j] = 0;
      if (c[i][j] == '#') continue;
      if (U[i][j]) W[i][j]++;
      if (D[i][j]) W[i][j]++;
      if (c[i][j - 1] != '#') s = s + W[i][j] * W[i][j - 2];
      W[i][j] = W[i][j - 1] + W[i][j];
    }
  for (i = 2; i < n; i++)
    for (j = 2; j < m; j++) {
      W[i][j] = 0;
      if (c[i][j] == '#') continue;
      if (L[i][j]) W[i][j]++;
      if (R[i][j]) W[i][j]++;
      if (c[i - 1][j] != '#') s = s + W[i - 2][j] * W[i][j];
      W[i][j] = W[i - 1][j] + W[i][j];
    }
  for (i = 2; i < n; i++)
    for (j = 2; j < m - 1; j++)
      if ((c[i][j] != '#') && (c[i][j + 1] != '#')) {
        if ((U[i][j]) && (D[i][j + 1])) s++;
        if ((D[i][j]) && (U[i][j + 1])) s++;
      }
  for (i = 2; i < n - 1; i++)
    for (j = 2; j < m; j++)
      if ((c[i][j] != '#') && (c[i + 1][j] != '#')) {
        if ((L[i][j]) && (R[i + 1][j])) s++;
        if ((R[i + 1][j]) && (L[i][j])) s++;
      }
  printf("%I64d", s);
  return 0;
}
