#include <bits/stdc++.h>
using namespace std;
int t, a;
void solve() {
  vector<int> v;
  for (int i = 1; i <= 250; ++i) {
    cin >> a;
    v.push_back(a);
  }
  sort((v).begin(), (v).end());
  if (double(v[246] - v[4]) / (2 * v[124]) < 0.8)
    cout << "poisson\n";
  else
    cout << "uniform\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> t;
  while (t--) solve();
}
