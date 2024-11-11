#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[1001], x, ans;
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) cin >> a[i];
  cin >> x;
  for (int i = 1; i <= m; i++) {
    int y = a[i], mask = 1, cnt = 0;
    for (int j = 0; j <= n; j++) {
      if (x & mask != y & mask) cnt++;
      mask = mask << 1;
    }
    if (cnt < k) ans++;
  }
  cout << ans;
  return 0;
}
