#include <bits/stdc++.h>
using namespace std;
long long n, m, k, ans;
int main() {
  cin >> n >> m >> k;
  m -= n;
  while (m >= 0) {
    if (min(ans, k) == k && min(ans - 1, n - k) == n - k) {
      ans += m / n + 1;
      break;
    } else {
      ans++;
      m -= min(ans, k);
      m -= min(ans - 1, n - k);
    }
  }
  cout << ans;
  return 0;
}
