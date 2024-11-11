#include <bits/stdc++.h>
using namespace std;
struct IO {
  IO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
} io;
using ll = long long;
using db = long double;
using pi = pair<ll, ll>;
using mi = map<ll, ll>;
const ll mod = 998244353;
const ll INF = 0x3f3f3f3f;
ll qpow(ll a, ll b, ll MOD = mod) {
  for (ll ans = 1;; a = a * a % MOD, b >>= 1) {
    if (b & 1) ans = ans * a % MOD;
    if (!b) return ans;
  }
}
ll inv(ll a, ll MOD = mod) { return qpow(a, MOD - 2, MOD); }
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll ret = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return ret;
}
ll getInv(ll a, ll mod) {
  ll x, y;
  ll d = exgcd(a, mod, x, y);
  return d == 1 ? (x % mod + mod) % mod : -1;
}
using vi = vector<ll>;
const ll N = 1e6 + 5, M = 1e9 + 7;
inline ll add(ll x, ll y) { return x + y >= M ? x + y - M : x + y; }
inline ll mul(ll x, ll y) { return x * y % M; }
inline ll sub(ll x, ll y) { return x - y < 0 ? x - y + M : x - y; }
using G = vector<vi>;
ll cnt[N];
const ll mx = 20;
ll bits(ll x) { return x & -x; }
ll find_vk(ll k) {
  ll ans = 0, res = 0;
  for (ll i = 4; i >= 0; i--) {
    ans += (1 << i);
    if (ans >= mx || res + cnt[ans] >= k)
      ans -= (1 << i);
    else
      res += cnt[ans];
  }
  return ans + 1;
}
void upd(ll pos, ll x) {
  for (; pos < mx; pos += bits(pos)) {
    cnt[pos] += x;
  }
}
ll FAC[20];
vector<ll> decantor(ll n, ll k) {
  for (ll i = 1; i <= mx; i++) cnt[i] = 0;
  for (ll i = 1; i <= n; i++) upd(i, 1);
  vector<ll> a;
  for (ll i = n; i >= 1; i--) {
    ll r = k % FAC[i - 1];
    ll t = k / FAC[i - 1];
    k = r;
    ll now = find_vk(t + 1);
    a.push_back(now);
    upd(now, -1);
  }
  return a;
}
ll sum[N];
signed main() {
  ll n, q;
  cin >> n >> q;
  for (ll i = 1; i <= n; i++) sum[i] = sum[i - 1] + i;
  ll res = max(0ll, n - 15);
  FAC[0] = 1;
  for (ll i = 1; i <= 15; i++) FAC[i] = FAC[i - 1] * i;
  n = min(1ll * 15, n);
  ll now = 0;
  while (q--) {
    ll op;
    cin >> op;
    if (op == 1) {
      ll l, r;
      cin >> l >> r;
      cout << sum[r] - sum[l - 1] << endl;
    } else {
      ll x;
      cin >> x;
      now += x;
      auto a = decantor(n, x);
      for (ll i = res + 1; i <= res + n - 1; i++)
        sum[i] = sum[i - 1] + a[i - res - 1] + res;
    }
  }
}
