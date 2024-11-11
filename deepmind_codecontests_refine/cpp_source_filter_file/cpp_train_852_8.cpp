#include <bits/stdc++.h>
char str[2003][2003];
int X[2003][2003];
int Y[2003][2003];
int gao(int x, int y) {
  int ret = 0;
  for (int i = 0; i <= y - x - 1; i++) {
    if (X[x][y - i]) {
      str[x][y - i] ^= 1;
      X[x][y - i - 1] ^= 1;
      X[x][y - i] = 0;
    }
    if (Y[x][y - i]) {
      str[x][y - i] ^= 1;
      Y[x + 1][y - i] ^= 1;
      Y[x][y - i] = 0;
    }
    if (X[x + i][y]) {
      str[x + i][y] ^= 1;
      X[x + i][y - 1] ^= 1;
      X[x + i][y] = 0;
    }
    if (Y[x + i][y]) {
      str[x + i][y] ^= 1;
      Y[x + i + 1][y] ^= 1;
      Y[x + i][y] = 0;
    }
    if (str[x][y - i] == '1') {
      ret++;
      str[x][y - i] = '0';
      X[x][y - i - 1] ^= 1;
      Y[x + 1][y - i] ^= 1;
    }
    if (str[x + i][y] == '1') {
      ret++;
      str[x + i][y] = '0';
      X[x + i][y - 1] ^= 1;
      Y[x + i + 1][y] ^= 1;
    }
    if (X[y][x + i]) {
      str[y][x + i] ^= 1;
      X[y][x + i + 1] ^= 1;
      X[y][x + i] = 0;
    }
    if (Y[y][x + i]) {
      str[y][x + i] ^= 1;
      Y[y - 1][x + i] ^= 1;
      Y[y][x + i] = 0;
    }
    if (X[y - i][x]) {
      str[y - i][x] ^= 1;
      X[y - i][x + 1] ^= 1;
      X[y - i][x] = 0;
    }
    if (Y[y - i][x]) {
      str[y - i][x] ^= 1;
      Y[y - i - 1][x] ^= 1;
      Y[y - i][x] = 0;
    }
    if (str[y][x + i] == '1') {
      ret++;
      str[y][x + i] = '0';
      X[y][x + i + 1] ^= 1;
      Y[y - 1][x + i] ^= 1;
    }
    if (str[y - i][x] == '1') {
      ret++;
      str[y - i][x + i] = '0';
      X[y - i][x + 1] ^= 1;
      Y[y - i - 1][x] ^= 1;
    }
  }
  return ret;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(X, 0, sizeof(X));
    memset(Y, 0, sizeof(Y));
    for (int i = 1; i <= n; i++) {
      scanf("%s", str[i] + 1);
    }
    int ans = 0;
    for (int i = 1; 2 * i <= n; i++) {
      ans += gao(i, n + 1 - i);
    }
    for (int i = 1; i <= n; i++) {
      if (X[i][i]) {
        str[i][i] ^= 1;
        X[i][i] = 0;
      }
      if (Y[i][i]) {
        str[i][i] ^= 1;
        Y[i][i] = 0;
      }
      if (str[i][i] == '1') {
        ans++;
        str[i][i] = '0';
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
