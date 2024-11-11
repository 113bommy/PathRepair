#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e6 + 5;
long long t, n, d, m, k, a[siz], nxt_min[siz];
pair<long long, long long> p[siz];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> d >> n >> m;
  for (long long i = 1; i <= m; i++) cin >> p[i].first >> p[i].second;
  p[++m] = {d, 0};
  sort(p + 1, p + 1 + m);
  stack<long long> q;
  for (long long i = 1; i <= m; i++) {
    while (q.size() and p[q.top()].second > p[i].second) {
      nxt_min[q.top()] = i;
      q.pop();
    }
    q.push(i);
  }
  long long ans = 0, have = n;
  for (long long i = 1; i <= m; i++) {
    long long cur = p[i].first - p[i - 1].first;
    have -= cur;
    if (have < 0) return cout << -1 << endl, 0;
    if (i == m) break;
    long long buy_now =
        max(0LL, min(n - have, p[nxt_min[i]].first - p[i].first - have));
    ans += buy_now * p[i].second;
    have += buy_now;
  }
  cout << ans << endl;
}
