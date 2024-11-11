#include <bits/stdc++.h>
using namespace std;
const long long o = 1e5 + 1;
struct qwq {
  long long x, y;
} a[o];
long long n, ans = 1e18;
bool cmp1(qwq u, qwq v) { return u.x < v.x; }
long long dis(qwq u, qwq v) {
  return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (long long i = 1, x; i <= n; i++)
    cin >> x, a[i] = (qwq){i, a[i - 1].y + x};
  sort(a + 1, a + n + 1, cmp1);
  for (long long i = 1; i <= n; i++)
    for (long long j = i + 1; j <= min(n, i + 3000); j++)
      ans = min(ans, dis(a[i], a[j]));
  cout << ans;
  return 0;
}
