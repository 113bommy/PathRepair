#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
using ll = long long;
using ld = long double;
using db = double;
using pii = pair<ll, ll>;
using pli = pair<ll, ll>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;
using vi = vector<ll>;
using vl = vector<ll>;
using vb = vector<bool>;
using vd = vector<db>;
using vs = vector<string>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using vpd = vector<pdd>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll x) { return (unsigned long long)rng() % x; }
const ll mod = 1000000007;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
template <class t, class u>
void chmax(t& a, u b) {
  if (a < b) a = b;
}
template <class t, class u>
void chmin(t& a, u b) {
  if (b < a) a = b;
}
struct Matrix {
  array<array<ll, 3>, 3> d{};
  Matrix operator*(const Matrix& m) const {
    Matrix a;
    for (ll i = 0; i < 3; i++)
      for (ll j = 0; j < 3; j++)
        for (ll k = 0; k < 3; k++) a.d[i][j] += d[i][k] * m.d[k][j] % mod;
    return a;
  }
  Matrix operator^(ll p) const {
    assert(p >= 0);
    Matrix a, b(*this);
    for (ll i = 0; i < 3; i++) a.d[i][i] = 1;
    while (p) {
      if (p & 1) a = a * b;
      b = b * b;
      p >>= 1;
    }
    return a;
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  vector<pair<ll, pii>> event;
  for (ll i = 0; i < n; i++) {
    ll a, l, r;
    cin >> a >> l >> r;
    a--, r++;
    event.push_back(make_pair(l, make_pair(a, 0LL)));
    event.push_back(make_pair(r, make_pair(a, 1LL)));
  }
  sort((event).begin(), (event).end());
  ll cur = 2;
  vi ob(3);
  Matrix curmat;
  for (ll i = 0; i < 3; i++) curmat.d[i][i] = 1;
  while (cur <= m) {
    while (!event.empty() && event.begin()->first == cur) {
      if (event.begin()->second.second == 0)
        ob[event.begin()->second.first]++;
      else
        ob[event.begin()->second.first]--;
      event.erase(event.begin());
    }
    ll nxt = m + 1;
    if (!event.empty()) nxt = event.begin()->first;
    42;
    Matrix tmp;
    for (ll i = 0; i < 2; i++)
      if (ob[0] == 0) tmp.d[i][0] = 1;
    for (ll i = 0; i < 3; i++)
      if (ob[1] == 0) tmp.d[i][1] = 1;
    for (ll i = 1; i < 3; i++)
      if (ob[2] == 0) tmp.d[i][2] = 1;
    curmat = curmat * (tmp ^ (nxt - cur));
    cur = nxt;
  }
  cout << curmat.d[1][1] % mod << '\n';
}
