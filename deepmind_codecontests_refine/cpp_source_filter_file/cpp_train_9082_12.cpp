#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int l, r, m;
  cin >> l >> r >> m;
  if (m >= l && m <= r) {
    cout << m << " " << l << " " << l << '\n';
    return;
  }
  for (long long int i = l; i <= r; i++) {
    long long int x = m % i;
    long long int y = (m / i + 1) * i - x;
    if (-x >= -(r - l) && -x <= (r - l)) {
      if (m - x) {
        cout << i << " " << r << " " << r - x << '\n';
        return;
      }
    }
    if (y >= -(r - l) && y <= (r - l)) {
      if (m + y) {
        cout << i << " " << r - y << " " << r << '\n';
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
