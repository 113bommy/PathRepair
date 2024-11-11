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
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
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
  t.erase(it);
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
int go(vector<int> x, int y) {
  if (y == 0 || (int)x.size() == 0) {
    return 0;
  }
  vector<int> l;
  vector<int> r;
  for (int i = 0; i < x.size(); i++) {
    if ((x[i] & (1 << y)) != 0) {
      l.push_back(x[i]);
    } else {
      r.push_back(x[i]);
    }
  }
  int ret = max((int)l.size() - 1, 0) + go(r, y - 1);
  ret = min(ret, max((int)r.size() - 1, 0) + go(l, y - 1));
  return ret;
}
int main() {
  setIO();
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int ans = 0;
  vector<int> cnt(n + 1);
  vector<int> freq(n + 1);
  int maxi = 0;
  freq[0] = n;
  int rig = -1;
  for (int i = 0; i < n; i++) {
    freq[cnt[a[i]]]--;
    freq[++cnt[a[i]]]++;
    maxi = max(cnt[a[i]], maxi);
    if (freq[maxi] > 1) {
      rig = i;
    }
  }
  maxi = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] > cnt[maxi]) {
      maxi = i;
    }
  }
  if (cnt[maxi] == n) {
    cout << 0 << endl;
    return 0;
  }
  int lo = rig + 1;
  int hi = n;
  vector<int> second(n);
  vector<int> l_cnt(n);
  vector<int> r_cnt(n);
  vector<int> cur(n);
  vector<int> best_prefix(n);
  priority_queue<pi> cur_set;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    while (cur_set.size() > 0) {
      cur_set.pop();
    }
    int add = 0;
    for (int i = 0; i < n; i++) {
      second[i] = 0;
      l_cnt[i] = 0;
      r_cnt[i] = 0;
      cur[i] = 0;
      best_prefix[i] = 0;
    }
    for (int i = 0; i < mid; i++) {
      r_cnt[a[i]]++;
      if (a[i] == maxi) {
        add++;
      } else {
        second[a[i]]--;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i != maxi) {
        cur[i] = l_cnt[i] - r_cnt[i];
        cur_set.push(make_pair(-cur[i], i));
      }
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
      second[i] += add;
      if (second[i] == 0) {
        ok = true;
      }
    }
    int aux = -r_cnt[maxi];
    for (int i = 0; i + mid < n; i++) {
      int r = i + mid;
      if (a[r] == maxi) {
        aux--;
        r_cnt[maxi]++;
      } else {
        r_cnt[a[r]]++;
        if (best_prefix[a[r]] >= r_cnt[maxi] - r_cnt[a[r]]) {
          ok = true;
        }
        cur[a[r]] = l_cnt[a[r]] - r_cnt[a[r]];
        cur_set.push(make_pair(-cur[a[r]], a[r]));
      }
      if (a[i] == maxi) {
        aux++;
        l_cnt[maxi]++;
      } else {
        best_prefix[a[i]] = max(best_prefix[a[i]], l_cnt[maxi] - l_cnt[a[i]]);
        l_cnt[a[i]]++;
        cur[a[i]] = l_cnt[a[i]] - r_cnt[a[i]];
        cur_set.push(make_pair(-cur[a[i]], a[i]));
      }
      while (cur_set.size() > 0) {
        auto now = cur_set.top();
        if (cur_set.top().first != -cur[cur_set.top().second]) {
          cur_set.pop();
        } else {
          break;
        }
      }
      int val = -cur_set.top().first;
      ok = (ok || (aux >= val));
    }
    while (cur_set.size() > 0) {
      auto now = cur_set.top();
      if (cur_set.top().first != -cur[cur_set.top().second]) {
        cur_set.pop();
      } else {
        break;
      }
    }
    int val = -cur_set.top().first;
    ok = (ok || (aux >= val));
    if (ok) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  cout << lo << endl;
}
