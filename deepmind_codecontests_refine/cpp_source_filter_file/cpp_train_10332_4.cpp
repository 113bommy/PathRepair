#include <bits/stdc++.h>
const int MAX_N = 500000;
const int MAX_M = 500000;
const int MOD = 998244353;
int l[MAX_M], r[MAX_M], val[MAX_M];
int smen[1 + MAX_N + 1], left[1 + MAX_N], dp[1 + MAX_N], _sp[1 + 1 + MAX_N],
    *sp = _sp + 1;
int solve(int n, int m, int bit) {
  int last = 0, p = 0;
  for (int i = 1; i <= n; ++i) {
    smen[i] = 0;
    left[i] = 0;
  }
  smen[n + 1] = left[n + 1] = 0;
  for (int i = 0; i < m; ++i)
    if ((1 << bit) & val[i]) {
      smen[l[i]]++;
      smen[r[i] + 1]--;
    } else
      left[r[i] + 1] = std::max(left[r[i]], l[i]);
  sp[0] = 1;
  dp[0] = 1;
  for (int i = 1; i <= n + 1; ++i) {
    p += smen[i];
    last = std::max(last, left[i]);
    if (p == 0) {
      dp[i] = (sp[i - 1] + MOD - sp[last - 1]) % MOD;
    } else
      dp[i] = 0;
    sp[i] = (sp[i - 1] + dp[i]) % MOD;
  }
  return dp[n + 1];
}
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 0; i < m; ++i) scanf("%d%d%d", &l[i], &r[i], &val[i]);
  int res = 1;
  for (int i = 0; i < k; ++i) res = (long long)res * solve(n, m, i) % MOD;
  printf("%d", res);
  return 0;
}
