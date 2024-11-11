#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i;
    for (i = 1; i * i < n; i++)
      ;
    int x = ((i - 1) * (i - 1) + 1 + i * i) / 2;
    if (x == n) {
      cout << i << ' ' << i;
      cout << '\n';
      ;
      continue;
    }
    if (x > n) {
      cout << n - ((i - 1) * (i - 1) + 1) + 1 << ' ' << i;
      cout << '\n';
      ;
      continue;
    }
    cout << i << ' ' << abs(n - i * i) + 1 << '\n';
  }
  return 0;
}
