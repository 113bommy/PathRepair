#include <bits/stdc++.h>
using namespace std;
bool bl[1001] = {0};
void solve() {
  int p, q, l, r;
  cin >> p >> q >> l >> r;
  int i, j, a, b;
  for (i = 1; i <= p; i++) {
    cin >> a >> b;
    for (j = a; j <= b; j++) bl[j] = 1;
  }
  vector<pair<int, int> > v;
  for (i = 1; i <= q; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  int ans = 0;
  bool f = 0;
  for (i = l; i <= r; i++) {
    auto it = v.begin();
    for (; it != v.end(); it++) {
      f = 0;
      for (j = it->first; j <= it->second; j++) {
        if (bl[j + i] == 1) {
          f = 1;
          break;
        }
      }
      if (f == 1) {
        ans++;
        break;
      }
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
