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
template <class t, size_t n>
ostream& operator<<(ostream& os, const array<t, n>& first) {
  return os << vc<t>(first.begin(), first.end());
}
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
template <class t>
void print(t x, ll suc = 1) {
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
  cout << "Yes"
       << "\n";
  if (ex) exit(0);
}
void no(bool ex = true) {
  cout << "No"
       << "\n";
  if (ex) exit(0);
}
void possible(bool ex = true) {
  cout << "Possible"
       << "\n";
  if (ex) exit(0);
}
void impossible(bool ex = true) {
  cout << "Impossible"
       << "\n";
  if (ex) exit(0);
}
constexpr ll ten(ll n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const ll inf = infLL;
ll topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
ll topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
ll botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
ll botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
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
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<ll>(l, r)(gen);
}
template <class t>
void myshuffle(vc<t>& first) {
  for (ll i = ll(0); i < ll(ll(first.size())); i++)
    swap(first[i], first[rand_int(0, i)]);
}
template <class t>
ll lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
vi get18() {
  ll x;
  cin >> x;
  vi first;
  for (ll i = ll(0); i < ll(18); i++) {
    first.push_back(x % 10);
    x /= 10;
  }
  return first;
}
ll dp[19][10][2][2][3][2];
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  vi lw = get18();
  vi up = get18();
  while (ll(lw.size()) && lw.back() == up.back()) {
    lw.pop_back();
    up.pop_back();
  }
  reverse(lw.begin(), lw.end());
  reverse(up.begin(), up.end());
  if (ll(lw.size()) == 0) {
    print(1);
    return 0;
  }
  ll ans = 0;
  ll len = ll(lw.size());
  void(0);
  void(0);
  {
    using A = array<ll, 2>;
    vc<A> eq(10);
    eq[0][0] = 1;
    for (ll _ = ll(0); _ < ll(len); _++) {
      for (ll i = ll(0); i < ll(9); i++)
        for (ll j = ll(0); j < ll(2); j++) eq[i + 1][j] += eq[i][j];
      for (ll i = ll(lw[0] + 1); i < ll(up[0]); i++) {
        eq[i][1] += eq[i][0];
        eq[i][0] = 0;
      }
    }
    for (ll i = ll(0); i < ll(10); i++) ans += eq[i][1];
  }
  void(0);
  dp[0][0][0][0][1][1] = 1;
  for (ll i = ll(0); i < ll(len); i++) {
    for (ll last = ll(0); last < ll(10); last++)
      for (ll ru = ll(0); ru < ll(2); ru++)
        for (ll lu = ll(0); lu < ll(2); lu++)
          for (ll rcmp = ll(0); rcmp < ll(3); rcmp++)
            for (ll lcmp = ll(0); lcmp < ll(2); lcmp++) {
              ll w = dp[i][last][ru][lu][rcmp][lcmp];
              if (w) {
                for (ll nx = ll(last); nx < ll(10); nx++) {
                  if (inc(lw[0] + 1, nx, up[0] - 1)) continue;
                  ll nxru = ru || nx == up[0];
                  ll nxlu = lu || nx == lw[0];
                  ll nxrcmp = rcmp;
                  if (ru == nxru) {
                    if (rcmp == 1) {
                      if (1 + i - ru < len) {
                        if (nx > up[1 + i - ru])
                          nxrcmp = 2;
                        else if (nx < up[i + 1 - ru])
                          nxrcmp = 0;
                      }
                    }
                  }
                  ll nxlcmp = lcmp;
                  if (lu == nxlu) {
                    if (len - 1 - (i - lu) >= 0) {
                      if (nx > lw[len - 1 - (i - lu)])
                        nxlcmp = 1;
                      else if (nx < lw[len - 1 - (i - lu)])
                        nxlcmp = 0;
                    }
                  }
                  dp[i + 1][nx][nxru][nxlu][nxrcmp][nxlcmp] += w;
                }
              }
            }
  }
  for (ll last = ll(0); last < ll(10); last++) {
    for (ll rcmp = ll(0); rcmp < ll(3); rcmp++)
      ans += dp[len][last][0][1][rcmp][1];
    void(0);
    for (ll lcmp = ll(0); lcmp < ll(2); lcmp++) {
      ans += dp[len][last][1][0][0][lcmp];
      ans += dp[len][last][1][0][1][lcmp];
    }
    ans += dp[len][last][1][1][0][0];
    ans += dp[len][last][1][1][0][1];
    ans += dp[len][last][1][1][1][0];
    ans += dp[len][last][1][1][1][1];
    ans += dp[len][last][1][1][2][1];
    void(0);
  }
  print(ans);
}
