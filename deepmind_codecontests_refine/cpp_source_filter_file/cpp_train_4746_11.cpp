#include <bits/stdc++.h>
char s[260 << 2][260 << 2];
long long f[260], g[260];
int h[260];
int a[260][260];
int n, m;
int check(int x, int y) {
  int num = 0;
  for (int i = 1; i < 4; i++)
    for (int j = 1; j < 4; j++)
      if (s[x + i][y + j] != '.') num++;
  if (num == 0 || num == 1 || num == 4 || num == 5) return 3;
  if (num == 2 || num == 3) return s[x + 1][y + 1] == '.' ? 1 : 2;
  return s[x + 2][y + 2] == '.' ? 1 : 2;
}
inline int ver(int x, int y) { return a[x][y] & 1; }
inline int hor(int x, int y) { return a[x][y] & 2; }
int cal1(int y) {
  if (n % 2 == 1) return 0;
  for (int i = 0; i < n; i++)
    if (!ver(i, y)) return 0;
  return 1;
}
long long cal2(int y) {
  long long f[260];
  f[0] = 1;
  for (int i = 0; i < n; i++) {
    f[i + 1] = 0;
    if (hor(i, y) && hor(i, y + 1)) f[i + 1] = (f[i + 1] + f[i]) % 1000000007;
    if (i > 0 && ver(i, y) && ver(i, y + 1) && ver(i - 1, y) &&
        ver(i - 1, y + 1))
      f[i + 1] = (f[i + 1] + f[i - 1]) % 1000000007;
  }
  f[n] -= (h[y] & h[y + 1]);
  return f[n];
}
int main() {
  int i, j, k;
  scanf("%d %d", &n, &m);
  for (i = 0; i < 4 * n + 1; i++) scanf("%s", s[i]);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) a[i][j] = check(i << 2, j << 2);
  for (i = 0; i < m; i++) h[i] = cal1(i);
  for (i = 0; i < m - 1; i++) g[i] = cal2(i);
  f[0] = 1;
  for (i = 0; i < m; i++) {
    f[i + 1] = f[i] * h[i];
    if (i > 0) f[i + 1] = (f[i + 1] + f[i - 1] * g[i - 1]) % 1000000007;
  }
  printf("%I64d\n", f[m]);
  return 0;
}
