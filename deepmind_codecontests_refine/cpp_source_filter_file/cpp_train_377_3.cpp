#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> seg(m - 1);
  for (int i = 0; i < m; ++i) cin >> a[i];
  sort(begin(a), end(a));
  iota(begin(seg), end(seg), 1);
  sort(begin(seg), end(seg),
       [&](int x, int y) { return a[x] - a[x - 1] < a[y] - a[y - 1]; });
  ll sol = INF;
  seg.resize(min(2 * n, m - 1));
  sort(begin(seg), end(seg));
  vector<ll> dp0(n + 1, INF);
  dp0[0] = 0;
  vector<ll> dp1(n + 1, INF);
  dp1[0] = 0;
  vector<ll> dp2(n + 1, INF);
  dp2[0] = 0;
  for (int i = 0; i < seg.size(); ++i) {
    int val = a[seg[i]] - a[seg[i] - 1];
    for (int j = 1; j <= n; ++j) {
      if (i > 0 && seg[i - 1] + 1 == seg[i]) {
        dp0[j] = min({dp1[j], dp2[j - 1] + val});
      } else {
        dp0[j] = min({dp1[j], dp2[j - 1] + val, dp1[j - 1] + val});
      }
    }
    sol = min(sol, dp0[n]);
    swap(dp2, dp1);
    swap(dp1, dp0);
  }
  cout << sol << '\n';
}
