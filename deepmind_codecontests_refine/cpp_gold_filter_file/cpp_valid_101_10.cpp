#include <bits/stdc++.h>
using namespace std;
const int N = 300005, mod = 998244353;
int a[N], b[N], px[N], py[N];
int cx[1000005], cy[1000005];
map<pair<int, int>, int> p1, p2;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= k; i++) cin >> px[i] >> py[i];
  long long ans = 0;
  for (int i = 1; i <= k; i++) {
    int x = px[i], y = py[i], l = 1, r = n, res = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid] >= x)
        res = a[mid], r = mid - 1;
      else
        l = mid + 1;
    }
    if (res != x) {
      ans += cx[res];
      cx[res]++;
      ans -= p1[{res, y}];
      p1[{res, y}]++;
    }
    l = 1, r = m, res = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (b[mid] >= y)
        res = b[mid], r = mid - 1;
      else
        l = mid + 1;
    }
    if (res != y) {
      ans += cy[res], cy[res]++;
      ans -= p2[{x, res}], p2[{x, res}]++;
    }
  }
  p1.clear(), p2.clear();
  for (int i = 1; i <= n; i++) cx[a[i]] = 0;
  for (int i = 1; i <= m; i++) cy[b[i]] = 0;
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
