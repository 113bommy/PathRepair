#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, m, k, ta, tb, a[N], b[N], ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> ta >> tb >> k;
  if (k >= n || k >= m) return cout << -1 << endl, 0;
  for (int i = 1, iE = n; i <= iE; i++) cin >> a[i];
  for (int i = 1, iE = m; i <= iE; i++) cin >> b[i];
  for (int i = 0, iE = k; i <= iE; i++) {
    if (a[i + 1] + ta > b[m - (k - i)]) return cout << -1 << endl, 0;
    int wz = lower_bound(b + 1, b + n + 1, a[i + 1] + ta) - b;
    ans = max(ans, b[wz + (k - i)] + tb);
  }
  cout << ans << endl;
  return 0;
}
