#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
  while (cin >> n >> m >> k) {
    long long ans = 1;
    if (k > 1 && k < n) {
      if (k % 2 == 0)
        ans = m;
      else
        ans = m * m % 1000000007;
    } else if (k == 1 || k > n) {
      for (int i = 0; i < n; ++i) {
        ans *= m;
        ans %= 1000000007;
      }
    } else if (k == n) {
      if (n % 2 == 0)
        n /= 2;
      else
        n = (n / 2) + 1;
      for (int i = 0; i < n; ++i) {
        ans *= m;
        ans %= 1000000007;
      }
    }
    cout << ans << endl;
  }
}
