#include <bits/stdc++.h>
using namespace std;
constexpr long long N = 2e5 + 5;
constexpr long long M = 998244353;
long long n;
pair<long long, long long> a[N];
long long pos[N];
long long ans[N];
long long len(pair<long long, long long> p) {
  return p.first * p.first + p.second * p.second;
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  cin >> n;
  for (long long i = 1; i <= n; i++)
    cin >> a[i].first >> a[i].second, pos[i] = i, ans[i] = 1;
  pair<long long, long long> p = {0, 0};
  for (long long i = 1; i <= n; i++) {
    if (len({p.first + a[i].first, p.second + a[i].second}) <
        len({p.first - a[i].first, p.second - a[i].second})) {
      ans[i] = 1;
      p.first += a[i].first, p.second += a[i].second;
    } else {
      ans[i] = -1;
      p.first -= a[i].first, p.second -= a[i].second;
    }
  }
  for (long long i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
