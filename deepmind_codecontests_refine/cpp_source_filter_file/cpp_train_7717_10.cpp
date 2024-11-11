#include <bits/stdc++.h>
const int maxn = 5010;
int f[maxn + 1][maxn + 1][2];
int a[maxn + 1];
int res;
int n;
void init() {
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
}
void update(int i, int j, int k, int v) {
  if (v < f[i][j][k]) f[i][j][k] = v;
}
void work() {
  int i, j, k, len;
  for (i = 1; i <= n; ++i) {
    f[i][i][0] = f[i][i][1] = 0;
  }
  for (len = 2; len <= n; ++len) {
    for (i = 1; i <= n - len + 1; ++i) {
      j = i + len - 1;
      f[i][j][0] = f[i][j][1] = 1000000000;
    }
  }
  for (len = 1; len < n; ++len) {
    for (i = 1; i <= n - len + 1; ++i) {
      j = i + len - 1;
      if (f[i][j][0] < 1000000000) {
        if (i > 1) {
          if (a[i] == a[i - 1])
            update(i - 1, j, 0, f[i][j][0]);
          else
            update(i - 1, j, 0, f[i][j][0] + 1);
        }
        if (j < n) {
          if (a[i] == a[j + 1])
            update(i, j + 1, 1, f[i][j][0]);
          else
            update(i, j + 1, 1, f[i][j][0] + 1);
        }
      }
      if (f[i][j][1] < 1000000000) {
        if (i > 1) {
          if (a[j] == a[i - 1])
            update(i - 1, j, 0, f[i][j][0]);
          else
            update(i - 1, j, 0, f[i][j][0] + 1);
        }
        if (j < n) {
          if (a[j] == a[j + 1])
            update(i, j + 1, 1, f[i][j][0]);
          else
            update(i, j + 1, 1, f[i][j][0] + 1);
        }
      }
    }
  }
  res = f[1][n][0];
  if (f[1][n][1] < res) res = f[1][n][1];
}
void output() { printf("%d\n", res); }
int main() {
  init();
  work();
  output();
  return 0;
}
