#include <bits/stdc++.h>
using namespace std;
inline bool isLow(char ch) { return (ch >= 'a' && ch <= 'z'); }
inline bool isUpp(char ch) { return (ch >= 'A' && ch <= 'Z'); }
inline bool isDig(char ch) { return (ch >= '0' && ch <= '9'); }
inline bool are_equal(double a, double b) {
  return fabs(a - b) < numeric_limits<double>::epsilon();
}
inline bool less_than(double a, double b) {
  return (b - a) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) *
                    numeric_limits<double>::epsilon());
}
inline bool greater_than(double a, double b) {
  return (a - b) > ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) *
                    numeric_limits<double>::epsilon());
}
template <typename T, typename... args>
inline string arrStr(T arr, int n) {
  stringstream s;
  s << "[ ";
  for (int i = 0; i < n - 1; i++) s << arr[i] << ", ";
  s << arr[n - 1] << " ]";
  return s.str();
}
inline void __evars_begin(int line) { cout << "#" << line << ": "; }
template <typename T>
inline void __evars_out_var(vector<T> val) {
  cout << arrStr(val, val.size());
}
template <typename T>
inline void __evars_out_var(T *val) {
  cout << arrStr(val, 10);
}
template <typename T>
inline void __evars_out_var(T val) {
  cout << val;
}
inline void __evars(vector<string>::iterator it) { cout << endl; }
template <typename T, typename... Args>
inline void __evars(vector<string>::iterator it, T a, Args... args) {
  cout << it->substr((*it)[0] == ' ', it->length()) << " = ";
  __evars_out_var(a);
  cout << "; ";
  __evars(++it, args...);
}
inline vector<string> split(const string &s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void in(int &n, int a[]) {
  cin >> n;
  for (__typeof(n - 1) i = (0); i <= (n - 1); i++) cin >> a[i];
}
void in(int &n, vector<int> &a) {
  cin >> n;
  a.resize(n);
  for (__typeof(n - 1) i = (0); i <= (n - 1); i++) cin >> a[i];
}
void out(int n, int a[]) {
  for (__typeof(n - 1) i = (0); i <= (n - 1); i++)
    cout << a[i] << " \n"[i + 1 == n];
}
void out(vector<int> &a) {
  for (__typeof(a.size() - 1) i = (0); i <= (a.size() - 1); i++)
    cout << a[i] << " \n"[i + 1 == a.size()];
}
template <typename T = long long>
T multiply(T a, T b, T mod) {
  T res = 0;
  a %= mod;
  b %= mod;
  while (b) {
    if (b & 0x1) res = (res + a) % mod;
    b >>= 1;
    if (a < mod - a)
      a <<= 1;
    else
      a -= (mod - a);
  }
  return res;
}
template <typename T = long long>
T power(T val, T p, T mod) {
  val %= mod;
  T res = 1;
  while (p > 0) {
    if (p & 0x1) res = (res * val) % mod;
    val = (val * val) % mod;
    p >>= 1;
  }
  return res;
}
template <typename T = long long>
T power(T val, T p) {
  T res = 1;
  while (p > 0) {
    if (p & 0x1) res = (res * val);
    val = (val * val);
    p >>= 1;
  }
  return res;
}
template <typename T = long long>
T powerMul(T val, T p, T mod) {
  val %= mod;
  T res = 1;
  while (p > 0) {
    if (p & 0x1) res = multiply(res, val, mod);
    val = multiply(val, val, mod);
    p >>= 1;
  }
  return res;
}
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
string toString(T x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
template <typename T>
T stringToT(string s) {
  T p;
  istringstream ss(s);
  ss >> p;
  return p;
}
template <typename T>
T SOD(T n) {
  __typeof(n) sum = 0, i = 1;
  for (; i * i <= n; i++)
    sum += (n % i) ? 0 : ((((i) * (i)) == n) ? i : i + n / i);
  return sum;
}
const int fx[] = {+1, -1, +0, +0};
const int fy[] = {+0, +0, +1, -1};
const int fx8[] = {+0, +0, +1, -1, -1, +1, -1, +1};
const int fy8[] = {-1, +1, +0, +0, +1, +1, -1, -1};
const int kx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int ky[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
const int mod = 1e9 + 7;
const int mx = 2 * 100001;
int n;
vector<int> adj[mx];
int vis[mx], dist[mx], par[mx];
void dfs(int u, int p) {
  vis[u] = 1;
  par[u] = p;
  for (int v : adj[u])
    if (!vis[v]) {
      dist[v] = dist[u] + 1;
      dfs(v, u);
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int u, v;
  for (__typeof(n - 1 - 1) i = (0); i <= (n - 1 - 1); i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  int p = 1;
  for (int i = 2; i <= n; i++)
    if (dist[i] > dist[p]) p = i;
  memset(vis, 0, sizeof(vis));
  memset(dist, 0, sizeof(dist));
  dfs(p, -1);
  int q = 1;
  for (int i = 2; i <= n; i++)
    if (dist[i] > dist[q]) q = i;
  memset(vis, 0, sizeof(vis));
  memset(dist, 0, sizeof(dist));
  int qq = q;
  vector<int> tmp;
  while (qq != -1) {
    tmp.push_back(qq);
    vis[qq] = 1;
    qq = par[qq];
  }
  int ans = 0, s = tmp[1];
  for (int u : tmp) dfs(u, u);
  for (int i = 1; i <= n; i++)
    if (dist[i] > ans) ans = dist[i], s = i;
  ans += tmp.size() - 1;
  cout << ans << '\n';
  cout << p << ' ' << q << ' ' << s;
  return 0;
}
