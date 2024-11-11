#include <bits/stdc++.h>
const int N = 50;
int i, j, tot, n;
bool left[N][N], down[N][N];
int main() {
  long long T;
  scanf("%I64d", &T);
  for (i = 0; T; T /= 3, i++) {
    int x = T % 3;
    if (i) {
      tot += 2;
      down[i][i + 3] = left[i + 3][i] = 1;
      if (T >= 3) tot += 2, left[i][i + 4] = down[i + 4][i] = 1;
    }
    if (x < 2) tot++, left[i + 1][i + 3] = 1;
    if (x < 1) tot++, down[i + 3][i + 1] = 1;
  }
  left[i + 1][i + 2] = left[i + 2][i + 2] = 1;
  down[i + 2][i + 1] = down[i + 2][i + 2] = 1;
  n = i + 3;
  printf("%d %d\n%d\n", n, n, tot + 4);
  for (i = 1; i < n; i++)
    for (j = 1; j < n; j++) {
      if (left[i][j]) printf("%d %d %d %d\n", i, j, i, j + 1);
      if (down[i][j]) printf("%d %d %d %d\n", i, j, i + 1, j);
    }
}
