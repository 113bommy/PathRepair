#include <bits/stdc++.h>
using namespace std;
long long int i, j, n;
long long int a[100005];
int main() {
  long long int u;
  cin >> n >> u;
  for (i = 0; i < n; i++) cin >> a[i];
  double ans = 0.0;
  for (i = n - 2; i >= 1; i--) {
    long long int t = a[i] - a[i - 1];
    long long int p = upper_bound(a, a + n, u + a[i - 1]) - a;
    p--;
    long long int ek;
    if (p >= i + 1) {
      ek = a[p];
      double z = (1.0 * (ek - a[i])) / (ek - a[i - 1]);
      ans = max(ans, z);
    }
  }
  if (ans == 1) {
    cout << 0;
    return 0;
  }
  if (ans == 0) {
    cout << -1;
  } else
    printf("%0.6lf", ans);
  return 0;
}
