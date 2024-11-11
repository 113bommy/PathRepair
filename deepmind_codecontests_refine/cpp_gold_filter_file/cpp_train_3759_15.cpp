#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 100 + 10;
int n, yy1, a[maxn], m, yy2, b[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> yy1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> m >> yy2;
  for (int i = 1; i <= m; i++) cin >> b[i];
  int ans = 2;
  for (int mod = 2; mod <= 1e9; mod *= 2) {
    map<int, int> mp;
    mp.clear();
    for (int i = 1; i <= n; i++) ans = max(ans, ++mp[a[i] % mod]);
    for (int i = 1; i <= m; i++) ans = max(ans, ++mp[(b[i] + mod / 2) % mod]);
  }
  cout << ans << endl;
  return 0;
}
