#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline long long rand(long long x, long long y) {
  return rng() % (y + 1 - x) + x;
}
string inline to_string(char c) {
  string second(1, c);
  return second;
}
template <typename T>
inline T gcd(T a, T b) {
  return a == 0 ? llabs(b) : gcd(b % a, a);
}
using ll = int;
using ld = long double;
using pi = pair<ll, ll>;
using spi = pair<ll, pi>;
using dpi = pair<pi, pi>;
const ll sqn = 450;
const ll other = (100006) / sqn + 2;
ll n, q, A[(100006)], heavy[(100006)], head[(100006)], p[(100006)],
    st[(100006)], co, depth[(100006)], bck[(100006)], ans;
bool off[(100006)];
vector<int> v[(100006)];
struct bkt {
  ll second, e, co2[(100006) * 2], ofs = 0;
  ll* co = co2 + (100006);
  bkt() { second = e = 0, memset((co2), 0, sizeof((co2))), ofs = 0; }
  void init(ll _s, ll _e) {
    second = _s, e = _e, ofs = 0;
    memset((co2), 0, sizeof((co2)));
    for (ll i = second; i <= ll(e); ++i) {
      ++co[A[bck[i]]];
    }
  }
  void up(ll x, ll y, ll val) {
    if (x > e || y < second) return;
    if (x <= second && e <= y) {
      ofs += val;
      return;
    }
    for (ll i = max(second, x); i <= ll(min(e, y)); ++i) {
      if (!off[i]) --co[A[bck[i]]];
      A[bck[i]] += val;
      if (!off[i]) ++co[A[bck[i]]];
    }
    return;
  }
  ll query(ll x, ll y, ll val) {
    if (x > e || y < second) return 0;
    if (x <= second && e <= y) {
      return co[val - ofs];
    }
    ll ans = 0;
    for (ll i = max(second, x); i <= ll(min(e, y)); ++i)
      if (!off[i]) ans += A[bck[i]] + ofs == val;
    return ans;
  }
  void dir(ll x) {
    assert(second <= x && x <= e);
    co[A[bck[x]]] += off[x] ? 1 : -1;
    ans += (A[bck[x]] + ofs < 0) * (off[x] ? 1 : -1);
    off[x] ^= 1;
  }
} bk[other];
ll query(ll x, ll y, ll val) {
  ll ans = 0;
  for (ll i = 0; i <= ll((n - 1) / sqn); ++i) ans += bk[i].query(x, y, val);
  return ans;
}
void up(ll x, ll y, ll val) {
  for (ll i = 0; i <= ll((n - 1) / sqn); ++i) bk[i].up(x, y, val);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (ll i = 2; i <= ll(n); ++i) {
    cin >> p[i];
    v[p[i]].emplace_back(i);
  }
  p[1] = 1;
  for (ll i = 1; i <= ll(n); ++i) cin >> A[i];
  function<ll(ll)> dfs = [&](ll x) {
    ll sz = 1, mx_sz = 0;
    for (auto i : v[x]) {
      depth[i] = depth[x] + 1;
      ll c_sz = dfs(i);
      sz += c_sz;
      if (c_sz > mx_sz) mx_sz = c_sz, heavy[x] = i;
    }
    return sz;
  };
  function<void(ll, ll)> hld = [&](ll x, ll h) {
    head[x] = h, st[x] = co++, bck[st[x]] = x;
    if (heavy[x]) hld(heavy[x], h);
    for (auto i : v[x])
      if (i ^ heavy[x]) hld(i, i);
  };
  dfs(1), hld(1, 1);
  assert(co == n);
  for (ll i = 0; i <= ll((n - 1) / sqn); ++i)
    bk[i].init(i * sqn, min((i + 1) * sqn, n) - 1);
  for (ll i = 0; i <= ll(q - 1); ++i) {
    auto op = [&](ll x, ll val) {
      if (x == 1) return;
      x = p[x];
      for (;; x = p[head[x]]) {
        up(st[head[x]], st[x], val);
        if (val == 1)
          ans -= query(st[head[x]], st[x], 0);
        else if (val == -1)
          ans += query(st[head[x]], st[x], -1);
        else
          assert(0);
        if (head[x] == 1) break;
      }
    };
    ll x;
    cin >> x;
    if (x > 0) {
      bk[st[x] / sqn].dir(st[x]);
      op(x, -1);
    } else {
      x *= -1;
      bk[st[x] / sqn].dir(st[x]);
      op(x, 1);
    }
    cout << ans << ' ';
  }
}
