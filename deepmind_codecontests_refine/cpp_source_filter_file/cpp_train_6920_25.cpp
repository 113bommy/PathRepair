#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    x = n - i;
    y = m - (2 * i);
    if (y > 0) {
      ans = max(ans, i + min(y, x / 2));
    }
  }
  cout << ans << "\n";
}
