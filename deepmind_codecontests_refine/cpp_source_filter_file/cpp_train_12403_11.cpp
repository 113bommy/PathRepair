#include <bits/stdc++.h>
using namespace std;
int n, m, lim;
short dp[40][7][32][32][32];
short go(int r, int c, int m1, int m2, int m3) {
  short &ret = dp[r][c][m1][m2][m3];
  if (ret != -1) return ret;
  if (c == m) {
    if (r == n - 1)
      return ret = 2 * m - __builtin_popcount(m1) - __builtin_popcount(m2);
    else
      return ret = m - __builtin_popcount(m1) + go(r + 1, 0, m2, m3, 0);
  } else {
    ret = go(r, c + 1, m1, m2 | (1 << c), m3);
    if (c > 0) ret = max(ret, go(r, c + 1, m1, m2 | (1 << (c - 1)), m3));
    if (c + 1 < m) ret = max(ret, go(r, c + 1, m1, m2 | (1 << (c + 1)), m3));
    if (r > 0) ret = max(ret, go(r, c + 1, m1 | (1 << c), m2, m3));
    if (r + 1 < n) ret = max(ret, go(r, c + 1, m1, m2, m3 | (1 << c)));
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  if (n < m) swap(n, m);
  memset(dp, -1, sizeof(dp));
  lim = (1 << m) - 1;
  int ans = go(0, 0, lim, 0, 0);
  printf("%d\n", ans);
  return 0;
}
