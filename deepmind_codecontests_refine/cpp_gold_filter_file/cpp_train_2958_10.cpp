#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, flag, ans, a[101], b[101];
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  flag = 0;
  for (i = 0; i < n; i++) {
    if (2 * a[i] < b[0] && 2 * a[i] >= a[n - 1]) {
      flag = 1;
      ans = 2 * a[i];
      break;
    }
  }
  if (a[n - 1] < b[0] && 2 * a[0] <= a[n - 1])
    cout << a[n - 1] << endl;
  else if (flag == 1)
    cout << ans << endl;
  else
    cout << "-1" << endl;
  return 0;
}
