#include <bits/stdc++.h>
int a, b, c, d, e, f[55][55][36], g[55][55][36], h, i, j, k;
char u[105], v[105], w[105];
struct node {
  int q, x, y;
};
struct node change[55];
int len1, len2;
int F[55][55][36], G[55][55][36];
int T[55][55];
int Min(int x, int y) {
  if (x < y) return x;
  return y;
}
void make(char x[]) {
  int ii, jj, kk;
  d = strlen(x);
  for (i = 0; i < d; i++) f[i][i][x[i] - 'a' + 1] = 1;
  for (k = 2; k <= d; k++)
    for (i = 0; i < d && i + k - 1 < d; i++) {
      j = i + k - 1;
      for (e = 1; e <= a; e++)
        for (h = i; h < j; h++)
          f[i][j][change[e].q] |=
              f[i][h][change[e].x] & f[h + 1][j][change[e].y];
    }
}
int main() {
  scanf("%s", u);
  scanf("%s", v);
  scanf("%d", &a);
  for (i = 1; i <= a; i++) {
    scanf("%s", w);
    change[i].q = w[0] - 'a' + 1;
    change[i].x = w[3] - 'a' + 1;
    change[i].y = w[4] - 'a' + 1;
  }
  len1 = strlen(u);
  len2 = strlen(v);
  make(u);
  for (i = 0; i < len1; i++)
    for (j = 0; j < len1; j++)
      for (e = 1; e <= 26; e++) F[i][j][e] = f[i][j][e];
  memset(f, 0, sizeof(f));
  make(v);
  for (i = 0; i < len2; i++)
    for (j = 0; j < len2; j++)
      for (e = 1; e <= 26; e++) G[i][j][e] = f[i][j][e];
  for (i = 0; i <= len1; i++)
    for (j = 0; j <= len2; j++) T[i][j] = 1 << 30;
  T[0][0] = 0;
  for (i = 1; i <= len1; i++)
    for (j = 1; j <= len2; j++)
      for (e = 1; e <= 24; e++) {
        for (c = 1; c <= i; c++)
          if (F[c - 1][i - 1][e])
            for (d = 1; d <= j; d++)
              if (G[d - 1][j - 1][e])
                T[i][j] = Min(T[i][j], T[c - 1][d - 1] + 1);
      }
  if (T[len1][len2] < 1 << 30)
    printf("%d\n", T[len1][len2]);
  else
    printf("-1\n");
  return 0;
}
