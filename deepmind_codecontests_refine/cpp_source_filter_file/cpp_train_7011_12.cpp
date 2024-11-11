#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, ans = 0;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long k = pow(i, 2);
      long long l = pow(j, 2);
      if (k + j == n && l + i == m) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
