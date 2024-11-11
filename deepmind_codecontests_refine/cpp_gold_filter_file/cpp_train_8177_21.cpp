#include <bits/stdc++.h>
using namespace std;
const int N = 2100;
int rng0[500010], rng1[500010];
int a[N][N / 32];
int b[N][N / 32];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    rng0[i] = x;
    rng1[i] = y;
    a[x][y / 32] |= 1 << (y % 32);
  }
  for (int i = 0; i < n; ++i) b[i][i / 32] |= 1 << (i % 32);
  for (int i = 0; i < n; ++i) {
    int one = -1;
    for (int j = i; j < n; ++j) {
      if (a[j][i / 32] & (1 << (i % 32))) {
        one = j;
        break;
      }
    }
    if (one == -1) assert(0);
    if (one != i) {
      for (int k = 0; k <= n / 32; ++k) {
        swap(a[i][k], a[one][k]);
        swap(b[i][k], b[one][k]);
      }
    }
    for (int j = 0; j < n; ++j)
      if (i != j && a[j][i / 32] & (1 << (i % 32))) {
        for (int k = 0; k <= n / 32; ++k) {
          a[j][k] ^= a[i][k];
          b[j][k] ^= b[i][k];
        }
      }
  }
  for (int i = 0; i < m; ++i) {
    int x = rng0[i], y = rng1[i];
    if (b[y][x / 32] & (1 << (x % 32)))
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
