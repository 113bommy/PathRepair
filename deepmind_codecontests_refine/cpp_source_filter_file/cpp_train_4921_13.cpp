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
template <class T>
using PR = pair<T, T>;
const int MOD = 1e9 + 7;
const int mxN = 1e6 + 5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int tSZ = (1 << 21);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return 31 - __builtin_clz(x); }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
ll add(ll first, ll second) {
  first += second;
  if (first >= MOD) first %= MOD;
  if (first < 0) first += MOD;
  return first;
}
ll mul(ll first, ll second) {
  first *= second;
  if (first >= MOD) first %= MOD;
  return first;
}
ll pw(ll x, ll y) {
  ll ans = 1, ml = x;
  while (y) {
    if (y & 1) ans = mul(ans, ml);
    ml = mul(ml, ml);
    y >>= 1;
  }
  return ans;
}
ll inv(ll x) { return pw(x, MOD - 2); }
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
template <class T>
void rv(int& n, vector<T>& x) {
  re(n);
  x.resize(n);
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
int n;
str st;
int bst[mxN];
vector<int> pss[2][mxN];
void solve() {
  int h[2] = {0, 0};
  int r = n;
  int last_char = n;
  for (int i = n - 1; i >= 0; i--) {
    int tmp = -1;
    if (st[i] != '?') {
      tmp = st[i] - '0';
    }
    if (tmp != -1 && h[tmp ^ 1] == 1) {
      h[tmp ^ 1] = 0;
      r = last_char;
    }
    if (tmp != -1) {
      last_char = i;
      h[tmp] = 1;
    }
    bst[i] = r - i;
  }
  for (int i = 0; i < 2; i++) {
    int l = 0, r = 0;
    while (l < n) {
      if (st[l] == char((i ^ 1) + '0')) {
        l++;
        continue;
      }
      r = l + 1;
      while (r < n && st[r] != char((i ^ 1) + '0')) r++;
      for (int j = 1; j <= r - l; j++) {
        pss[i][j].push_back(l);
      }
      l = r;
    }
  }
  for (int i = (1); i < (n + 1); ++i) {
    int pos = 0;
    int ans = 0;
    int t[2] = {0, 0};
    while (pos < n) {
      int tmp = pos;
      if (bst[pos] >= i) {
        ans++;
        pos += i;
      } else {
        int mn = n;
        for (int g = 0; g < 2; g++) {
          while (t[g] < (int)(pss[g][i]).size() && pss[g][i][t[g]] < pos)
            t[g]++;
          if (t[g] < (int)(pss[g][i]).size()) {
            mn = min(mn, pss[g][i][t[g]] + i);
          }
        }
        if (mn != n) ans++;
        pos = mn;
      }
      if (pos == tmp) break;
    }
    ps(ans);
  }
}
int main() {
  setIO();
  re(n, st);
  solve();
  return 0;
}
