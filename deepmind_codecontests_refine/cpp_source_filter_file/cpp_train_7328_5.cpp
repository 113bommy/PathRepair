#include <bits/stdc++.h>
using namespace std;
int m, a[25], b[25], g[25][25][25];
long long ans, n, f[25][25][25];
int G(int t, int p, int x) {
  int i, y = x;
  if (t == 1) {
    x -= max(x, p);
    if (x >= 0) x -= p;
    return 10 + x;
  }
  if (g[t][p][x] >= 0) return g[t][p][x];
  for (i = 8; i >= 0; i--) x = G(t - 1, max(p, i), x);
  return g[t][p][y] = x;
}
long long F(int t, int p, int x) {
  int i, y = x;
  if (t == 1) return 1 + (p <= x);
  if (f[t][p][x] >= 0) return f[t][p][x];
  f[t][p][y] = 0;
  for (i = 8; i >= 0; i--) {
    f[t][p][y] += F(t - 1, max(p, i), x);
    x = G(t - 1, max(p, i), x);
  }
  return f[t][p][y];
}
int main() {
  int i, j, p;
  long long x;
  cin >> n;
  if (n == 0) {
    printf("0");
    return 0;
  }
  memset(g, -1, sizeof(g));
  memset(f, -1, sizeof(f));
  for (x = n; x; x /= 10) a[++m] = x % 10;
  for (i = m; i >= 1; i--) b[i] = max(b[i + 1], a[i]);
  ans = F(1, b[2], a[1]);
  p = G(1, b[2], a[1]);
  for (i = 2; i <= m; i++)
    for (j = a[i] - 1; j >= 0; j--) {
      ans += F(i - 1, max(b[i + 1], j), p);
      p = G(i - 1, max(b[i + 1], j), p);
    }
  cout << ans - 1;
  return 0;
}
