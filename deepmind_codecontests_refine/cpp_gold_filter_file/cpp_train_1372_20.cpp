#include <bits/stdc++.h>
using namespace std;
inline int nextint() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long nextll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
template <typename T>
void scanint(T& x) {
  T c = getchar();
  while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
  bool neg = false;
  if (c == '-') {
    neg = true;
    c = getchar();
  }
  x = 0;
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) x = (x * 10) + (c - 48);
  if (neg) x = -x;
}
template <typename T>
T min_(T a, T b) {
  return a > b ? b : a;
}
template <typename T, typename... Ts>
T min_(T first, Ts... last) {
  return min_(first, min_(last...));
}
template <typename T>
T max_(T a, T b) {
  return a > b ? a : b;
}
template <typename T, typename... Ts>
T max_(T first, Ts... last) {
  return max_(first, max_(last...));
}
template <class T, class S>
std::ostream& operator<<(std::ostream& os, const std::pair<T, S>& t) {
  os << "(" << t.first << ", " << t.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  out << "[";
  size_t last = v.size() - 1;
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i];
    if (i != last) out << ", ";
  }
  out << "]";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const set<T>& v) {
  out << "{";
  auto last = v.end();
  for (auto i = v.begin(); i != last;) {
    out << *i;
    if (++i != last) out << ", ";
  }
  out << "}";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const multiset<T>& v) {
  out << "{";
  auto last = v.end();
  for (auto i = v.begin(); i != last;) {
    out << *i;
    if (++i != last) out << ", ";
  }
  out << "}";
  return out;
}
template <typename T, typename VAL>
ostream& operator<<(ostream& out, const map<T, VAL>& v) {
  out << "{";
  auto last = v.end();
  for (auto i = v.begin(); i != last;) {
    out << *i;
    if (++i != last) out << ", ";
  }
  out << "}";
  return out;
}
template <typename T, class S>
void outv(vector<pair<S, S>>& v) {
  for (T x : v) cout << x.first << " " << x.second << endl;
}
template <typename T>
void outv(vector<T>& v) {
  for (T x : v) cout << x << " ";
  cout << endl;
}
template <typename T>
void outs(set<T>& v) {
  for (T x : v) cout << x << " ";
  cout << endl;
}
template <typename T>
void outm(map<T, int>& v, int n = 1) {
  for (T& x : v) cout << (n == 1 ? x.first : x.second) << " ";
  cout << endl;
}
template <typename Arg, typename... Args>
void ptrace(std::ostream& out, Arg&& arg, Args&&... args) {
  out << "<< ";
  out << std::forward<Arg>(arg);
  using expander = int[];
  (void)expander{0, (void(out << ", " << std::forward<Args>(args)), 0)...};
  out << " >>\n";
}
template <typename Arg, typename... Args>
void trace(Arg&& arg, Args&&... args) {}
template <typename T>
void readv(vector<T>& v, int n) {
  v = vector<T>(n);
  for (int i = 0; i < (int)(n); i++) cin >> (v[i]);
}
template <typename T>
void reads(set<T>& v, int n) {
  T x;
  for (int i = 0; i < (int)(n); i++) {
    cin >> x;
    v.insert(x);
  }
}
template <typename T>
void readm(map<T, int>& v, int n) {
  T x;
  for (int i = 0; i < (int)(n); i++) {
    cin >> x;
    v[x]++;
  }
}
template <typename Arg, typename... Args>
void read(Arg&& arg, Args&&... args) {
  cin >> std::forward<Arg>(arg);
  using expander = int[];
  (void)expander{0, (void(cin >> std::forward<Args>(args)), 0)...};
}
long long pwr(long long base, long long p, long long mod) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
const long double PI = (long double)(3.1415926535897932384626433832795);
const long long mx_ll = numeric_limits<long long>::max();
const int mx_int = numeric_limits<int>::max();
const int mod = 1e9 + 7;
const int oo = 0x3f3f3f3f;
const long long OO = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;
const int dx[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
const int dsx[4] = {0, 1, 0, -1};
const int dsy[4] = {1, 0, -1, 0};
const int maxn = 200123;
int n;
vector<int> a;
void _build() {}
void _solve() {
  read(n);
  readv(a, n);
  int q;
  vector<int> day(n), val(a);
  cin >> q;
  vector<int> hi(max(q, n));
  for (int i = 0; i < (int)(q); i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      val[p] = x;
      day[p] = i;
    } else {
      int x;
      cin >> x;
      hi[i] = x;
    }
  }
  for (int i = q - 2; i >= (int)(0); i--)
    hi[i] = (hi[i]) > (hi[i + 1]) ? (hi[i]) : (hi[i + 1]);
  vector<int> ans(n);
  for (int i = 0; i < (int)(n); i++) {
    ans[i] = max(val[i], hi[day[i]]);
  }
  trace(day);
  trace(val);
  trace(hi);
  outv(ans);
}
void _input() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool GOOGLE = false;
  _build();
  int qq = 1;
  if (GOOGLE) cin >> qq;
  for (int i = 0; i < (int)(qq); i++) {
    _input();
    if (GOOGLE) cout << "Case #" << i + 1 << ": ";
    _solve();
  }
}
