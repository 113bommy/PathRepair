#include <bits/stdc++.h>
using namespace std;
const long long int inf = 2e18;
long long int solve() {
  long long int a, n, m;
  cin >> a >> n >> m;
  vector<long long int> col(a + 1, 0);
  vector<pair<long long int, long long int>> p;
  for (long long int j = 1; j <= n; j++) {
    long long int l, r;
    cin >> l >> r;
    p.push_back({l, r});
    for (long long int i = l + 1; i <= r; i++) {
      col[i] = 1;
    }
  }
  sort(p.begin(), p.end());
  vector<long long int> dist(a + 1, 0);
  for (long long int j = p[0].first + 1; j <= a; j++) {
    if (col[j] == 1) {
      dist[j] = 0;
    } else {
      dist[j] = dist[j - 1] + 1;
    }
  }
  map<long long int, long long int> w;
  vector<long long int> pos;
  long long int k = p.size();
  long long int end = p[k - 1].second;
  for (long long int j = 0; j < m; j++) {
    long long int x, we;
    cin >> x >> we;
    if (x >= end) continue;
    if (w.find(x) != w.end()) {
      w[x] = min(w[x], we);
    } else {
      w[x] = we;
      pos.push_back(x);
    }
  }
  if (pos.size() == 0) {
    cout << 0 << "\n";
    return 0;
  }
  sort(pos.begin(), pos.end());
  reverse(pos.begin(), pos.end());
  vector<long long int> dp(m + 1);
  dp[0] = (end - pos[0]) * w[pos[0]];
  long long int start = p[0].first;
  m = pos.size();
  for (long long int j = 1; j < m; j++) {
    dp[j] = (end - pos[j]) * w[pos[j]];
    for (long long int i = 0; i < j; i++) {
      if (pos[i] <= start) continue;
      if (pos[j] < (pos[i] - dist[pos[i]])) {
        dp[j] =
            min(dp[j], (pos[i] - dist[pos[i]] - pos[j]) * w[pos[j]] + dp[i]);
      }
    }
  }
  long long int ans = inf;
  for (long long int j = m - 1; j >= 0; j--) {
    if (pos[j] > start) {
      break;
    } else {
      ans = min(ans, dp[j]);
    }
  }
  if (ans == inf) {
    cout << -1 << "\n";
  } else {
    cout << ans << "\n";
  }
  return 0;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
