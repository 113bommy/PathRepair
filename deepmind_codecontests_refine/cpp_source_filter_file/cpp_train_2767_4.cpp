#include <bits/stdc++.h>
long long read() {
  long long x = 0;
  int zf = 1;
  char ch = ' ';
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') zf = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * zf;
}
int ans[3][6] = {{0, 1, 0, 2, 2, 0}, {1, 0, 1, 1, 0, 2}, {2, 2, 2, 0, 1, 1}};
int main() {
  int n = read() % 6, x = read();
  printf("%d", ans[x][n]);
  return 0;
}
