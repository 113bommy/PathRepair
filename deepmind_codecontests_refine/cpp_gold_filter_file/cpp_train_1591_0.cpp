#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const long double pi = acos((ld)-1.0);
const double eps = (double)1e-9;
const int inf = 1e9 + 7;
void solve() {
  ll ans = 0;
  int n, q;
  cin >> n >> q;
  int a[n + 2];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = a[n + 1] = 0;
  function<void(int, ll)> add = [&](int p, ll x) -> void {
    x *= a[p];
    if (a[p] > a[p - 1] and a[p] > a[p + 1]) ans += x;
    if (a[p] < a[p - 1] and a[p] < a[p + 1]) ans -= x;
  };
  for (int i = 1; i <= n; i++) {
    add(i, 1);
  }
  cout << ans << endl;
  while (q--) {
    int u, v;
    cin >> u >> v;
    set<int> st;
    for (int i = -1; i <= 1; i++) {
      if (v + i > 0 and v + i <= n) st.insert(v + i);
      if (u + i > 0 and u + i <= n) st.insert(u + i);
    }
    for (int e : st) {
      add(e, -1);
    }
    swap(a[v], a[u]);
    for (int e : st) {
      add(e, 1);
    }
    cout << ans << endl;
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
const int fastio = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
