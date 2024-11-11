#include <bits/stdc++.h>
using namespace std;
long long f[55];
int k, X, n, m, cnt[] = {0, 1, 1, 2};
struct point {
  int f, s;
  long long d;
} p[55];
void out(bool a, bool b, int c, int d) {
  int j = 0;
  if (a) putchar('C'), ++j;
  while (c--) putchar('A'), putchar('C'), j += 2;
  while (j + 1 < d) putchar('B'), ++j;
  if (b)
    putchar('A');
  else if (j < d)
    putchar('B');
  puts("");
}
bool check(bool xa, bool xc, bool ya, bool yc, int x, int y) {
  f[1] = x, f[2] = y;
  for (int i = 3; i <= k; ++i) f[i] = f[i - 2] + f[i - 1];
  long long sum = f[k];
  if (sum > X) return false;
  p[1].f = xa, p[1].s = xc, p[1].d = 0;
  p[2].f = ya, p[2].s = yc, p[2].d = 0;
  for (int i = 3; i <= k; ++i) {
    p[i].d = p[i - 1].d + p[i - 2].d;
    if (p[i - 2].s && p[i - 1].f) ++p[i].d;
    p[i].f = p[i - 2].f;
    p[i].s = p[i - 2].s;
  }
  sum += p[k].d;
  if (sum != X) return false;
  out(xa, xc, x, n);
  out(ya, yc, y, m);
  return true;
}
bool solve() {
  for (int i = 0; i * 2 <= n; ++i) {
    for (int j = 0; j * 2 <= m; ++j) {
      for (int ii = 0; ii < 4; ++ii) {
        if (cnt[ii] + i * 2 > n) continue;
        for (int jj = 0; jj < 4; ++jj) {
          if (cnt[jj] + j * 2 > m) continue;
          if (check(ii & 2, ii & 1, jj & 2, jj & 1, i, j)) return true;
        }
      }
    }
  }
  return false;
}
int main() {
  cin >> k >> X >> n >> m;
  if (!solve()) puts("Happy new year!");
  return 0;
}
