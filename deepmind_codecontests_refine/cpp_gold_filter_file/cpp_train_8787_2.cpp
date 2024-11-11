#include <bits/stdc++.h>
int a[100][100];
int w[60][60];
int w2[60][60];
char s[100];
int abs(int a) {
  if (a < 0) return -a;
  return a;
}
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
int n, m;
int ot[10000][2];
int start = 0;
int end = 0;
void fill(int i, int j, int c) {
  w[i][j] = c;
  if (i > 0)
    if (a[i - 1][j] == a[i][j])
      if (w[i - 1][j] == 0x10101010) fill(i - 1, j, c);
  if (j > 0)
    if (a[i][j - 1] == a[i][j])
      if (w[i][j - 1] == 0x10101010) fill(i, j - 1, c);
  if (i < n - 1)
    if (a[i + 1][j] == a[i][j])
      if (w[i + 1][j] == 0x10101010) fill(i + 1, j, c);
  if (j < m - 1)
    if (a[i][j + 1] == a[i][j])
      if (w[i][j + 1] == 0x10101010) fill(i, j + 1, c);
}
void rec2(int i, int j, int c) {
  fill(i, j, c);
  w2[i][j] = 1;
  if (i > 0)
    if (!w2[i - 1][j])
      if (a[i - 1][j] == a[i][j])
        rec2(i - 1, j, c);
      else if (w[i - 1][j] == 0x10101010) {
        fill(i - 1, j, c + 1);
        ot[end][0] = i - 1;
        ot[end][1] = j;
        end++;
      }
  if (j > 0)
    if (!w2[i][j - 1])
      if (a[i][j - 1] == a[i][j])
        rec2(i, j - 1, c);
      else if (w[i][j - 1] == 0x10101010) {
        fill(i, j - 1, c + 1);
        ot[end][0] = i;
        ot[end][1] = j - 1;
        end++;
      }
  if (i < n - 1)
    if (!w2[i + 1][j])
      if (a[i + 1][j] == a[i][j])
        rec2(i + 1, j, c);
      else if (w[i + 1][j] == 0x10101010) {
        fill(i + 1, j, c + 1);
        ot[end][0] = i + 1;
        ot[end][1] = j;
        end++;
      }
  if (j < m - 1)
    if (!w2[i][j + 1])
      if (a[i][j + 1] == a[i][j])
        rec2(i, j + 1, c);
      else if (w[i][j + 1] == 0x10101010) {
        fill(i, j + 1, c + 1);
        ot[end][0] = i;
        ot[end][1] = j + 1;
        end++;
      }
}
void rec(int i, int j, int c) {
  start = 0;
  end = 0;
  ot[0][0] = i;
  ot[0][1] = j;
  end = 1;
  w[i][j] = 0;
  while (start < end) {
    rec2(ot[start][0], ot[start][1], w[ot[start][0]][ot[start][1]]);
    start++;
  }
}
int main() {
  memset(w, 0x10, sizeof(w));
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++)
      if (s[j] == 'W')
        a[i][j] = 0;
      else
        a[i][j] = 1;
  }
  int mi = 10000;
  for (int i1 = 0; i1 < n; i1++)
    for (int j1 = 0; j1 < m; j1++) {
      int max = -1;
      memset(w, 0x10, sizeof(w));
      memset(w2, 0, sizeof(w2));
      rec(i1, j1, 0);
      for (int i2 = 0; i2 < n; i2++)
        for (int j2 = 0; j2 < m; j2++)
          if (a[i2][j2])
            if (w[i2][j2] > max) max = w[i2][j2];
      if (max < mi) mi = max;
    }
  printf("%d", mi + 1);
}
