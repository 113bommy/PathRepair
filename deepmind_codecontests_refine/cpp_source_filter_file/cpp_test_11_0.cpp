#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, a[MAXN];
pair<int, int> ta[MAXN];
int seq[MAXN];
void solve() {
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  for (int i = (1); i <= (n); ++i) {
    ta[i].first = i - a[i];
    ta[i].second = a[i];
  }
  sort(ta + 1, ta + 1 + n,
       [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
         return lhs.first < rhs.first ||
                (lhs.first < rhs.first && lhs.second < rhs.second);
       });
  int i = 1;
  while (i <= n && ta[i].first < 0) ++i;
  if (i > n) {
    cout << "0\n";
    return;
  }
  int ans = 1;
  seq[1] = ta[i].second;
  for (++i; i <= n; ++i) {
    auto p = lower_bound(seq + 1, seq + 1 + ans, ta[i].second);
    *p = ta[i].second;
    ans = max(ans, int(p - seq));
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int _;
  _ = 1;
  while (_--) {
    solve();
  }
  return 0;
}
