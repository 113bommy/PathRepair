#include <bits/stdc++.h>
using namespace std;
const long long max_n = 1e5 + 20;
long long n, m, k, mn = 1e9 + 20, tmp1, tmp2, cnt = 1;
pair<long long, long long> a[max_n], b[max_n];
string s;
long long alert, v, mark[max_n], e[max_n];
long long ans;
int32_t main() {
  cin >> n;
  for (long long i = 0; i < n; i++)
    cin >> a[i].first >> a[i].second, ans += a[i].second;
  cin >> m;
  for (long long i = 0; i < m; i++)
    cin >> b[i].first >> b[i].second, ans += b[i].second;
  sort(a, a + n), sort(b, b + m);
  for (long long i = 0; i < n; i++) {
    pair<long long, long long> tmp =
        *(lower_bound(b, b + m, make_pair(a[i].first, 0LL)));
    if (tmp.first == a[i].first) ans -= min(a[i].second, tmp.second);
  }
  cout << ans;
  return 0;
}
