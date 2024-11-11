#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int &i : a) cin >> i;
  int b[m];
  for (int &i : b) cin >> i;
  int pos[n + 1];
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }
  int dep = 0, ans = 0;
  for (int i = 0; i < m; i++) {
    if (pos[b[i]] < dep) {
      ++ans;
    } else {
      ans += 2 * (pos[b[i]] - i) + 1;
      dep = pos[b[i]];
    }
  }
  cout << ans << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
