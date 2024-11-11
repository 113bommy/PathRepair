#include <bits/stdc++.h>
int f[32][32][64];
int work(int x, int y, int k) {
  if (f[x][y][k]) return f[x][y][k];
  if (x * y == k || !k) return f[x][y][k] = 0;
  int t = 1 << 30;
  for (int i = 1; i < x; ++i)
    for (int j = 0; j <= k; ++j)
      t = std::min(t, y * y + work(i, y, j) + work(x - i, y, k - j));
  for (int i = 1; i < y; ++i)
    for (int j = 0; j <= k; ++j)
      t = std::min(t, x * x + work(x, i, j) + work(x, y - i, k - j));
  return f[x][y][k] = t;
}
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1, n, m, k; i <= t; ++i) {
    scanf("%d %d %d", &n, &m, &k);
    printf("%d\n", work(n, m, k));
  }
  return 0;
}
