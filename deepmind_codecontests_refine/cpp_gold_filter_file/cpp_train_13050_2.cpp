#include <bits/stdc++.h>
int n;
int cl[100];
int c[100][100];
int sl[100];
int stack[2504][5];
int stl = 0;
void process() {
  int i, j, k, l, m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < cl[i]; j++) {
      m = 0;
      if (i > 0) m = sl[i - 1];
      m += j + 1;
      if (c[i][j] == m) continue;
      for (k = i; k < n; k++) {
        for (l = 0; l < cl[k]; l++) {
          if (c[k][l] == m) break;
        }
        if (l < cl[k]) break;
      }
      stack[stl][0] = i + 1;
      stack[stl][1] = j + 1;
      stack[stl][2] = k + 1;
      stack[stl][3] = l + 1;
      c[i][j] ^= c[k][l] ^= c[i][j] ^= c[k][l];
      stl++;
    }
  }
  printf("%d\n", stl);
  for (i = 0; i < stl; i++) {
    printf("%d %d %d %d\n", stack[i][0], stack[i][1], stack[i][2], stack[i][3]);
  }
}
int main() {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &cl[i]);
    sl[i] = cl[i];
    if (i > 0) sl[i] += sl[i - 1];
  }
  for (i = 0; i < n; i++)
    for (j = 0; j < cl[i]; j++) scanf("%d", &c[i][j]);
  process();
}
