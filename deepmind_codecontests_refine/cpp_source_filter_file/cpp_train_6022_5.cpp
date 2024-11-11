#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll ans = 0;
  int n;
  cin >> n;
  vector<vector<int>> v(3, vector<int>(n));
  for (auto &x : v) {
    for (auto &xx : x) {
      cin >> xx;
    }
    sort(x.begin(), x.end());
  }
  for (const auto &xx : v[1]) {
    int u = lower_bound(v[0].begin(), v[0].end(), xx) - v[0].begin();
    int d = v[2].end() - upper_bound(v[2].begin(), v[2].end(), xx);
    ans += (ll)u * d;
  }
  cout << ans << endl;
}
