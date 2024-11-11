#include <bits/stdc++.h>
using namespace std;
int n, m, mi = 1e6, l, r;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> l >> r;
    mi = min(mi, r - l + 1);
  }
  cout << mi << endl;
  mi--;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cout << ans << " ";
    ans++;
    if (ans > mi) {
      ans = 0;
    }
  }
  return 0;
}
