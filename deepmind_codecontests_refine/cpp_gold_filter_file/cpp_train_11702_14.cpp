#include <bits/stdc++.h>
using namespace std;
int const mxn = 1e5 + 10;
int inf = 1e9;
int mn[mxn], ll[mxn], dp[mxn];
int ans = 1;
int main() {
  ans = 1;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ll[i];
  fill(mn, mn + mxn, inf);
  for (int i = 0; i < n; i++) {
    mn[1] = min(mn[1], ll[i]);
    long long l = 1, r = 1e5 + 1, mid;
    while (r - l > 1) {
      mid = (r + l) / 2;
      if (ll[i] > mn[mid])
        l = mid;
      else
        r = mid;
    }
    dp[i] = r;
    mn[r] = min(ll[i], mn[r]);
    ans = max(ans, dp[i]);
  }
  cout << ans - 1 << endl;
}
