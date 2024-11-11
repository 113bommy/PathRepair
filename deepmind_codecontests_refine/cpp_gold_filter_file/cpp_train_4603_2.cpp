#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int cost[N];
map<pair<int, int>, int> offers;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int Q, n, i;
  cin >> n;
  long long ans = 0;
  for (i = 1; i <= n; i++) cin >> cost[i], ans += cost[i];
  cin >> Q;
  while (Q--) {
    int s, t, u;
    cin >> s >> t >> u;
    if (offers.count({s, t})) {
      int v = offers[{s, t}];
      if (cost[v] >= 0) ans++;
      cost[v]++;
    }
    if (!u) {
      offers.erase({s, t});
      cout << ans << "\n";
      continue;
    }
    offers[{s, t}] = u;
    if (cost[u] > 0) ans--;
    cost[u]--;
    cout << ans << "\n";
  }
  return 0;
}
