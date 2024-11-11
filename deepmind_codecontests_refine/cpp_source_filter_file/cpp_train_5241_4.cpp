#include <bits/stdc++.h>
int C, n, a[2010][2010], b[2010][2010], Cir, Rec, bl[2010][2010],
    x[2010 * 2010], y[2010 * 2010];
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void Bfs(int A, int B) {
  int h, t, MidX, MidY, k, i, R2(0);
  long long SumX(A), SumY(B);
  double ForCir, ForRec;
  x[0] = A;
  y[0] = B;
  t = 1;
  for (h = 0; h < t; h++)
    for (k = 0; k < 4; k++)
      if (x[h] + dx[k] >= 0 && x[h] + dx[k] < n && y[h] + dy[k] >= 0 &&
          y[h] + dy[k] < n && !bl[x[h] + dx[k]][y[h] + dy[k]] &&
          b[x[h] + dx[k]][y[h] + dy[k]]) {
        x[t] = x[h] + dx[k];
        y[t] = y[h] + dy[k];
        bl[x[t]][y[t]] = 1;
        SumX += x[t];
        SumY += y[t];
        t++;
      }
  if (t < 50) return;
  MidX = SumX / t;
  MidY = SumY / t;
  for (i = 0; i < t; i++)
    if ((x[i] - MidX) * (x[i] - MidX) + (y[i] - MidY) * (y[i] - MidY) > R2)
      R2 = (x[i] - MidX) * (x[i] - MidX) + (y[i] - MidY) * (y[i] - MidY);
  ForCir = (3.1415926 * R2) / t;
  ForRec = t / (2.0 * R2) * 1.5;
  if (ForCir <= ForRec)
    Cir++;
  else
    Rec++;
}
int main() {
  int i, j, k, l;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) scanf("%d", a[i] + j);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      C = 0;
      for (k = -3; k <= 3; k++)
        for (l = -3; l <= 3; l++)
          if (i + k >= 0 && i + k < n && j + l >= 0 && j + l < n &&
              k * k + l * l <= 10 && a[i + k][j + l] != a[i][j])
            C++;
      b[i][j] = a[i][j];
      if (C >= 20) b[i][j] ^= 1;
    }
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (!bl[i][j] && b[i][j]) Bfs(i, j);
  printf("%d %d\n", Cir, Rec);
  return 0;
}
