#include <bits/stdc++.h>
using namespace std;
int n, a[400005];
long long res, sum[400005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], a[n + i] = a[i], res += a[i];
  for (int i = 2 * n; i >= 1; i--) {
    sum[i] = sum[i + 2] + a[i];
  }
  if (n == 1) {
    cout << res;
    return 0;
  }
  long long subMin = 1ll * 1000000007 * 1000000007;
  if (n == 3) {
    for (int i = 1; i <= 3; i++) subMin = min(subMin, 1ll * a[i]);
  } else {
    for (int i = 1; i <= n; i++) {
      int j = i + 3;
      subMin = min(subMin, sum[j] - sum[j + n - 3] + a[i]);
    }
  }
  cout << res - subMin;
}
