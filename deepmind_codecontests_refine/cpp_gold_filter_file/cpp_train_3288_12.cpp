#include <bits/stdc++.h>
const int N = 5e2 + 5, bit = 64;
int n, m;
std::bitset<N> f[2][bit][N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    f[w][0][u].set(v);
  }
  for (int i = 1; i < bit; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 1; k <= n; ++k) {
        if (f[1][i - 1][j].test(k)) f[1][i][j] |= f[0][i - 1][k];
        if (f[0][i - 1][j].test(k)) f[0][i][j] |= f[1][i - 1][k];
      }
    }
  }
  unsigned long long ans = 0;
  std::bitset<N> tmp, avi;
  avi[1] = 1;
  bool cur = false;
  for (int i = bit - 1; ~i; i--) {
    tmp.reset();
    for (int j = 1; j <= n; j++)
      if (avi[j]) tmp |= f[cur][i][j];
    if (tmp.count() != 0) {
      cur ^= 1;
      avi = tmp;
      ans |= 1ull << i;
    }
  }
  if (ans > 1000000000000000000ull)
    puts("-1");
  else
    printf("%llu", ans);
  return 0;
}
