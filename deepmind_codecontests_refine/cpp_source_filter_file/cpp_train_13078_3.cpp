#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 360;
  cin >> n;
  int a[n + 1];
  a[n] = 0;
  cin >> a[0];
  if (n == 1)
    cout << ans << endl;
  else {
    for (int i = 1; i < n; i++) {
      cin >> a[i];
      a[i] = a[i] + a[i - 1];
    }
    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        ans = min(ans, 2 * abs(180 - (a[k] - a[j > 0 ? j - 1 : n])));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
