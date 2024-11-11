#include <bits/stdc++.h>
using namespace std;
const long long N = 3005;
long long f[N][N], n, a[N], val[N];
signed main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i], a[i] -= i;
  map<long long, long long> mp;
  for (long long i = 1; i <= n; i++) mp[a[i]]++;
  long long ind = 0;
  for (auto &[x, y] : mp) y = ++ind, val[ind] = x;
  for (long long i = 1; i <= n; i++) a[i] = mp[a[i]];
  for (long long i = 1; i <= n; i++) {
    long long mn = 1e18;
    for (long long j = 1; j <= ind; j++) {
      mn = min(mn, f[i - 1][j]);
      f[i][j] = mn + abs(val[a[i]] - val[j]);
    }
  }
  cout << *min_element(f[n] + 1, f[n] + ind + 1) << endl;
}
