#include <bits/stdc++.h>
using namespace std;
int a[10009];
int main() {
  int n, i, tc, ans;
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    ans = 1;
    for (i = 0; i < n; i++) {
      if (a[i] - a[i - 1] <= 1) {
        ans = 2;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
