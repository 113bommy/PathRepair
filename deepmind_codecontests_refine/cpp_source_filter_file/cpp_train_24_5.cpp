#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t, i, j, a, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int a[n + 5], f = 0;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 0; i < n - 2; i++) {
      if (a[i] + a[i + 1] <= a[i + 2]) {
        cout << i + 1 << " " << i + 2 << " " << i + 3 << '\n';
        f = 1;
        break;
      }
    }
    if (f == 0) cout << -1 << '\n';
  }
  return 0;
}
