#include <bits/stdc++.h>
using namespace std;
int n;
int d[55][55];
int func(int x, int y, int r) {
  if (max(x, y) + r > 50) return 0;
  int sum = 0;
  for (int i = 0; i < r; i++) {
    if (d[x + i][y]) sum++;
    if (d[x][y + i + 1]) sum++;
    if (d[x + i + 1][y + r]) sum++;
    if (d[x + r][y + i]) sum++;
  }
  if (sum == 4 * n) {
    for (int i = 0; i < r; i++) {
      if (d[x + i][y]) d[x + i][y] = 0;
      if (d[x][y + i + 1]) d[x][y + i + 1] = 0;
      if (d[x + i + 1][y + r]) d[x + i + 1][y + r] = 0;
      if (d[x + r][y + i]) d[x + r][y + i] = 0;
    }
    for (int i = 0; i < 55; i++) {
      for (int j = 0; j < 55; j++) {
        if (d[i][j] == 1) printf("%d %d", i, j);
      }
    }
    return 1;
  }
  return 0;
}
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < 4 * n + 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    d[x][y] = 1;
  }
  for (int i = 0; i <= 50; i++) {
    for (int j = 0; j <= 50; j++) {
      for (int k = n; k <= 50; k++) {
        if (func(i, j, k)) return 0;
      }
    }
  }
  return 0;
}
