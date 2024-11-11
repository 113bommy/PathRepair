#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7, maxn = 1e5 + 50;
long long int ans, q, k, n, m, x, y;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> n;
    if (n < 3)
      cout << -1 << endl;
    else {
      if (n % 2) {
        for (long long int i = n; i >= 5; i -= 2) {
          cout << i << " ";
        }
        cout << "3 1 4 2 ";
        for (long long int i = 6; i < n; i += 2) cout << i << " ";
        cout << endl;
      } else {
        for (long long int i = n - 1; i >= 5; i -= 2) {
          cout << i << " ";
        }
        cout << "3 1 4 2 ";
        for (long long int i = 6; i <= n; i += 2) cout << i << " ";
        cout << endl;
      }
    }
  }
  return 0;
}
