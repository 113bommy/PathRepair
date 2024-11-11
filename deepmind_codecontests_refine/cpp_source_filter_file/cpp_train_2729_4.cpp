#include <bits/stdc++.h>
long long gi() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? x : -x;
}
int a[61], s[61], m, pri[61], C[61][61], dp[1 << 15 | 1][61], Mask[61];
std::vector<int> G[61];
int yes[61], c, Sum[1 << 15 | 1];
void dfs(int x) {
  ++c;
  for (int i : G[x])
    if (!yes[i]) yes[i] = yes[x], dfs(i);
}
int main() {
  int n = gi();
  for (int i = 1; i <= n; ++i) a[i] = gi();
  std::sort(a + 1, a + n + 1);
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
  }
  for (int i = 1; i <= n; ++i) {
    if (s[i]) continue;
    if (a[i] * 2 <= n) pri[++m] = a[i];
    for (int j = i + 1; j <= n; ++j)
      if (a[j] % a[i] == 0) s[j] = 1, Mask[j] |= 1 << m - 1;
  }
  for (int i = 1; i <= n; ++i)
    if (s[i])
      for (int j = i + 1; j <= n; ++j)
        if (s[j])
          if (Mask[i] & Mask[j]) G[i].push_back(j), G[j].push_back(i);
  for (int i = 1; i <= n; ++i)
    if (s[i]) ++Sum[Mask[i]];
  for (int i = 1; i < 1 << m; i <<= 1)
    for (int j = 0; j < 1 << m; ++j)
      if (~j & i) Sum[j | i] = (Sum[j | i] + Sum[j]) % 1000000007;
  int ans = 1, sz = 0;
  for (int i = 1; i <= n; ++i)
    if (s[i] && !yes[i]) {
      c = 0;
      yes[i] = i;
      dfs(i);
      memset(dp, 0, sizeof dp);
      std::vector<int> vec;
      int OR = 0;
      for (int j = 1; j <= n; ++j)
        if (yes[j] == i)
          OR |= Mask[j], dp[Mask[j]][1]++, vec.push_back(Mask[j]);
      for (int j = 1; j < c; ++j)
        for (int s = 0; s < 1 << m; ++s)
          if (dp[s][j]) {
            int x = Sum[s] - j;
            for (int t : vec)
              if ((t & ~s) && (t & s))
                dp[s | t][j + 1] = (dp[s | t][j + 1] + dp[s][j]) % 1000000007;
            dp[s][j + 1] = (dp[s][j + 1] + 1ll * dp[s][j] * x) % 1000000007;
          }
      ans = 1ll * ans * C[sz + c - 1][c - 1] % 1000000007 * dp[OR][c] %
            1000000007,
      sz += c - 1;
    }
  printf("%d\n", ans);
  return 0;
}
