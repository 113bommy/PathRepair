#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, i, ans;
  while (cin >> n >> m >> k) {
    if (m == 1) {
      cout << 1 << endl;
      continue;
    }
    if (k == 1 || k > n) {
      ans = 1;
      for (i = 1; i <= n; i++) {
        ans = ans * m % 1000000007;
      }
      cout << ans << endl;
      continue;
    }
    if (k % 2 && k < n) {
      ans = m;
      ans += m * (m - 1);
      cout << ans << endl;
      continue;
    }
    if (k < n) {
      cout << m << endl;
      continue;
    }
    ans = 1;
    for (i = 1; i <= n / 2; i++) {
      ans = ans * m % 1000000007;
    }
    if (n % 2) ans = ans * m % 1000000007;
    cout << ans << endl;
  }
}
