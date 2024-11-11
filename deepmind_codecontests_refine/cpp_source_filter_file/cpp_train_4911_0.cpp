#include <bits/stdc++.h>
using namespace std;
int a[12 * 2 + 1][12 * 2 + 1] = {};
int main() {
  int n = 0;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n + 1; ++i) {
    for (int j = 0; j < 2 * n + 1; ++j) a[i][j] = -1;
  }
  for (int i = 0; i <= n; ++i) {
    int x = i;
    int c = n;
    int v = n;
    while (x >= 0) {
      a[i][c] = x;
      a[i][v] = x;
      ++v;
      --c;
      --x;
    }
  }
  for (int i = 0; i <= n; ++i) {
    int x = i;
    int c = n;
    int v = n;
    while (x >= 0) {
      a[2 * n - i][c] = x;
      a[2 * n - i][v] = x;
      ++v;
      --c;
      --x;
    }
  }
  for (int i = 0; i < 2 * n + 1; ++i) {
    int state = 0;
    for (int j = 0; j < 2 * n + 1; ++j) {
      if (a[i][j] == -1)
        if (state == 0)
          printf("  ");
        else
          break;
      else {
        state = 1;
        if (a[i][j + 1] == -1) {
          printf("%d", a[i][j]);
          break;
        } else
          printf("%d ", a[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}
