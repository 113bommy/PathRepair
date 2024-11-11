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
using pi = pair<int, int>;
using vi = vc<int>;
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
template <int i, class T>
void print_tuple(ostream&, const T&) {}
template <int i, class T, class H, class... Args>
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
void print(t x, int suc = 1) {
  cout << x;
  if (suc == 1) cout << "\n";
  if (suc == 2) cout << " ";
}
ll read() {
  ll i;
  cin >> i;
  return i;
}
vi readvi(int n, int off = 0) {
  vi v(n);
  for (int i = int(0); i < int(n); i++) v[i] = read() + off;
  return v;
}
template <class T>
void print(const vector<T>& v, int suc = 1) {
  for (int i = int(0); i < int(v.size()); i++)
    print(v[i], i == int(v.size()) - 1 ? suc : 2);
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
constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }
const ll infLL = LLONG_MAX / 3;
const int inf = INT_MAX / 2 - 100;
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int botbit(signed first) { return first == 0 ? 32 : __builtin_ctz(first); }
int botbit(ll first) { return first == 0 ? 64 : __builtin_ctzll(first); }
int popcount(signed t) { return __builtin_popcount(t); }
int popcount(ll t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }
ll mask(int i) { return (ll(1) << i) - 1; }
bool inc(int first, int second, int c) {
  return first <= second && second <= c;
}
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
  for (int i = int(0); i < int(int(first.size())); i++)
    swap(first[i], first[rand_int(0, i)]);
}
template <class t>
int lwb(const vc<t>& v, const t& first) {
  return lower_bound(v.begin(), v.end(), first) - v.begin();
}
const int B = 16;
const int nmax = 1 << 12;
int first[nmax], cnt;
vc<pi> ans;
int mg(int x, int y) {
  if (x == -1) return y;
  if (y == -1) return x;
  ans.emplace_back(x, y);
  return cnt++;
}
struct ysp {
  vi idx;
  vvc<int> buf;
  ysp(vi ii) : idx(ii) {
    int n = int(idx.size());
    buf.resize(n + 1, vi(n + 1, -1));
    if (int(idx.size()) == 1) {
      buf[0][1] = idx[0];
    } else {
      vi vals;
      for (auto i : idx) vals.push_back(first[i]);
      sort(vals.begin(), vals.end());
      int t = vals[n / 2];
      vi lw, up;
      for (auto i : idx)
        if (first[i] < t)
          lw.push_back(i);
        else
          up.push_back(i);
      ysp x(lw), y = (up);
      for (int i = int(0); i < int(n); i++)
        for (int j = int(i); j < int(n); j++) {
          int l = idx[i], r = idx[j] + 1;
          buf[i][j + 1] = mg(x.query(l, r), y.query(l, r));
        }
    }
  }
  int query(int l, int r) const {
    l = lwb(idx, l);
    r = lwb(idx, r);
    return buf[l][r];
  }
};
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int n;
  cin >> n;
  int q;
  cin >> q;
  cnt = n;
  for (int i = int(0); i < int(n); i++) first[i] = read() - 1;
  vc<ysp> kh;
  for (int lw = 0; lw < n; lw += B) {
    vi idx;
    for (int i = int(0); i < int(n); i++)
      if (inc(lw, first[i], lw + B - 1)) idx.push_back(i);
    kh.push_back(ysp(idx));
  }
  vi tar;
  for (int _ = int(0); _ < int(q); _++) {
    int l, r;
    cin >> l >> r;
    l--;
    int x = -1;
    for (const auto& p : kh) {
      x = mg(x, p.query(l, r));
    }
    tar.push_back(x);
  }
  print(cnt);
  for (auto p : ans) {
    print(p.first + 1, 2);
    print(p.second + 1);
  }
  for (auto& v : tar) v++;
  print(tar);
}
