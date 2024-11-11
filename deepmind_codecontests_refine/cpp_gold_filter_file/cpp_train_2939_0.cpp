#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;
const int N = 5001, MOD = 1e9 + 7;
int a[N], f[N], h[N], tc[N], cc[N];
ll rr;
vector<int> lf[N];
int fc(int x) {
  int c1 = cc[x], c2 = tc[x] - c1;
  if (c1 > c2) swap(c1, c2);
  ll p1 = lower_bound((lf[x]).begin(), (lf[x]).end(), c1 + 1) - lf[x].begin(),
     p2 = lower_bound((lf[x]).begin(), (lf[x]).end(), c2 + 1) - lf[x].begin();
  if (p1 > 0 && p2 > 1) {
    rr = p1 * (p2 - 1);
    return 2;
  }
  if (p2 > 0) {
    rr = p1 + p2;
    return 1;
  }
  rr = 1;
  return 0;
}
ll pw(ll x, ll k) {
  ll r = 1;
  while (k) {
    if (k & 1) r = r * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    a[i]--;
    tc[a[i]]++;
  }
  for (int i = 0; i < (m); i++) {
    cin >> f[i] >> h[i];
    f[i]--;
    lf[f[i]].push_back(h[i]);
  }
  int ans = 0, ca = 0;
  for (int i = 0; i < (n); i++) {
    sort((lf[i]).begin(), (lf[i]).end());
    if (!lf[i].empty() && lf[i][0] <= tc[i]) ca++;
  }
  for (int i = 0; i < (n); i++) {
    ans = max(ans, ca);
    ca -= fc(a[i]);
    cc[a[i]]++;
    ca += fc(a[i]);
  }
  ans = max(ans, ca);
  ll res = 0, cr = 1;
  ca = 0;
  for (int i = 0; i < (n); i++) {
    int pos =
        lower_bound((lf[i]).begin(), (lf[i]).end(), tc[i] + 1) - lf[i].begin();
    if (pos) {
      ca++;
      cr = cr * pos % MOD;
    }
  }
  for (int i = 0; i < (n); i++) cc[i] = 0;
  if (ca == ans) res = cr;
  for (int i = 0; i < (n); i++) {
    ca -= fc(a[i]);
    cr = cr * pw(rr, MOD - 2) % MOD;
    cc[a[i]]++;
    ca += fc(a[i]);
    if (ca == ans) {
      ll p1 = lower_bound((lf[a[i]]).begin(), (lf[a[i]]).end(), cc[a[i]]) -
              lf[a[i]].begin(),
         p2 = lower_bound((lf[a[i]]).begin(), (lf[a[i]]).end(),
                          tc[a[i]] - cc[a[i]] + 1) -
              lf[a[i]].begin();
      if (p1 < lf[a[i]].size() && lf[a[i]][p1] == cc[a[i]]) {
        if (p2 - 1 >= p1) p2--;
        res = (res + cr * max(p2, 1ll)) % MOD;
      }
    }
    cr = cr * rr % MOD;
  }
  cout << ans << ' ' << res;
}
