#include <bits/stdc++.h>
using namespace std;
string ans;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k, i, j;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) {
    ans += 'L';
  }
  for (i = 0; i < m; i++) {
    ans += 'D';
  }
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (j = 1; j < m; j++) {
        ans += 'R';
      }
    } else {
      for (j = 1; j < m; j++) {
        ans += 'L';
      }
    }
    if (i < n - 1) ans += 'U';
  }
  cout << ans.size() << '\n';
  cout << ans << '\n';
  return 0;
}
