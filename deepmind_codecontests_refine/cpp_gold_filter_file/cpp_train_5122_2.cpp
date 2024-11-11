#include <bits/stdc++.h>
using namespace std;
long long cntbits(long long x) {
  long long cnt = 0;
  while (x) {
    cnt += (x % 2);
    x /= 2;
  }
  return cnt;
}
int32_t main() {
  long long n, p;
  cin >> n >> p;
  if (p >= n) {
    cout << -1;
    return 0;
  }
  long long ans = 1e18;
  for (long long tm = 0; tm < 10000; ++tm) {
    long long x = n - p * tm;
    if (x < tm) continue;
    if (cntbits(x) > tm) continue;
    ans = min(ans, tm);
    break;
  }
  if (ans != 1e18)
    cout << ans;
  else
    cout << -1;
}
