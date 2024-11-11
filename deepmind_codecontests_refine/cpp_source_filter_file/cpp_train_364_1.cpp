#include <bits/stdc++.h>
int n, a[15][15];
int scan(int i, int j, int n) {
  scanf("%d", &a[i][j]);
  return j + 1 < n ? scan(i, j + 1, n) : i + 1 < n ? scan(i + 1, 0, n) : 0;
}
int wtf(int k, int i, int j, int n) {
  a[i][j] = std::min(a[i][j], a[i][k] + a[j][k]);
  return k + 1 < n   ? wtf(i, j, k + 1, n)
         : j + 1 < n ? wtf(i, j + 1, 0, n)
         : i + 1 < n ? wtf(i + 1, 0, 0, n)
                     : 0;
}
int ftw(int i, int j, int n) {
  return std::max(a[i][j], j + 1 < n   ? ftw(i, j + 1, n)
                           : i + 1 < n ? ftw(i + 1, 0, n)
                                       : 0);
}
int main() {
  scanf("%d", &n);
  scan(0, 0, n);
  wtf(0, 0, 0, n);
  printf("%d\n", ftw(0, 0, n));
  scanf("\n");
  return 0;
}
