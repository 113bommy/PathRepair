#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using db = long double;
using ii = pair<int, int>;
const int N = 1e7 + 5, LG = 17, MOD = 1e9 + 7;
const int SQ = 450;
const long double EPS = 1e-7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x, --x;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      vector<int> cycle;
      int cur = i;
      if (ans[cur]) continue;
      while (!ans[cur]) {
        cycle.push_back(cur);
        ans[cur] = 1;
        cur = a[cur];
      }
      for (auto x : cycle) ans[x] = cycle.size();
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i + 1 == n];
  }
  return 0;
}
