#include <bits/stdc++.h>
using namespace std;
template <typename Arg, typename... Args>
void trace(Arg &&arg, Args &&...args) {}
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
void outvp(vector<pair<T, S>> &v) {
  for (pair<T, S> x : v) cout << x.first << " " << x.second << endl;
}
template <typename T>
void outv(vector<T> &v) {
  for (T x : v) cout << x << " ";
  cout << endl;
}
template <typename T>
void outs(set<T> &v) {
  for (T x : v) cout << x << " ";
  cout << endl;
}
template <typename T>
void outm(map<T, int> &v, int n = 1) {
  for (T &x : v) cout << (n == 1 ? x.first : x.second) << " ";
  cout << endl;
}
template <typename T>
void finalize(T x) {
  cout << x << endl;
  exit(0);
}
void yesno(int x, int last = 1) {
  cout << (x ? "YES" : "NO") << endl;
  if (last) exit(0);
}
template <typename T>
void readv(vector<T> &v, int n) {
  v = vector<T>(n);
  for (int i = 0; i < (int)(n); i++) cin >> (v[i]);
}
template <typename T>
void reads(set<T> &v, int n) {
  T x;
  for (int i = 0; i < (int)(n); i++) {
    cin >> x;
    v.insert(x);
  }
}
template <typename T>
void readm(map<T, int> &v, int n) {
  T x;
  for (int i = 0; i < (int)(n); i++) {
    cin >> x;
    v[x]++;
  }
}
template <typename Arg, typename... Args>
void read(Arg &&arg, Args &&...args) {
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
const int mod = 998244353;
const int oo = 0x3f3f3f3f;
const long long OO = 0x3f3f3f3f3f3f3f3fll;
const double eps = 1e-9;
const int dx[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
const int dsx[4] = {0, 1, 0, -1};
const int dsy[4] = {1, 0, -1, 0};
const int maxn = 300123;
void _build() {}
void _solve() {
  int n;
  cin >> n;
  map<int, int> p, s;
  vector<pair<int, int>> both;
  for (int i = 0; i < (int)(n); i++) {
    int a, b;
    cin >> a >> b;
    p[a]++;
    s[b]++;
    both.push_back({a, b});
  }
  long long f[maxn];
  f[0] = 1;
  for (int i = 1; i < (int)(maxn); i++) f[i] = f[i - 1] * i % mod;
  long long a = 1, b = 1, c = 1;
  for (const auto &it : p) {
    a = a * f[it.second] % mod;
  }
  for (const auto &it : s) {
    b = b * f[it.second] % mod;
  }
  sort((both).begin(), (both).end());
  for (int i = 0; i < (int)(n - 1); i++)
    if (both[i].second > both[i + 1].second) c = 0;
  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n and both[i] == both[j]) j++;
    c = c * f[j - i] % mod;
  }
  long long ans = (f[n] - a - b + c + mod * 5LL) % mod;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool GOOGLE = false;
  _build();
  int qq = 1;
  if (GOOGLE) cin >> qq;
  for (int i = 0; i < (int)(qq); i++) {
    if (GOOGLE) cout << "Case #" << i + 1 << ": ";
    _solve();
  }
}
