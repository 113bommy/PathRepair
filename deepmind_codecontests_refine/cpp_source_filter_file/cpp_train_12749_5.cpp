#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, l;
  cin >> n >> l;
  long long a[n + 2];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = 0;
  a[n + 1] = l;
  sort(a + 1, a + n + 2);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      double d = a[i];
      ans = max(ans, d);
    } else {
      double d = (abs(a[i] - a[i - 1])) / 2.0;
      ans = max(ans, d);
    }
  }
  double d = a[n] - l;
  ans = max(ans, d);
  cout << setprecision(10) << fixed << ans << endl;
}
