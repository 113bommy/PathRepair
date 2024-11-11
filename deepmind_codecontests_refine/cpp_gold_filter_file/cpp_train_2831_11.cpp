#include <bits/stdc++.h>
const int MAX_N = 1e5 + 5;
const int MAX_M = 20;
const int INF = 1e9;
int n, m, c[MAX_M][MAX_M], f[1 << MAX_M];
char s[MAX_N];
int main() {
  scanf("%d%d %s", &n, &m, s);
  for (int i = 1; i < n; ++i) ++c[s[i - 1] - 'a'][s[i] - 'a'];
  std::fill(f + 1, f + (1 << MAX_M), INF);
  for (int mask = 0; mask < 1 << m; ++mask) {
    for (int i = 0; i < m; ++i)
      if (mask >> i & 1)
        for (int j = 0; j < m; ++j)
          if (!(mask >> j & 1)) f[mask] += c[i][j] + c[j][i];
    for (int i = 0; i < m; ++i)
      if (!(mask >> i & 1))
        f[mask ^ 1 << i] = std::min(f[mask ^ 1 << i], f[mask]);
  }
  printf("%d\n", f[(1 << m) - 1]);
  return 0;
}
