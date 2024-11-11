#include <bits/stdc++.h>
using namespace std;
const long long MX = 3e5 + 1;
long long n, x1, x2;
vector<pair<long long, long long>> c;
vector<long long> S1, S2;
bool solve(long long a, long long b, bool ok) {
  vector<long long> ans[2];
  long long l = 0;
  for (long long i = 0; i < 2; ++i) {
    long long cn = (i ? b : a);
    long long r = l;
    while (r <= n && ((r == l) || (c[r - 1].first * (r - l) < cn))) {
      ++r;
    }
    if (r > n) {
      return false;
    }
    for (long long j = l; j < r; ++j) {
      ans[i ^ ok].push_back(c[j].second);
    }
    l = r;
  }
  cout << "Yes\n";
  cout << ans[0].size() << " " << ans[1].size() << "\n";
  sort(ans[0].begin(), ans[0].end());
  sort(ans[1].begin(), ans[1].end());
  for (auto& val : ans[0]) {
    cout << val << " ";
  }
  cout << "\n";
  for (auto& val : ans[1]) {
    cout << val << " ";
  }
  cout << "\n";
  return true;
}
void solve() {
  cin >> n >> x1 >> x2;
  for (long long i = 0; i < n; i++) {
    c.push_back({0, 0});
    cin >> c[i].first;
    c[i].second = i + 1;
  }
  sort(c.rbegin(), c.rend());
  if (solve(x1, x2, false)) return;
  if (solve(x2, x1, true)) return;
  cout << "NO\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
