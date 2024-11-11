#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, q, mx = 0;
  cin >> n >> q;
  vector<int> a(n + 2), v;
  deque<int> que;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
    que.push_back(a[i]);
  }
  vector<pair<int, int> > ans;
  for (;;) {
    int be = que.front();
    que.pop_front();
    int en = que.front();
    que.pop_front();
    que.push_front(max(be, en));
    que.push_back(min(be, en));
    ans.push_back({be, en});
    if (max(be, en) == mx) break;
  }
  que.pop_front();
  while (!que.empty()) {
    v.push_back(que.front());
    que.pop_front();
  }
  while (q--) {
    long long x;
    cin >> x;
    if (x <= int(ans.size())) {
      cout << ans[x - 1].first << " " << ans[x - 1].second << endl;
    } else {
      x -= int(ans.size());
      x = (x - 1) % int(v.size());
      cout << mx << " " << v[x] << endl;
    }
  }
}
int main() {
  int _ = 1;
  for (int i = 1; i <= _; ++i) solve();
}
