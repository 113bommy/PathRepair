#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 1e6 + 10;
const ll inf = 0x3f3f3f3f;
ll a[maxn], b[maxn], p[maxn];
ll pre[maxn], suf[maxn];
ll n, m;
map<ll, ll> dic;
ll bits[2 * maxn];
ll lowbit(ll x) { return x & (-x); }
void update(ll x, ll pos) {
  while (pos < maxn) {
    bits[pos] += x;
    pos += lowbit(pos);
  }
}
ll query(ll pos) {
  ll res = 0;
  while (pos) {
    res += bits[pos];
    pos -= lowbit(pos);
  }
  return res;
}
void insert(ll il, ll ir, ll l, ll r) {
  if (il > ir || l > r) return;
  ll mid = l + r >> 1;
  pre[il] = suf[ir] = 0;
  for (ll i = il; i < ir; ++i) pre[i + 1] = pre[i] + (a[i] > b[mid]);
  for (ll i = ir - 1; i >= il; --i) suf[i] = suf[i + 1] + (a[i] < b[mid]);
  ll ans = inf;
  for (ll i = il; i <= ir; ++i) {
    if (pre[i] + suf[i] < ans) {
      ans = pre[i] + suf[i];
      p[mid] = i;
    }
  }
  insert(il, p[mid], l, mid - 1);
  insert(p[mid], ir, mid + 1, r);
}
void solve() {
  dic.clear();
  cin >> n >> m;
  for (ll i = 1; i <= n; ++i) cin >> a[i];
  for (ll i = 1; i <= m; ++i) cin >> b[i];
  for (ll i = 1; i <= m + n + 2; ++i) bits[i] = 0;
  sort(b + 1, b + m + 1);
  insert(1, n + 1, 1, m);
  vector<ll> discrete;
  for (ll i = 1; i <= n; ++i) {
    discrete.emplace_back(a[i]);
  }
  for (ll i = 1; i <= m; ++i) {
    discrete.emplace_back(b[i]);
  }
  sort(discrete.begin(), discrete.end());
  discrete.erase(unique(discrete.begin(), discrete.end()), discrete.end());
  for (ll i = 0; i < discrete.size(); ++i) {
    dic[discrete[i]] = i + 1;
  }
  vector<ll> c;
  ll j = 1;
  for (ll i = 1; i <= n; ++i) {
    while (j <= m && p[j] == i) c.push_back(b[j]), ++j;
    c.push_back(a[i]);
  }
  while (j <= m) c.push_back(b[j]), ++j;
  ll ans = 0;
  for (ll i = 0; i < c.size(); ++i) {
    ll rk = dic[c[i]];
    ans += i - query(rk);
    update(1, rk);
  }
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
