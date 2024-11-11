#include <bits/stdc++.h>
using namespace std;
const int MXN = 2 * 1e5 + 100;
const int INF = INT_MAX;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<long long, long long> > v(n);
  long long a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    v[i] = make_pair(x * a + y * b, i);
  }
  sort((v).begin(), (v).end());
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (v[i].first <= m) {
      ans.push_back(v[i].second);
      m -= v[i].first;
    }
  }
  cout << ans.size() << "\n";
  for (auto x : ans) cout << x << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt = 1;
  for (int i = 1; i <= tt; i++) {
    solve();
  }
  return 0;
}
