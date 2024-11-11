#include <bits/stdc++.h>
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
int n, b[5500], p[5500], ans[5500], map[5500][5500 << 1];
int main() {
  n = read();
  for (int i = 0; i < n; ++i) {
    printf("? %d %d\n", 0, i);
    fflush(stdout);
    map[0][n + i] = read();
  }
  for (int i = 0; i < n; ++i) {
    printf("? %d %d\n", i, 0);
    fflush(stdout);
    map[n][i] = read();
  }
  int cnt = 0;
  for (int x = 0; x < n; ++x) {
    bool flag = false;
    p[0] = x;
    for (int i = 1; i < n; ++i) {
      p[i] = x ^ map[0][n] ^ map[n][i];
      if (p[i] >= n) {
        flag = true;
        break;
      }
    }
    b[0] = x ^ map[0][0];
    for (int i = 1; i < n; ++i) {
      b[i] = b[0] ^ map[n][0] ^ map[0][n + i];
      if (b[i] >= n) {
        flag = true;
        break;
      }
    }
    if (flag) continue;
    flag = false;
    for (int i = 0; i < n; ++i) {
      if (p[b[i]] != i) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      cnt++;
      for (int i = 0; i < n; ++i) ans[i] = p[i];
    }
  }
  printf("!\n%d\n", cnt);
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  return 0;
}
