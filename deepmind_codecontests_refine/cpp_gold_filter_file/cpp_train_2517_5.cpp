#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class t, class u>
void chmax(t& first, u second) {
  if (first < second) first = second;
}
template <class t, class u>
void chmin(t& first, u second) {
  if (second < first) first = second;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using pi = pair<ll, ll>;
using vi = vc<ll>;
template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
  return os << "{" << p.first << "," << p.second << "}";
}
template <class t>
ostream& operator<<(ostream& os, const vc<t>& v) {
  os << "{";
  for (auto e : v) os << e << ",";
  return os << "}";
}
using uint = unsigned;
using ull = unsigned long long;
template <ll i, class T>
void print_tuple(ostream&, const T&) {}
template <ll i, class T, class H, class... Args>
void print_tuple(ostream& os, const T& t) {
  if (i) os << ",";
  os << get<i>(t);
  print_tuple<i + 1, T, Args...>(os, t);
}
template <class... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  os << "{";
  print_tuple<0, tuple<Args...>, Args...>(os, t);
  return os << "}";
}
void print(ll x, ll suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(ll n, ll off = 0) {
  vi v(n);
  for (ll i = ll(0); i < ll(n); i++) v[i] = read() + off;
  return v;
}
template <class T>
void print(const vector<T>& v, ll suc = 1) {
  for (ll i = ll(0); i < ll(v.size()); i++)
    print(v[i], i == ll(v.size()) - 1 ? suc : 2);
}
string readString() {
  string s;
  cin >> s;
  return s;
}
template <class T>
T sq(const T& t) {
  return t * t;
}
void yes(bool ex = true) {
  cout << "Yes" << endl;
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No" << endl;
  if (ex) exit(0);
}
constexpr ll ten(ll n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
ll topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
ll topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
ll popcount(signed t) { return __builtin_popcount(t); }
ll popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(ll i) { return i && (i & -i) == i; }
ll mask(ll i) { return (ll(1) << i) - 1; }
bool inc(ll first, ll second, ll c) { return first <= second && second <= c; }
template <class t>
void mkuni(vc<t>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
ll rand_int(ll l, ll r) {
  static random_device rd;
  static mt19937_64 gen(rd());
  return uniform_int_distribution<ll>(l, r)(gen);
}
vc<pi> morita(vi len, vi d) {
  ll n = len.size();
  vi pos{0};
  for (auto& v : d) {
    chmax(v, 0);
    pos.push_back(v);
  }
  mkuni(pos);
  ll s = pos.size();
  vi sum(s);
  for (ll i = ll(0); i < ll(n); i++) {
    sum[0] += -len[i];
    sum[lower_bound(pos.begin(), pos.end(), d[i]) - pos.begin()] += len[i] * 2;
  }
  for (ll i = ll(0); i < ll(s - 1); i++) sum[i + 1] += sum[i];
  vc<pi> res;
  for (ll i = ll(0); i < ll(s - 1); i++)
    res.emplace_back(sum[i], pos[i + 1] - pos[i]);
  return res;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  ll m, n;
  cin >> m >> n;
  vi first = readvi(n), second = readvi(n);
  vi c;
  for (auto v : first) c.push_back(v);
  for (auto v : second) c.push_back(v);
  mkuni(c);
  ll s = c.size();
  vi len(s - 1), d(s - 1);
  for (ll i = ll(0); i < ll(s - 1); i++) len[i] = c[i + 1] - c[i];
  ll base = 0;
  {
    vi buf(s);
    for (auto v : first) buf[lower_bound(c.begin(), c.end(), v) - c.begin()]--;
    for (auto v : second) buf[lower_bound(c.begin(), c.end(), v) - c.begin()]++;
    ll cur = 0;
    for (ll i = ll(0); i < ll(s - 1); i++) {
      cur += buf[i];
      d[i] = cur;
      base += len[i] * abs(cur);
    }
  }
  ll sgm = m - (c.back() - c.front());
  pi ans(0, 0);
  for (ll _ = ll(0); _ < ll(2); _++) {
    vc<pi> x = morita(len, d);
    ll res = 0, am = 0;
    for (auto ab : x) {
      ll slp = ab.first + sgm;
      if (slp >= 0) continue;
      res += slp * ab.second;
      am += ab.second;
    }
    if (_) am = -am;
    chmin(ans, pi(res, am));
    reverse(len.begin(), len.end());
    reverse(d.begin(), d.end());
    for (auto& v : d) v = -v;
  }
  cout << base + ans.first << endl;
  ll f = ans.second;
  vvc<ll> x(s), y(s);
  vi in, out;
  for (ll i = ll(0); i < ll(n); i++)
    y[lower_bound(c.begin(), c.end(), first[i]) - c.begin()].push_back(i);
  for (ll i = ll(0); i < ll(n); i++)
    x[lower_bound(c.begin(), c.end(), second[i]) - c.begin()].push_back(i);
  ll nn = n + abs(f);
  vi p(nn, -1), q(nn, -1);
  for (ll i = ll(0); i < ll(f); i++) y[0].push_back(n + i);
  for (ll i = ll(0); i < ll(f); i++) x[s - 1].push_back(n + i);
  for (ll i = ll(0); i < ll(-f); i++) x[0].push_back(n + i);
  for (ll i = ll(0); i < ll(-f); i++) y[s - 1].push_back(n + i);
  for (ll i = ll(0); i < ll(s); i++) {
    for (auto j : x[i]) in.push_back(j);
    for (auto j : y[i]) out.push_back(j);
    while (in.size() && out.size()) {
      ll g = in.back();
      in.pop_back();
      ll h = out.back();
      out.pop_back();
      p[g] = h;
      q[h] = g;
    }
  }
  for (ll i = ll(0); i < ll(n); i++) {
    ll j = q[i];
    if (j >= n) j = q[j];
    assert(j < n);
    print(j + 1, i == n - 1 ? 1 : 2);
  }
}
