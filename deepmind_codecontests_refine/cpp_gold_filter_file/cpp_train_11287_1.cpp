#include <bits/stdc++.h>
using namespace std;
void Solve() {
  long long n;
  cin >> n;
  long long a[n + 1];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (n == 1) {
    cout << "-1\n";
    return;
  }
  if (n == 2) {
    long long d = a[1] - a[0];
    if (d == 0)
      cout << "1\n" << a[0] << endl;
    else if (d & 1)
      cout << "2\n" << a[0] - d << " " << a[1] + d << endl;
    else
      cout << "3\n"
           << a[0] - d << " " << a[0] + d / 2 << " " << a[1] + d << endl;
    return;
  }
  long long d = a[1] - a[0];
  for (long long i = 1; i < n; i++) d = min(a[i] - a[i - 1], d);
  long long ans = 0, f = 0;
  for (long long i = 1; i < n; i++)
    if (a[i] != a[i - 1] + d) {
      a[n] = a[i - 1] + d;
      ans = a[i - 1] + d;
      f = 1;
      break;
    }
  if (f == 0) {
    if (d == 0)
      cout << "1\n" << a[0] << endl;
    else
      cout << "2\n" << a[0] - d << " " << a[n - 1] + d << endl;
  } else {
    n += 1;
    sort(a, a + n);
    for (long long i = 1; i < n; i++)
      if (a[i] != a[i - 1] + d) {
        cout << "0\n";
        return;
      }
    cout << "1\n" << ans << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  Solve();
  return 0;
}
