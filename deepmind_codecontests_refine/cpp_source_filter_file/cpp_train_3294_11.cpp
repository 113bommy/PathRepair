#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, n, k, x, y, m;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cin >> x;
    m = x;
    k--;
    while (k--) {
      cin >> y;
      m = max(m, (y - x) / 2);
      x = y;
    }
    m = max(m, n - x + 1);
    cout << m << "\n";
  }
  return 0;
}
