#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10, md = 1e9 + 7;
long long a[MAXN], cnt[MAXN];
vector<long long> d[MAXN];
long long power(long long n, long long p) {
  long long res = 1;
  for (; p; p >>= 1, n = n * n % md)
    if (p & 1) res = res * n % md;
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  for (long long i = 1; i < MAXN; ++i) cnt[i] += cnt[i - 1];
  for (long long i = 1; i < MAXN; ++i)
    for (long long j = i; j < MAXN; j += i) d[j].push_back(i);
  long long ans = 0;
  for (long long mx = 1; mx < MAXN; ++mx) {
    long long now = 1, last = 0, s = d[mx].size();
    for (long long i = 0; i < s; ++i) {
      now = now * power(i, cnt[d[mx][i] - 1] - last) % md;
      last = cnt[d[mx][i] - 1];
    }
    now = now * power(s, n - last) % md;
    long long now1 = 1;
    last = 0;
    for (long long i = 0; i < s - 1; ++i) {
      now1 = now1 * power(i, cnt[d[mx][i] - 1] - last) % md;
      last = cnt[d[mx][i] - 1];
    }
    now1 = now1 * power(s - 1, n - last) % md;
    ans += now - now1 + md * 2;
    if (ans >= md) ans %= md;
  }
  cout << ans;
  return 0;
}
