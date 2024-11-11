#include <bits/stdc++.h>
using namespace std;
int n, d, ans, x, l, r;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x != 0) {
      l += x, r = max(d, r + x);
      if (l > d) {
        cout << -1;
        return 0;
      }
    } else {
      if (r < 0)
        l = 0, r = d, ans++;
      else
        l = max(l, 0);
    }
  }
  cout << ans;
  return 0;
}
