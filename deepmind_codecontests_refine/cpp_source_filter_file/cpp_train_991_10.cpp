#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int t[n];
  for (i = 0; i < n; i++) cin >> t[i];
  int ans = 90;
  if (t[0] > 15) {
    cout << 15 << endl;
    return 0;
  }
  for (i = 0; i < n - 1; i++) {
    if (t[i + 1] - t[i] > 15) {
      ans = t[i] + 15;
      cout << ans << endl;
      return 0;
    }
  }
  if (90 - t[n - 1] > 15) {
    ans = t[n] + 15;
    cout << ans << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
