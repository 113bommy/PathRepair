#include <bits/stdc++.h>
using namespace std;
long long int m, n, l, r, ans, i, q[200010], x;
int main() {
  cin >> n >> m;
  for (i = 0; i < m; i++) cin >> x >> q[i];
  sort(q, q + m, greater<int>());
  bool ch = 0;
  for (i = 1; i <= m; i++) {
    l = i;
    if (i % 2) {
      if ((i * (i - 1)) / 2 > n) {
        ch = 1;
        break;
      }
    } else {
      if ((i * i) / 2 > n - 1) {
        ch = 1;
        break;
      }
    }
  }
  if (!ch) l = m + 1;
  for (i = 0; i < l - 1; i++) ans += q[i];
  cout << ans << endl;
}
