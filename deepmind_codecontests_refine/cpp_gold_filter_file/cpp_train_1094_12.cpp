#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long a[N], n, pref[N];
double calc(long long i, long long mid) {
  return 1.0 * (pref[n] - pref[n - mid] + pref[i] - pref[i - mid - 1]) /
         (mid * 2 + 1);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  double res = 0;
  pair<long long, long long> id;
  for (long long i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i];
  }
  for (long long i = 1; i <= n; ++i) {
    double ans = 0;
    long long l = 1, r = min(i - 1, n - i), t = 0;
    if (a[n] == a[i]) break;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      double cur = calc(i, mid), nxt, pre;
      nxt = pre = -1;
      if (mid != min(i - 1, n - 1)) nxt = calc(i, mid + 1);
      if (mid != 1) pre = calc(i, mid - 1);
      if (cur > ans) {
        ans = cur;
        t = mid;
      }
      if (nxt > cur)
        l = mid + 1;
      else if (pre > cur)
        r = mid - 1;
      else
        break;
    }
    if (ans - a[i] >= res) {
      res = ans - a[i];
      id = pair<long long, long long>(i, t);
    }
  }
  if (res == 0) id = pair<long long, long long>(1, 0);
  long long l = id.first - 1, r = n;
  cout << 2 * id.second + 1 << endl;
  vector<long long> op;
  op.clear();
  op.push_back(a[id.first]);
  while (id.second--) {
    op.push_back(a[l]);
    op.push_back(a[r]);
    l--;
    r--;
  }
  sort(op.begin(), op.end());
  for (long long x : op) cout << x << ' ';
  return 0;
}
