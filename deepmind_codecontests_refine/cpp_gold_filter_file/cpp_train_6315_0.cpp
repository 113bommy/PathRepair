#include <bits/stdc++.h>
using namespace std;
struct node {
  long long st, en, req, idx;
};
bool comp(node a, node b) { return a.en > b.en; }
void solve() {
  long long n, m, i;
  cin >> n >> m;
  long long ans[n + 1];
  node a[m];
  memset(ans, 0, sizeof(ans));
  for (i = 0; i < m; i++) {
    cin >> a[i].st >> a[i].en >> a[i].req;
    a[i].idx = i + 1;
  }
  sort(a, a + m, comp);
  priority_queue<pair<long long, pair<long long, long long> > > pq;
  ans[a[0].en] = m + 1;
  for (i = 1; i < m; i++) {
    ans[a[i].en] = m + 1;
    if (a[i].en == a[i - 1].en) {
      cout << "-1"
           << "\n";
      return;
    }
  }
  long long j = 0;
  for (i = n; i >= 1; i--) {
    if (j < m && a[j].en == i) {
      pq.push({a[j].st, {a[j].req, a[j].idx}});
      j++;
    }
    if (ans[i] == (m + 1)) continue;
    if (pq.empty()) continue;
    pair<long long, pair<long long, long long> > x = pq.top();
    pq.pop();
    if (i < x.first) {
      cout << "-1"
           << "\n";
      return;
    }
    ans[i] = x.second.second;
    x.second.first--;
    if (x.second.first) pq.push(x);
  }
  if (pq.size()) {
    cout << "-1"
         << "\n";
    return;
  }
  for (i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
