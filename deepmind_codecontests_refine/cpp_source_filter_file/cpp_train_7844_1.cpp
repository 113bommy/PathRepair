#include <bits/stdc++.h>
using namespace std;
int a[200];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (n < 3 || (n % 2 == 0)) {
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  for (int i = (n - 1) / 2; i > 0; i--) {
    ans += max(a[2 * i], a[2 * i + 1]);
    a[i] = max(0, a[i] - max(a[2 * i], a[2 * i + 1]));
    a[2 * i] = a[2 * i + 1] = 0;
  }
  ans += a[0];
  cout << ans << endl;
}
