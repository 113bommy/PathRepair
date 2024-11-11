#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t n, k;
    cin >> n >> k;
    int64_t aa, bb;
    int64_t cc, dd;
    cin >> aa >> bb;
    cin >> cc >> dd;
    if (aa > cc) {
      swap(aa, cc);
      swap(bb, dd);
    }
    int64_t st = 0;
    int64_t tt = 0;
    if (bb >= cc) {
      st = 0;
      k -= n * (min(bb, dd) - cc);
      k = max(k, (int64_t)0);
    } else {
      st = cc - bb;
    }
    if (k == 0) {
      cout << 0 << endl;
      continue;
    }
    int64_t ans = 1e15;
    int64_t cost = 0;
    int64_t cur = 0;
    int64_t val = (max(bb, dd) - min(aa, cc));
    int64_t ko = val * 2 - (bb - aa) - (dd - cc);
    val -= -max((int64_t)0, min(bb, dd) - max(aa, cc));
    for (int64_t i = 1; i <= n; i++) {
      if (cur + val >= k) {
        ans = min(ans, cost + st + k - cur);
        break;
      }
      cur += val;
      cost += ko;
      ans = min(ans, cost + 2 * (k - cur));
    }
    cout << ans << '\n';
  }
  return 0;
}
