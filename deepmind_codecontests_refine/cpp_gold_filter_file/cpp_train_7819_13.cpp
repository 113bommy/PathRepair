#include <bits/stdc++.h>
using namespace std;
const long long int INF = (long long)1e15;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    int mx = 0;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      mx = max(mx, x);
    }
    v.push_back({mx, m});
  }
  sort(v.begin(), v.end());
  int mxx = v[n - 1].first;
  long long ans = 0;
  for (auto p : v) {
    ans += 1ll * (mxx - p.first) * p.second;
  }
  cout << ans << endl;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
