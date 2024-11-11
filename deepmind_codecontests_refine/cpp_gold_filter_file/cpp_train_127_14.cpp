#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, a[1001] = {};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a[x]++;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
      cin >> x;
      if (a[x]) ans = x;
    }
    if (ans) {
      cout << "YES" << endl << 1 << " " << ans << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
