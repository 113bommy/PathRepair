#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)(1e5 + 1e1);
const double PI = acos(-1.0);
long long n, a[MAXN], ans, k, mn = (int)(1e9 + 11);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i], mn = min(a[i], mn);
  for (int i = 1; i <= n; i++) {
    if ((a[i] - mn) % k != 0) {
      cout << -1;
      return 0;
    }
    ans += (a[i] - mn) / k;
  }
  cout << ans;
  return 0;
}
