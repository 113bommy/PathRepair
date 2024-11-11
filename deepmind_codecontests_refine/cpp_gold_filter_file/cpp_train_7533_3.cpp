#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, c, x, y, z, s, i, j;
bool f;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int A[101][101], C[101][101], C2[101][101];
bool B[101][101];
void color(int i, int j) {
  int k, p, q, x, y;
  bool used[27];
  memset(used, 0, sizeof used);
  for (k = 0; k < 2; k++)
    for (p = 0; p < 2; p++)
      if (i + k < n && j + p < m && A[i + k][j + p] == A[i][j])
        for (q = 0; q < 4; q++) {
          x = i + k + dx[q];
          y = j + p + dy[q];
          if ((x >= 0 && x < n) && (y >= 0 && y < m) && B[x][y])
            used[C[x][y]] = 1;
        }
  for (k = 0; k < 2; k++)
    for (p = 0; p < 2; p++)
      if (i + k < n && j + p < m && A[i + k][j + p] == A[i][j])
        B[i + k][j + p] = 1;
  for (q = 0; used[q]; q++)
    ;
  for (k = 0; k < 2; k++)
    for (p = 0; p < 2; p++)
      if (i + k < n && j + p < m && A[i + k][j + p] == A[i][j])
        C[i + k][j + p] = q;
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
  if ((n * m) & 1) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  if (m & 1) {
    swap(n, m);
    swap(a, b);
    f = 1;
  }
  x = 0;
  y = 0;
  while (c && x + 1 < n) {
    A[x][y] = z;
    A[x][y + 1] = z;
    A[x + 1][y] = z;
    A[x + 1][y + 1] = z;
    y += 2;
    if (y == m) {
      x += 2;
      y = 0;
    }
    c--;
    s += 4;
    z++;
  }
  while (b >= 2 && x + 1 < n) {
    A[x][y] = z;
    A[x + 1][y] = z++;
    A[x][y + 1] = z;
    A[x + 1][y + 1] = z++;
    y += 2;
    if (y == m) {
      x += 2;
      y = 0;
    }
    b -= 2;
    s += 4;
  }
  if (2 * a >= n * m - s) {
    if (y) {
      for (i = y; i < m; i += 2) {
        A[x][i] = z;
        A[x][i + 1] = z++;
        A[x + 1][i] = z;
        A[x + 1][i + 1] = z++;
      }
      x += 2;
      y = 0;
    }
    while (x < n) {
      for (i = 0; i < m; i += 2) A[x][i] = A[x][i + 1] = z++;
      x++;
    }
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        if (!B[i][j]) color(i, j);
    if (f) {
      memcpy(C2, C, sizeof C);
      for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) C[j][i] = C2[i][j];
      swap(n, m);
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) printf("%c", C[i][j] + 'a');
      printf("\n");
    }
  } else
    printf("IMPOSSIBLE\n");
  return 0;
}
