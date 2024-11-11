#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
pair<int, int> a[maxn];
int n, A, cf, cm;
long long m;
long long sum[maxn];
int ans2[maxn];
int main() {
  cin >> n >> A >> cf >> cm >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n);
  sum[0] = 0;
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i].first;
  pair<long long, pair<int, int>> ans;
  ans.first = -1;
  for (int i = 0; i <= n; i++) {
    int l = 0, r = A;
    int minlevel;
    while (l <= r) {
      int mid = (l + r) / 2;
      int pos = lower_bound(a + 1, a + 1 + n - i, make_pair(mid, -1)) - a;
      if (1ll * mid * pos - sum[pos] <= m) {
        minlevel = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    ans = max(ans, {1ll * cf * i + 1ll * cm * minlevel, {i, minlevel}});
    m -= A - a[n - i].first;
    if (m < 0) break;
  }
  cout << ans.first << endl;
  for (int i = 1; i <= n; i++) {
    if (i <= n - ans.second.first)
      ans2[a[i].second] = max(a[i].first, ans.second.second);
    else
      ans2[a[i].second] = A;
  }
  for (int i = 1; i <= n; i++) cout << ans2[i] << " ";
  cout << endl;
  return 0;
}
