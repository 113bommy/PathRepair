#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int n;
int a[N];
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) continue;
    int tmp = a[i] * 2;
    int range = (a[n - 1] / a[i] + 1) * a[i];
    while (tmp <= range) {
      int p = lower_bound(a + 1, a + 1 + n, tmp) - (a + 1);
      if (p >= 1) ans = max(ans, a[p] % a[i]);
      tmp += a[i];
    }
  }
  cout << ans;
}
