#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const long long maxn = (long long)1e6 + 5;
const long long mod = (long long)998244353;
const long long inf = 0x3f3f3f3f3f3f3f3f;
pair<long long, long long> ans[4];
inline long long dis(const pair<long long, long long> &a,
                     const pair<long long, long long> &b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
pair<long long, long long> a[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    if (i == 1)
      for (long long j = 0; j < 4; ++j) ans[j] = a[i];
    else {
      if (ans[0].first > a[i].first) ans[0] = a[i];
      if (ans[2].first < a[i].first) ans[2] = a[i];
      if (ans[1].second < a[i].second) ans[1] = a[i];
      if (ans[3].second > a[i].second) ans[3] = a[i];
    }
  }
  long long cnt = 0;
  for (long long i = 0; i < 4; ++i) {
    for (long long j = 0; j < 4; ++j) {
      if (i == j) continue;
      long long tmp = dis(ans[i], ans[j]);
      for (long long k = 1; k <= n; ++k)
        cnt = max(cnt, tmp + dis(ans[i], a[k]) + dis(ans[j], a[k]));
    }
  }
  cout << cnt << ' ';
  cnt = 0;
  for (long long i = 0; i < 3; ++i) cnt += dis(ans[i], ans[i + 1]);
  cnt += dis(ans[3], ans[0]);
  for (long long i = 4; i <= n; ++i) cout << cnt << ' ';
  return 0;
}
