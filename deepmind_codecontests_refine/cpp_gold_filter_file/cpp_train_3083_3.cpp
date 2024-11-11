#include <bits/stdc++.h>
using namespace std;
long long h, w, k, Q;
long long a[505][505];
long long dp[505][505];
bool check(long long t) {
  for (long long(y) = (1); (y) <= (h); (y)++) {
    for (long long(x) = (1); (x) <= (w); (x)++) {
      if (a[x][y] > t)
        dp[x][y] = 0;
      else
        dp[x][y] = min(dp[x - 1][y], min(dp[x][y - 1], dp[x - 1][y - 1])) + 1;
      if (dp[x][y] >= k) return true;
    }
  }
  return false;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> h >> w >> k >> Q;
  for (long long(y) = (0); (y) <= (h); (y)++)
    for (long long(x) = (0); (x) <= (w); (x)++) a[x][y] = 1e18;
  long long x, y, t;
  for (long long(i) = (1); (i) <= (Q); (i)++) {
    cin >> y >> x >> t;
    a[x][y] = t;
  }
  long long ub = 1e9 + 7, lb = -1, mid;
  while (ub - lb > 1) {
    mid = (ub + lb) / 2;
    if (check(mid))
      ub = mid;
    else
      lb = mid;
  }
  if (ub > 1e9 + 3) ub = -1;
  cout << ub << endl;
  return 0;
}
