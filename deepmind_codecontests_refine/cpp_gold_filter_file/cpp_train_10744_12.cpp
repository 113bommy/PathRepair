#include <bits/stdc++.h>
using namespace std;
inline void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long r, g, b;
  cin >> r >> g >> b;
  vector<long long> v = {r, g, b};
  sort(v.begin(), v.end());
  if (v[2] <= v[1] + v[0] + 1) {
    cout << "Yes\n";
    return;
  }
  cout << "No\n";
}
signed main() {
  fastio();
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
