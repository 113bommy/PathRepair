#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
using namespace std;
const int MN = 15, MM = (1 << 14) + 5, inf = 1000000005, mod = 1000000007;
const long long INF = 1000000000000000005LL;
int E[MN][MN];
int jest[MM][MN][MN];
int dp[MM], maska[MM], raki[MM];
int n;
void restore(int mask) {
  while (__builtin_popcount(mask) > 1) {
    int p = 0, k, ok;
    for (int i = 0; i < n; ++i)
      if ((raki[mask] >> i) & 1) {
        if (!p) p = i + 1;
        k = i + 1;
      }
    int wyw = maska[mask], krab = raki[mask];
    while (__builtin_popcount(maska[mask]) > 1) {
      printf("%d %d\n", k, jest[maska[mask]][p - 1][k - 1]);
      ok = k;
      k = jest[maska[mask]][p - 1][k - 1];
      if (ok != p) maska[mask] ^= (1 << (ok - 1));
    }
    mask ^= wyw;
    mask |= krab;
  }
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    E[u][v] = E[v][u] = 1;
  }
  for (int i = 0; i < n; ++i) jest[(1 << i)][i][i] = i + 1;
  int M = (1 << n);
  for (int mask = 0; mask < M; ++mask)
    for (int p = 0; p < n; ++p)
      for (int k = 0; k < n; ++k)
        if (jest[mask][p][k] && (p != k || jest[mask][p][k] == p + 1))
          for (int l = 0; l < n; ++l)
            if (jest[mask][p][k] != (l + 1))
              if (E[k][l] && (l == p || !(mask & (1 << l))))
                jest[mask | (1 << l)][p][l] = k + 1;
  for (int j = 1; j < M; ++j) dp[j] = inf;
  for (int j = 0; j < M; ++j)
    for (int k = 0; k < n; ++k)
      if (jest[j][k][k]) {
        int cost = __builtin_popcount(j);
        if (cost < dp[j]) {
          dp[j] = cost;
          maska[j] = j;
          raki[j] = (1 << k);
        }
      }
  int neg = (1 << n) - 1;
  for (int j = 0; j < M; ++j) {
    int dop = j ^ neg, cost, lub;
    for (int l = 0; l < n; ++l)
      for (int k = l; k < n; ++k)
        if (((j >> l) & 1) && ((j >> k) & 1)) {
          lub = (1 << l) | (1 << k);
          for (int dod = dop; dod; dod = (dod - 1) & dop) {
            if (!jest[dod | lub][l][k]) continue;
            cost = dp[j] + __builtin_popcount(dod | lub) - 1 + (l == k);
            if (cost < dp[j | dod]) {
              dp[j | dod] = cost;
              raki[j | dod] = lub;
              maska[j | dod] = dod | lub;
            }
          }
        }
  }
  printf("%d\n", dp[M - 1]);
  restore(M - 1);
}
