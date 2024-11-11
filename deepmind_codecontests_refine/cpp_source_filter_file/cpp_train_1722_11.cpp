#include <bits/stdc++.h>
using namespace std;
int n, k, m, ans, a[1005], b[1005];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int j = 1; j <= 1000; j++) {
    for (int i = 1; i <= n; i++) {
      if (b[i] >= a[i]) {
        b[i] -= a[i];
      } else {
        m += a[i] - b[i];
        b[i] = 0;
      }
    }
    if (m <= k)
      ans++;
    else
      break;
  }
  cout << ans;
}
