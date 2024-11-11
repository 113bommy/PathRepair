#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t a, b, k, m;
  cin >> a >> b >> k >> m;
  vector<int64_t> v1(a), v2(b);
  for (int64_t i = 0; i < a; i++) cin >> v1[i];
  for (int64_t i = 0; i < b; i++) cin >> v2[i];
  bool posible = false;
  for (int64_t i = 0; i < b; i++) {
    if (v1[k - 1] < v2[i]) {
      if (b - (i + 1) + 1 >= m) posible = true;
      break;
    }
  }
  if (posible)
    cout << "YES\n";
  else
    cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
