#include <bits/stdc++.h>
const int C = 501, M = 998244353;
using ll = long long;
ll tmp[C][C], dp[C][C], tab_n[C], pw[C];
int main() {
  ll res = 0, m_sum = 0;
  int n, k, i, j, x;
  pw[0] = 1;
  for (i = 1; i < C; i++) pw[i] = (pw[i - 1] * 2) % M;
  scanf("%d %d", &n, &k);
  dp[1][1] = 1;
  for (x = 2; x <= n; x++) {
    for (i = 1; i < x; i++) {
      for (j = 1; j < x; j++) {
        tmp[1][(((1) > (j)) ? (1) : (j))] += dp[i][j];
        tmp[i + 1][(((j) > (i + 1)) ? (j) : (i + 1))] += dp[i][j];
      }
    }
    for (i = 1; i <= x; i++) {
      for (j = 1; j <= x; j++) {
        dp[i][j] = tmp[i][j] % M;
        tmp[i][j] = 0;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = i; j <= n; j++) {
      tab_n[j] = (tab_n[j] + dp[i][j]) % M;
    }
  }
  j = n;
  for (i = 1; i <= n; i++) {
    for (; j > 0 && j * i >= k; j--) m_sum = (m_sum + tab_n[j]) % M;
    res = (res - 2 * tab_n[i] * m_sum) % M;
  }
  res = (res + pw[n + n - 1]) % M;
  if (res < 0) res += M;
  printf("%lld\n", res);
  return 0;
}
