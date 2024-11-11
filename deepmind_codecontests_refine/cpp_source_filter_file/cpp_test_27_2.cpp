#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  T = 1;
  cin >> T;
  while (T--) {
    int i, j, k, m, n, l, res = 0, ans = 0;
    cin >> n >> m >> k;
    k -= 2;
    if (m < n - 1) {
      cout << "NO" << '\n';
    } else if (m > n * (n - 1) / 2) {
      cout << "NO" << '\n';
    } else if (k == 0) {
      if (n == 1) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    } else if (k < 0) {
      cout << "NO" << '\n';
    } else if (k == 1) {
      if (m == n * (n - 1) / 2) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    } else {
      cout << "YES" << '\n';
    }
  }
}
