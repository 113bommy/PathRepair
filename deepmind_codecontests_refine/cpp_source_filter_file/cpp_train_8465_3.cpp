#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 228;
const long long md1 = 1000000021LL, md2 = 1000000007LL;
long long st[2][N], ob[N];
pair<long long, long long> hsh[N];
int x[N], y[N];
long long bin_pow(long long a, long long b, long long md) {
  if (!b) return 1;
  long long res = bin_pow(a, b >> 1LL, md);
  res *= res;
  res %= md;
  if (b & 1) res = a * res % md;
  return res;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  st[0][0] = st[1][0] = 1;
  for (int i = 1; i <= n; i++) {
    st[0][i] = 2LL * st[0][i - 1] % md1;
    st[1][i] = 2LL * st[1][i - 1] % md1;
  }
  for (int i = 0; i < m; i++) {
    scanf("%I64d%I64d", &x[i], &y[i]);
    hsh[x[i]] = make_pair((hsh[x[i]].first + st[0][y[i]]) % md1,
                          (hsh[x[i]].second + st[1][y[i]]) % md2);
    hsh[y[i]] = make_pair((hsh[y[i]].first + st[0][x[i]]) % md1,
                          (hsh[y[i]].second + st[1][x[i]]) % md2);
  }
  unordered_map<long long, long long> mp;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ;
    ans += mp[hsh[i].first * md2 + hsh[i].second]++;
  }
  for (int i = 0; i < m; i++) {
    pair<long long, long long> c = make_pair(
        hsh[x[i]].first - st[0][y[i]] - hsh[y[i]].first + st[0][x[i]],
        hsh[x[i]].second - st[1][y[i]] - hsh[y[i]].second + st[1][x[i]]);
    c.first += md1 * 4LL;
    c.first %= md1;
    c.second += md2 * 4LL;
    c.second %= md2;
    if (c == make_pair(0LL, 0LL)) ans++;
  }
  cout << ans << "\n";
}
