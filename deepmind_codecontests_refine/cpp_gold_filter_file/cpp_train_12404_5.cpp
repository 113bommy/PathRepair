#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, A = 1e5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, r;
  cin >> n >> m >> r;
  long long a[n], b[m], mn = 1e18, mx = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    mx = max(mx, b[i]);
  }
  if (mn >= mx)
    cout << r;
  else {
    if (mn > r)
      cout << r;
    else {
      long long x = r % mn, y = r / mn, z = y * mx, ans = x + z;
      cout << ans;
    }
  }
  return 0;
}
