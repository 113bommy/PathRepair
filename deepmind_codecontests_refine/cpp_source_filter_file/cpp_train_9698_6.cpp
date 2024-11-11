#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100 * 1000 + 10;
long long b[MAXN], g[MAXN], t[MAXN];
map<long long, long long> cnt;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long mx = LLONG_MIN, mn = LLONG_MAX;
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    cnt[b[i]]++;
    mx = max(mx, b[i]);
  }
  sort(b, b + n);
  long long k = m;
  for (long long i = 0; i < k; i++) {
    cin >> g[i];
    mn = min(mn, g[i]);
    if (cnt[g[i]]) {
      cnt[g[i]]--;
      i--;
      k--;
    }
  }
  if (mn < mx) return (cout << -1 << endl, 0);
  long long ans = 0;
  for (long long i = 0; i < n; i++) ans += m * b[i];
  long long l = n - 1;
  for (long long i = 0; i < m; i++) {
    if (t[l] >= m - 1) l--;
    ans += g[i] - b[l];
    t[l]++;
  }
  cout << ans << endl;
  return 0;
}
