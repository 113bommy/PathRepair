#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class t>
using V = vector<t>;
constexpr ll INF = 1e16;
int n, m;
ll dp[1502][1502];
int tab[1502][1502];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int k = 1; k <= m; ++k) scanf("%d", &tab[i][k]);
  for (int i = 1; i <= n; ++i)
    for (int k = 1; k <= m; ++k) tab[i][k] += tab[i][k - 1];
  for (int i = 1; i <= n + 1; ++i)
    for (int k = 0; k <= m + 1; ++k) dp[i][k] = -INF;
  for (int i = 1; i <= n; ++i) {
    if (i & 1) {
      for (int k = 1; k <= m; ++k)
        dp[i - 1][k] = max(dp[i - 1][k - 1], dp[i - 1][k]);
      for (int k = 2; k <= m; ++k) dp[i][k] = dp[i - 1][k - 1] + tab[i][k];
    } else {
      for (int k = m; k >= 1; --k)
        dp[i - 1][k] = max(dp[i - 1][k], dp[i - 1][k + 1]);
      for (int k = 1; k <= m - 1; ++k) dp[i][k] = dp[i - 1][k + 1] + tab[i][k];
    }
  }
  ll res = -INF;
  for (int i = 1; i <= m; ++i) res = max(res, dp[n][i]);
  printf("%lld\n", res);
}
