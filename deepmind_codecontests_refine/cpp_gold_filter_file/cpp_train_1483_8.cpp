#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5;
void solve() {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> v(m);
  for (auto &it : v) cin >> it;
  ;
  vector<long long int> suf(m);
  long long int s = 0;
  for (long long int i = m - 1; i >= 0; i--) {
    if (i + v[i] - 1 > n - 1) {
      cout << -1 << "\n";
      return;
    }
    s += v[i];
    suf[i] = s;
  }
  if (s < n) {
    cout << -1 << "\n";
    return;
  }
  long long int j = 0;
  long long int start = 0, prev = -1;
  vector<long long int> ans;
  for (long long int i = 0; i < m; i++) {
    cout << max(n - suf[i] + 1, i + 1) << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) solve();
  return 0;
}
