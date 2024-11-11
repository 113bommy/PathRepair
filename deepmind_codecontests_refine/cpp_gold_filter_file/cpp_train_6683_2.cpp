#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int N = 1e5 + 20, inf = 1e18 + 20;
int n, m, a[N];
ll k;
vector<int> vec;
int cnt[N];
ll sum[N];
inline ll calc(int x, int y) {
  int xx = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  int yy = lower_bound(vec.begin(), vec.end(), y) - vec.begin();
  ll res = 0;
  res += 1ll * cnt[xx] * x - sum[xx];
  res += (sum[m] - sum[yy]) - 1ll * (cnt[m] - cnt[yy]) * y;
  return res;
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i], vec.push_back(a[i]);
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  m = (int)vec.size();
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
  for (int i = 0; i < n; i++) {
    cnt[a[i] + 1]++;
    sum[a[i] + 1] += vec[a[i]];
  }
  for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];
  int ans = inf;
  for (int x : vec) {
    int low = x - 1, high = inf;
    while (high - low > 1) {
      int y = (low + high) / 2;
      if (calc(x, y) <= k)
        high = y;
      else
        low = y;
    }
    ans = min(ans, high - x);
    low = -inf, high = x + 1;
    while (high - low > 1) {
      int y = (low + high) / 2;
      if (calc(y, x) <= k)
        low = y;
      else
        high = y;
    }
    ans = min(ans, x - low);
  }
  cout << ans << '\n';
}
