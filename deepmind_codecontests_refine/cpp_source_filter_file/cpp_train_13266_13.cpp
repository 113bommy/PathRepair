#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
const int max_mask = 1 << 20;
const long long INF = 1e18;
int n, m;
long long b;
long long x[maxn], k[maxn];
int M[maxn];
vector<pair<int, int> > arr;
long long dp[2][max_mask + 10];
void init() {
  for (int k = 0; k <= 1; ++k)
    for (int mask = 0; mask <= 1 << m; ++mask) dp[k][mask] = INF;
}
long long solve() {
  sort(arr.begin(), arr.end());
  long long ans = INF;
  init();
  int cur = 0;
  dp[0][0] = dp[1][0] = 0;
  for (int i = 0; i <= n - 1; ++i) {
    int id = arr[i].second;
    for (int mask = 0; mask <= (1 << m) - 1; ++mask)
      dp[cur][mask] = min(dp[cur][mask], dp[cur ^ 1][mask]);
    for (int mask = 0; mask <= (1 << m) - 1; ++mask)
      if (dp[cur][mask] != INF)
        dp[cur ^ 1][mask | M[id]] =
            min(dp[cur ^ 1][mask | M[id]], dp[cur][mask] + x[id]);
    if (dp[cur ^ 1][(1 << m) - 1] != INF)
      ans = min(ans, dp[cur ^ 1][(1 << m) - 1] + k[id] * b);
    cur ^= 1;
  }
  if (ans == INF) ans = -1;
  return ans;
}
int main() {
  scanf("%d%d%lld", &n, &m, &b);
  for (int i = 0; i <= n - 1; ++i) {
    int sz;
    scanf("%lld%lld%d", &x[i], &k[i], &sz);
    while (sz--) {
      int id;
      scanf("%d", &id);
      --id;
      M[i] += (1 << id);
    }
    arr.push_back(pair<int, int>(k[i], i));
  }
  printf("%lld\n", solve());
  return 0;
}
