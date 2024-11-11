#include <bits/stdc++.h>
using namespace std;
const int N = 250 + 1, inf = 1e9;
int n, m, dp[250][1 << 16][2][2];
char c[N][N];
void ad(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
int calc(int x, int y, int mask, int guardedFromTop, int first) {
  if (x == n) return calc(0, y + 1, mask, 0, first);
  if (y == m) return 1;
  int &ret = dp[x * m + y][mask][guardedFromTop][first];
  if (ret + 1) return ret;
  ret = 0;
  bool guardedFromLeft = (mask >> x & 1);
  if (c[x][y] == 'x') {
    ad(ret, calc(x + 1, y, mask & !(1 << x), 0, first));
    return ret;
  }
  if (!first && !guardedFromTop && !guardedFromLeft)
    ad(ret, calc(x + 1, y, mask, 0, 1));
  ad(ret, calc(x + 1, y, mask | (1 << x), 1, first));
  if (!guardedFromLeft && !guardedFromTop) return ret;
  ad(ret, calc(x + 1, y, mask, guardedFromTop, first));
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  bool first = n > m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (first)
        scanf(" %c", &c[j][i]);
      else
        scanf(" %c", &c[i][j]);
    }
  }
  if (first) swap(n, m);
  memset(dp, -1, sizeof dp);
  printf("%d\n", calc(0, 0, 0, 0, 0));
}
