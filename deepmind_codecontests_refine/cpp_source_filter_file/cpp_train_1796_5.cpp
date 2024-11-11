#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int odd = k - 1;
    int even = 2 * (k - 1);
    if (n - odd > 0 && (n - odd) & 1) {
      cout << "YES" << '\n';
      while (k-- > 1) cout << 1 << " ";
      cout << n - odd << '\n';
    } else if (n - even > 0 && (n - even) % 2 == 0) {
      cout << "YES" << '\n';
      while (k-- > 1) cout << 2 << " ";
      cout << n - odd << '\n';
    } else
      cout << "NO" << '\n';
  }
}
