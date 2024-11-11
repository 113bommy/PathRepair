#include <bits/stdc++.h>
const int MOD = 1000003;
bool A[2][500000][2];
int n, m, i, j, ans = 1;
int main() {
  scanf("%d%d", &n, &m);
  for (char c; i < n; ++i)
    for (j = 0, getchar(); j < m; ++j)
      if ((c = getchar()) != '.')
        A[1][j][(i & 1) ^ (c == '1' || c == '4')] = true,
                                            A[0][i][(j & 1) ^ c <= '2'] = true;
  for (i = 0; i < n; ++i) ans *= 2 - A[0][i][0] - A[0][i][1], ans %= MOD;
  for (j = 0; j < m; ++j) ans *= 2 - A[1][j][0] - A[1][j][1], ans %= MOD;
  printf("%d\n", ans);
}
