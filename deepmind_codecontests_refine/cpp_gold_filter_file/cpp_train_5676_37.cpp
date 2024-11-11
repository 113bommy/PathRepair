#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
long long limit, cf, cm, m;
int a[N];
pair<int, int> b[N];
long long s[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> limit >> cf >> cm >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) b[i] = make_pair(a[i], i);
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; ++i) a[i] = b[i].first;
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
  long long res = 0;
  int bestPos = 0;
  long long bestMin = 0;
  for (int i = n; i >= 0; --i) {
    long long suf = s[n] - s[i];
    long long all = limit * (n - i);
    if (all - suf > m) break;
    long long rem = m - (all - suf);
    long long l = 0, r = limit, ans = 0;
    while (l <= r) {
      long long mid = l + r >> 1;
      int last = lower_bound(a + 1, a + 1 + i, mid) - a - 1;
      if (mid * last - s[last] <= rem)
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    long long cur = cf * (n - i) + ans * cm;
    if (res <= cur) {
      res = cur;
      bestPos = i;
      bestMin = ans;
    }
  }
  cout << res << endl;
  vector<int> ans(n + 1);
  for (int i = 1; i <= bestPos; ++i)
    ans[b[i].second] = max((long long)a[i], bestMin);
  for (int i = bestPos + 1; i <= n; ++i) ans[b[i].second] = limit;
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
  return 0;
}
