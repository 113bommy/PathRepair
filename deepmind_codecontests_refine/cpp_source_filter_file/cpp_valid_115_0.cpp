#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int first = 0;
  cerr << '{';
  for (auto& i : x) cerr << (first++ ? ", " : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int MOD = 998244353;
const char nl = '\n';
const int MX = 1000001;
struct mi {
  long long v;
  explicit operator long long() const { return v; }
  mi() { v = 0; }
  mi(long long _v) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
  mi& operator+=(const mi& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mi& operator-=(const mi& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mi& operator*=(const mi& m) {
    v = v * m.v % MOD;
    return *this;
  }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi pow(mi a, long long p) {
    mi ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  mi operator-() const { return mi(-v); }
  mi& operator++() { return *this += 1; }
  mi& operator--() { return *this -= 1; }
  mi operator++(int) {
    mi temp;
    temp.v = v++;
    return temp;
  }
  mi operator--(int) {
    mi temp;
    temp.v = v--;
    return temp;
  }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
  friend ostream& operator<<(ostream& os, const mi& m) {
    os << m.v;
    return os;
  }
  friend istream& operator>>(istream& is, mi& m) {
    long long x;
    is >> x;
    m.v = x;
    return is;
  }
};
void __print(mi X) { cout << X.v; }
set<int> rused, cused;
set<int> rbad, cbad;
int r[2][MX], c[2][MX];
int same, diff;
void uncolor(int x, int y, int co) {
  if ((x + y) % 2 == co) {
    same--;
  } else
    diff--;
  r[(co + y) % 2][x]--;
  if (r[(co + y) % 2][x] == 0) {
    rbad.erase(x);
    if (r[1 - (co + y) % 2][x] == 0) {
      rused.erase(x);
    }
  }
  c[(co + x) % 2][y]--;
  if (c[(co + x) % 2][y] == 0) {
    cbad.erase(y);
    if (c[1 - (co + x) % 2][y] == 0) {
      cused.erase(y);
    }
  }
}
void color(int x, int y, int co) {
  if ((x + y) % 2 == co) {
    same++;
  } else
    diff++;
  r[(co + y) % 2][x]++;
  rused.insert(x);
  if (r[1 - (co + y) % 2][x]) rbad.insert(x);
  c[(co + x) % 2][y]++;
  cused.insert(y);
  if (c[1 - (co + x) % 2][y]) cbad.insert(y);
}
void solve() {
  int N, M, K;
  cin >> N >> M >> K;
  map<pair<int, int>, int> col;
  while (K--) {
    int X, Y;
    cin >> X >> Y;
    X--;
    Y--;
    int T;
    cin >> T;
    pair<int, int> C = make_pair(X, Y);
    if (col.count(C)) {
      uncolor(X, Y, col[C]);
      col.erase(C);
    }
    if (T == 0) {
      color(X, Y, 0);
      col[C] = 0;
    }
    if (T == 1) {
      color(X, Y, 1);
      col[C] = 1;
    }
    mi ans;
    if ((int)(rbad).size() == 0) ans += pow(mi(2), N - (int)(rused).size());
    if ((int)(cbad).size() == 0) ans += pow(mi(2), M - (int)(cused).size());
    if (same == 0) ans--;
    if (diff == 0) ans--;
    cout << ans << nl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
