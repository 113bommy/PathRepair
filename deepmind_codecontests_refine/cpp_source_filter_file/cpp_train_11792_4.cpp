#include <bits/stdc++.h>
using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
void solve() {
  int n, k;
  pii a, b;
  cin >> n >> k >> a.first >> a.second >> b.first >> b.second;
  li cur = 0;
  li d = 0;
  {
    int x1 = max(a.first, b.first);
    int y1 = min(a.second, b.second);
    if (x1 <= y1) {
      cur += (y1 - x1) * n;
      d = max(a.second, b.second) - min(a.first, b.first) - (y1 - x1);
    } else {
      d = -max(a.first, b.first) + min(a.second, b.second);
    }
  }
  if (cur >= k) {
    cout << 0 << endl;
    return;
  }
  k -= cur;
  li ans = 0;
  if (d >= 0) {
    if (d * 1ll * n >= k) {
      cout << k << endl;
      return;
    } else {
      ans += d * n;
      k -= d * n;
    }
    cout << ans + k * 2 << endl;
    return;
  }
  li res = 1e18;
  for (int i = 0; i < n; i++) {
    ans += -d;
    li l = max(a.second, b.second) - min(a.first, b.first);
    if (l >= k) {
      ans += k;
      res = min(res, ans);
      break;
    } else {
      ans += l;
      k -= l;
    }
    res = min(res, k * 2 + ans);
  }
  cout << res << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
