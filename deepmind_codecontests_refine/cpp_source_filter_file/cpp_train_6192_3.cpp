#include <bits/stdc++.h>
using namespace std;
const int MX = 301, INF = 1e9;
int n, ans = INF, size;
int l[MX], cost[MX], mask[MX];
int dp[MX][1 << 9];
int solve(int cur, int msk) {
  if (cur == n + 1) {
    if (msk == (1 << size) - 1) return 0;
    return INF;
  }
  int &r = dp[cur][msk];
  if (r != -1) return r;
  r = INF;
  r = min(r, solve(cur + 1, msk));
  r = min(r, solve(cur + 1, msk | mask[cur]) + cost[cur]);
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> l[i];
  for (int i = 1; i <= n; ++i) cin >> cost[i];
  for (int i = 1; i <= n; ++i) {
    vector<int> factor;
    int t = l[i];
    for (int j = 2; j * j <= t; ++j)
      if (t % j == 0) {
        factor.push_back(j);
        while (t % j == 0) t /= j;
      }
    if (t > 1) factor.push_back(t);
    size = (int)factor.size();
    for (int j = 0; j < size; ++j) {
      mask[j] = 0;
      for (int k = 0; k < size; ++k)
        if (l[j] % factor[k] != 0) mask[j] |= (1 << k);
    }
    memset(dp, 255, sizeof(dp));
    ans = min(ans, solve(1, 0) + cost[i]);
  }
  if (ans >= INF)
    cout << -1;
  else
    cout << ans;
}
