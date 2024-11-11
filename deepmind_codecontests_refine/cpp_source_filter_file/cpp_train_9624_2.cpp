#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
int main() {
  cin >> n >> m >> k;
  if (n + m - 2 < k) {
    cout << -1 << endl;
    return 0;
  }
  if (n < m) swap(n, m);
  long long ans;
  if (n - 1 > k) {
    ans = n / (k + 1) * m;
    if (m - 1 > k) ans = max(ans, m / (k + 1) * n);
    cout << ans << endl;
  } else {
    k -= (n - 1);
    ans = m / (k + 1);
    cout << ans << endl;
  }
  return 0;
}
