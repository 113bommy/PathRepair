#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using cd = complex<ld>;
using vcd = vector<cd>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
template <class T>
using min_pq = priority_queue<T, vector<T>, greater<T> >;
template <class T>
inline int ckmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int ckmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
template <class T>
void remDup(vector<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), end(v));
}
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
ll ceilDiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll floorDiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
void setPrec(int x) { cout << fixed << setprecision(x); }
string to_string(char c) { return string(1, c); }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(bool b) { return to_string((int)b); }
template <class T>
string to_string(complex<T> c) {
  stringstream ss;
  ss << c;
  return ss.str();
}
template <class T>
using V = vector<T>;
string to_string(V<bool> v) {
  string res = "{";
  for (int i = (0); i <= (int((v).size()) - 1); i++) res += char('0' + v[i]);
  res += "}";
  return res;
}
template <size_t sz>
string to_string(bitset<sz> b) {
  string res = "";
  for (int i = (0); i <= (int((b).size()) - 1); i++) res += char('0' + b[i]);
  return res;
}
template <class T, class U>
string to_string(pair<T, U> p);
template <class T>
string to_string(T v) {
  bool fst = 1;
  string res = "";
  for (const auto& x : v) {
    if (!fst) res += " ";
    fst = 0;
    res += to_string(x);
  }
  return res;
}
template <class T, class U>
string to_string(pair<T, U> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
const ld PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ld EPS = 1e-9;
const ll MODBASE = 1000000007LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 110;
const int MAXM = 1000;
const int MAXK = 16;
const int MAXQ = 200010;
int f[30], n;
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int te;
  cin >> te;
  while (te--) {
    cin >> n;
    memset(f, 0, sizeof(f));
    for (int i = (1); i <= (n); i++) {
      int x;
      cin >> x;
      for (int j = (29); j >= (0); j--)
        if (x & (1 << j)) f[j]++;
    }
    int g = 0;
    for (int i = (0); i <= (29); i++) g = gcd(g, f[i]);
    if (g == 0) {
      for (int i = (1); i <= (n); i++) cout << i << " ";
      cout << "\n";
    } else {
      for (int i = (1); i <= (g); i++)
        if (g % i == 0) cout << i << ' ';
      cout << "\n";
    }
  }
  return 0;
}
