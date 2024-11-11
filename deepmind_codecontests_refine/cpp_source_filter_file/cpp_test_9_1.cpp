#include <bits/stdc++.h>
int grid[1001][1001];
int start[100000];
int main(void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &grid[i][j]);
    }
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &start[i]);
  }
  for (int i = 0; i < k; i++) {
    int r = 1;
    int c = start[i];
    while (r < n) {
      int rr, cc;
      switch (grid[r][c]) {
        case 1:
          rr = r;
          cc = c + 1;
          break;
        case 2:
          rr = r + 1;
          cc = c;
          break;
        case 3:
          rr = r;
          cc = c - 1;
          break;
      }
      grid[r][c] = 2;
      r = rr;
      c = cc;
    }
    printf("%d ", c);
  }
}
