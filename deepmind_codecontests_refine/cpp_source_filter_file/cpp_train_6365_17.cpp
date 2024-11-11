#include <bits/stdc++.h>
using namespace std;
long long n, k, a[200005], b[200005], ca[200005];
bool check(long long mid) {
  for (long long i = 1; i < n + 1; i++) ca[i] = a[i];
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;
  for (long long i = 1; i < n + 1; i++) pq.push({ca[i] / b[i] + 1, i});
  for (long long i = 1; i < k + 1; i++) {
    pair<long long, long long> cur = pq.top();
    pq.pop();
    if (cur.first > k + 1) return 1;
    if (cur.first < i) return 0;
    long long id = cur.second;
    ca[id] += mid;
    pq.push({ca[id] / b[id] + 1, id});
  }
  return 1;
}
void solve() {
  cin >> n >> k;
  for (long long i = 1; i < n + 1; i++) cin >> a[i];
  for (long long i = 1; i < n + 1; i++) cin >> b[i];
  long long lo = 0, hi = 1e13;
  while (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    if (check(mid))
      hi = mid;
    else
      lo = mid;
  }
  if (hi == 1e13)
    cout << -1 << '\n';
  else
    cout << hi << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
