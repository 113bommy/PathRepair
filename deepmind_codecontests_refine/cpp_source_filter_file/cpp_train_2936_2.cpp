#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 16, maxm = 150;
int n, k;
int a[maxn];
bitset<maxm + 1> dp[1 << maxn];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  dp[0][0] = true;
  for (int s = 0; s < 1 << n; ++s) {
    for (int i = maxm / k; i; --i)
      if (dp[s][i * k]) dp[s][i] = true;
    for (int i = 0; i < n; ++i)
      if (~s & (1 << i)) dp[s | (1 << i)] |= dp[s] << a[i];
  }
  if (!dp[(1 << n) - 1][1]) return cout << "NO\n", 0;
  cout << "YES\n";
  vector<pair<int, int>> res;
  priority_queue<pair<int, int>> pq;
  int s = (1 << n) - 1, v = 1, t = 0;
  while (s) {
    while (v * k <= maxm && dp[s][v * k]) v *= k, ++t;
    for (int i = 0; i < n; ++i)
      if (s & (1 << i))
        if (v >= a[i] && dp[s ^ (1 << i)][v - a[i]]) {
          cerr << "T " << t << ' ' << a[i] << '\n';
          pq.emplace(t, a[i]);
          s ^= 1 << i;
          v -= a[i];
          break;
        }
  }
  while (pq.size() > 1) {
    auto [_, a] = pq.top();
    pq.pop();
    auto [__, b] = pq.top();
    pq.pop();
    assert(__ == _);
    cout << a << ' ' << b << '\n';
    int val = a + b, t = 0;
    while (val % k == 0) val /= k, ++t;
    pq.emplace(_ - t, val);
  }
}
