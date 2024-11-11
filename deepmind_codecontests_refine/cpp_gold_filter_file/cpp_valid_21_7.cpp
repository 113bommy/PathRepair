#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T, size_t N>
inline ostream &operator<<(ostream &os, const array<T, N> &a) {
  os << "[";
  int cnt = 0;
  for (auto &val : a) {
    if (cnt++) os << ", ";
    os << val;
  }
  os << "]";
  return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "]";
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T>
inline ostream &operator<<(ostream &os, const unordered_set<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T>
inline ostream &operator<<(ostream &os, const multiset<T> &v) {
  os << "{";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "}";
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  os << "[";
  int cnt = 0;
  for (auto &val : v) {
    if (cnt++) os << ", ";
    os << val;
  }
  return os << "]";
}
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vb = vector<bool>;
using vd = vector<double>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vc = vector<char>;
using si = set<int>;
using mpii = map<int, int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
template <int MOD_>
struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

 private:
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - long long(minv(m, a)) * long long(m) / a);
  }

 public:
  modnum() : v(0){};
  modnum(long long v_) : v(int(v_ % MOD)) {
    if (v < 0) v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream &operator<<(std::ostream &out, const modnum &n) {
    return out << int(n);
  }
  friend std::istream &operator>>(std::istream &in, modnum &n) {
    long long v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum &a, const modnum &b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum &a, const modnum &b) {
    return a.v != b.v;
  }
  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum &m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum &m) { return m.neg(); }
  modnum pow(int m) {
    assert(m >= 0);
    modnum res = 1, p = modnum(*this);
    while (m) {
      if (m & 1) res *= p;
      p *= p;
      m /= 2;
    }
    return res;
  }
  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }
  modnum &operator++() {
    ++v;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum &operator--() {
    if (v == 0) v = MOD;
    --v;
    return *this;
  }
  modnum &operator+=(const modnum &o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum &operator-=(const modnum &o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum &operator*=(const modnum &o) {
    v = int(long long(v) * long long(o.v) % MOD);
    return *this;
  }
  modnum &operator/=(const modnum &o) { return *this *= o.inv(); }
  friend modnum operator++(modnum &a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum &a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum &a, const modnum &b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum &a, const modnum &b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum &a, const modnum &b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum &a, const modnum &b) {
    return modnum(a) /= b;
  }
};
using mint = modnum<998244353>;
int n;
int solve() {
  int m = n * 2;
  vi p;
  map<int, int> back;
  set<int> active;
  for (int i = 0; i < (n); i++) {
    int x, y, z;
    cin >> x >> y >> z;
    p.emplace_back(x);
    p.emplace_back(y);
    back[x] = y;
    if (z) active.emplace(x);
  }
  sort((p).begin(), (p).end());
  mint ans = p[0];
  ans += 1;
  map<int, mint> out, in;
  out[p[m - 1]] = 1;
  for (int i = m - 1; i >= 0; i--) {
    mint inCnt = 0;
    if (back.count(p[i])) {
      mint x = out[p[i]], backTimes = 0;
      if (active.count(p[i])) {
        backTimes++;
        inCnt++;
      }
      inCnt += x * 2 - 1;
      backTimes += x - 1;
      in[back[p[i]]] += backTimes;
    } else {
      inCnt = out[p[i]];
    }
    inCnt -= in[p[i]];
    if (i) {
      mint d = p[i] - p[i - 1];
      ans += d * inCnt;
      out[p[i - 1]] += inCnt;
    }
    in[p[i]] += inCnt;
  }
  return int(ans);
}
void solve(int _cas) { cout << solve() << endl; }
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL), cout.precision(12);
  while (cin >> n) solve(1);
}
