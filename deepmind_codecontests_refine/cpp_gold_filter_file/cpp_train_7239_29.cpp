#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, x, y, z, A, B, an;
int l[10][10], r[10][10], a[10][10], f[10];
void dfs(int x, int y, int z, int s) {
  if (x == n) {
    if (s > an) an = s;
    return;
  }
  if (y > n) {
    if (!z) dfs(x + 1, x + 2, f[x + 1], s);
    return;
  }
  int i;
  for (i = l[x][y]; i <= min(z, r[x][y]); i++) {
    f[y] += i;
    dfs(x, y + 1, z - i, s + (i ? a[x][y] : 0) + i * i);
    f[y] -= i;
  }
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n * (n - 1) / 2; i++) {
    scanf("%d%d%d%d%d", &x, &y, &z, &A, &B);
    l[x][y] = z, r[x][y] = A, a[x][y] = B;
  }
  for (i = 0; i <= 25; i++) {
    an = -1;
    dfs(1, 2, i, 0);
    if (an >= 0) {
      printf("%d %d\n", i, an);
      return 0;
    }
  }
  printf("-1 -1\n");
  return 0;
}
