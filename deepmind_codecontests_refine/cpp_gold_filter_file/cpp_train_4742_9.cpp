#include <bits/stdc++.h>
bool A[102][102];
bool DFS(int x, int y) {
  A[x][y] = false;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (A[x + i][y + j]) DFS(x + i, y + j);
    }
  }
  return true;
}
int main() {
  int R, C;
  scanf("%d %d\n", &R, &C);
  for (int i = 1; i <= R; i++) {
    char a;
    for (int j = 1; j <= C; j++) {
      scanf("%c", &a);
      if (a == 'B')
        A[i][j] = true;
      else
        A[i][j] = false;
    }
    scanf("%c", &a);
  }
  int ans = 0;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (A[i][j]) {
        ans += DFS(i, j);
      }
    }
  }
  printf("%d", ans);
  return 0;
}
