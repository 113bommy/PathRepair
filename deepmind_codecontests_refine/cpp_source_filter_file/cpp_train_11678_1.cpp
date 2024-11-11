#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 2;
long long a[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k, i, j;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  long long ans = LLONG_MIN;
  for (i = 0; i < m; i++) {
    long long temp = 0;
    for (j = 0; j < n; j++) {
      temp += a[j];
      if (j % m == i) temp -= k, ans = max(ans, temp);
      temp = max(temp, 0LL);
    }
  }
  cout << ans << "\n";
}
