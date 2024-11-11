#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const ll N = 100005, MOD = 1e9 + 7;
const long double PI = acos(-1.0);
ll n, A, cf, cm, a[N], ans[N];
vector<pair<ll, ll> > q, v;
ll pr[N], m;
bool check(ll mnv, ll x, ll i) {
  ll j = lower_bound(a, a + n, mnv) - a;
  j = min(j, i);
  if (j == 0) {
    return 1;
  }
  return mnv * j - pr[j - 1] <= x;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> A >> cf >> cm >> m;
  ll qt = 0;
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
    q.push_back({a[i], i});
    qt += A - a[i];
  }
  if (m >= qt) {
    cout << (ll)A * cm + (ll)n * cf << '\n';
    for (ll i = 0; i < n; ++i) {
      cout << A << ' ';
    }
    cout << '\n';
    return 0;
  }
  sort(q.begin(), q.end());
  for (ll i = 0; i < n; ++i) {
    a[i] = q[i].first;
  }
  for (ll i = 0; i < n; ++i) {
    pr[i] = (i == 0 ? 0 : pr[i - 1]) + a[i];
  }
  ll ans = -1, rs = -1, mnv = -1;
  for (ll i = n; i >= 0; --i) {
    ll q = (n - i) * A - pr[n - 1] + (i == 0 ? 0 : pr[i - 1]);
    if (q > m) {
      break;
    }
    ll rt = m - q;
    ll l = -1, r = A + 1, mid;
    while (r - l > 1) {
      mid = (l + r) >> 1;
      if (check(mid, rt, i)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    ll vl = l * cm + (ll)(n - i) * cf;
    if (vl > ans) {
      ans = vl;
      rs = i, mnv = l;
    }
  }
  for (ll i = 0; i < n; ++i) {
    a[i] = max(a[i], (ll)mnv);
    if (i >= rs) a[i] = A;
    ::ans[q[i].second] = a[i];
  }
  ll mn = (ll)2e18, cnt = 0;
  for (ll i = 0; i < n; ++i) {
    mn = min(mn, (ll)::ans[i]);
    if (::a[i] == A) ++cnt;
  }
  cout << ans << '\n';
  for (ll i = 0; i < n; ++i) {
    cout << ::ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
