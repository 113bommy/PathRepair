#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T, class U>
T fstTrue(T lo, T hi, U first) {
  hi++;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo) / 2;
    first(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
template <class T, class U>
T lstTrue(T lo, T hi, U first) {
  lo--;
  assert(lo <= hi);
  while (lo < hi) {
    T mid = lo + (hi - lo + 1) / 2;
    first(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
template <class T>
void remDup(vector<T>& v) {
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
}
template <class T, class U>
void erase(T& t, const U& u) {
  auto it = t.find(u);
  assert(it != end(t));
  t.erase(u);
}
template <class T>
void re(complex<T>& c);
template <class T, class U>
void re(pair<T, U>& p);
template <class T>
void re(vector<T>& v);
template <class T, size_t SZ>
void re(AR<T, SZ>& a);
template <class T>
void re(T& x) {
  cin >> x;
}
void re(db& d) {
  str t;
  re(t);
  d = stod(t);
}
void re(ld& d) {
  str t;
  re(t);
  d = stold(t);
}
template <class T, class... U>
void re(T& t, U&... u) {
  re(t);
  re(u...);
}
template <class T>
void re(complex<T>& c) {
  T a, b;
  re(a, b);
  c = {a, b};
}
template <class T, class U>
void re(pair<T, U>& p) {
  re(p.first, p.second);
}
template <class T>
void re(vector<T>& x) {
  for (auto& a : x) re(a);
}
template <class T, size_t SZ>
void re(AR<T, SZ>& x) {
  for (auto& a : x) re(a);
}
str to_string(char c) { return str(1, c); }
str to_string(const char* second) { return (str)second; }
str to_string(str second) { return second; }
str to_string(bool b) { return to_string((int)b); }
template <class T>
str to_string(complex<T> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
str to_string(vector<bool> v) {
  str res = "{";
  for (int i = (0); i < ((int)(v).size()); ++i) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t SZ>
str to_string(bitset<SZ> b) {
  str res = "";
  for (int i = (0); i < (SZ); ++i) res += char('0' + b[i]);
  return res;
}
template <class T, class U>
str to_string(pair<T, U> p);
template <class T>
str to_string(T v) {
  bool fst = 1;
  str res = "";
  for (const auto& x : v) {
    if (!fst) res += " ";
    fst = 0;
    res += to_string(x);
  }
  return res;
}
template <class T, class U>
str to_string(pair<T, U> p) {
  return to_string(p.first) + " " + to_string(p.second);
}
template <class T>
void pr(T x) {
  cout << to_string(x);
}
template <class T, class... U>
void pr(const T& t, const U&... u) {
  pr(t);
  pr(u...);
}
void ps() { pr("\n"); }
template <class T, class... U>
void ps(const T& t, const U&... u) {
  pr(t);
  if (sizeof...(u)) pr(" ");
  ps(u...);
}
void DBG() { cerr << "]" << endl; }
template <class T, class... U>
void DBG(const T& t, const U&... u) {
  cerr << to_string(t);
  if (sizeof...(u)) cerr << ", ";
  DBG(u...);
}
void setIn(str second) { freopen(second.c_str(), "r", stdin); }
void setOut(str second) { freopen(second.c_str(), "w", stdout); }
void unsyncIO() { cin.tie(0)->sync_with_stdio(0); }
void setIO(str second = "") {
  unsyncIO();
  if ((int)(second).size()) {
    setIn(second + ".in"), setOut(second + ".out");
  }
}
int n, k, cur[MX], sing[MX], wei[MX];
vpi adj[MX];
vpi ed;
int main() {
  setIO();
  re(n, k);
  for (int i = (0); i < (k); ++i) {
    int a, b;
    re(a, b);
    ed.push_back({a, b});
    if (a > b) swap(a, b);
    adj[b].push_back({a, i});
    cur[a]++, cur[b]++;
    wei[i] = 1;
  }
  for (int i = (1); i < (n + 1); ++i) {
    set<int> bad;
    for (auto& t : adj[i]) {
      bad.insert(cur[t.first]);
      if (!sing[t.first]) {
        sing[t.first]++;
        wei[t.second]--;
        cur[i]--;
      }
    }
    for (auto& t : adj[i]) {
      if (!bad.count(cur[i])) break;
      sing[t.first]--;
      wei[t.second]++;
      cur[i]++;
    }
  }
  vi res;
  for (int i = (1); i < (n + 1); ++i)
    if (sing[i]) res.push_back(i);
  ps((int)(res).size());
  for (auto& t : res) pr(t, ' ');
  ps();
  for (int i = (0); i < (k); ++i) ps(ed[i].first, ed[i].second, wei[i]);
}
