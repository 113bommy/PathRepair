#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10, MN = 1e5 + 10;
long long lim[MN], Less[MN], n, m, k, p;
long long h[MN], a[MN];
set<pair<long long, long long> > S;
void calc(long long id, long long L) {
  long long tmp = (L + 1ll * Less[id] * p) / a[id] + 1;
  if (tmp > m) {
    if (1ll * a[id] * m - 1ll * Less[id] * p + h[id] > L)
      lim[id] = m;
    else
      lim[id] = m + 1;
  } else
    lim[id] = tmp - 1;
}
bool check(long long L) {
  memset(Less, 0, sizeof Less), memset(lim, 0, sizeof lim);
  S.clear();
  for (long long i = 0; i < n; ++i) {
    calc(i, L);
    S.insert({lim[i], i});
  }
  for (long long i = 1, rp = k; i <= m; ++i, rp = k) {
    while (rp--) {
      auto my = S.begin();
      long long id = my->second;
      if (lim[id] < i) return false;
      S.erase(my);
      ++Less[id];
      calc(id, L);
      S.insert({lim[id], id});
    }
  }
  for (long long i = 0; i < n; ++i)
    if (1ll * a[i] * m + h[i] - 1ll * Less[i] * p > L) return false;
  return true;
}
int32_t main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k >> p;
  for (long long i = 0; i < n; ++i) cin >> h[i] >> a[i];
  long long L = 0,
            R = 1ll * k * (*max_element(h, h + n)) + *max_element(a, a + n);
  while (L != R) {
    long long mid = L + R >> 1;
    if (check(mid))
      R = mid;
    else
      L = mid + 1;
  }
  cout << L << '\n';
  return 0;
}
