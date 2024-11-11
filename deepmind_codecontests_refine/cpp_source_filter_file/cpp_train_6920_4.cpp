#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  if (n < m) {
    if (2 * n <= m) {
      ans = n;
    } else {
      ans += m - n;
      n = n - (m - n);
      ans += (n * 2) / 3;
    }
  } else {
    if (2 * m <= n) {
      ans = m;
    } else {
      ans += n - m;
      m = m - (n - m);
      ans += (n * 2) / 3;
    }
  }
  cout << ans << endl;
  return 0;
}
