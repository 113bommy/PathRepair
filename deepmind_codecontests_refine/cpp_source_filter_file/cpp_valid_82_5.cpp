#include <bits/stdc++.h>
using namespace std;
using mii = map<int, int>;
using pii = pair<int, int>;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
const pair<int, int> DD[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int mod = 1e9 + 7, mxN = 2e5 + 5, INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
template <typename... T>
void print(T... args) {
  ((cout << args << " "), ...), cout << "\n";
}
template <typename... T>
void dbgout(string vars, T... args) {
  cout << "\n";
  cout << "[";
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << args, delim = ", "));
  cout << "]";
  cout << "\n";
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& ot, pair<T1, T2>& p) {
  ot << p.first << ' ' << p.second;
  return ot;
}
template <typename T1, typename T2>
bool cmax(T1& a, T2 b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
bool cmin(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (T& x : v) in >> x;
  return in;
}
template <typename T>
ostream& operator<<(ostream& ot, vector<T>& v) {
  for (T& x : v) ot << x << ' ';
  return ot;
}
template <typename T>
ostream& operator<<(ostream& ot, set<T>& s) {
  for (T x : s) ot << x << ' ';
  return ot;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& ot, map<T1, T2>& M) {
  for (auto& [x, y] : M)
    ot << "(" << x << " : " << y << ")"
       << "\n";
  return ot;
}
template <typename T>
using pq = priority_queue<T, vector<T>, greater<T>>;
ll mod_pow(ll x, ll y) {
  ll res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
ll mod_inv(ll n) {
  ll ans = mod_pow(n, mod - 2);
  return ans;
}
ll mul(ll a, ll b) {
  a %= mod, b %= mod;
  return (a * b) % mod;
}
ll sub(ll a, ll b) {
  a %= mod, b %= mod;
  return (a - b + mod) % mod;
}
ll add(ll a, ll b) {
  a %= mod, b %= mod;
  return (a + b) % mod;
}
bool _prime(ll n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (ll i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  return 1;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n, q, L, R;
  cin >> n >> q;
  string s;
  cin >> s;
  s = " " + s;
  for (int i = 2; i <= n; i += 2) {
    s[i] ^= '+' ^ '-';
  }
  vi pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = (s[i] == '+' ? 1 : -1) + pref[i - 1];
  }
  vvi pos(2 * n + 1);
  for (int i = 1; i <= (int)(n); i++) {
    pos[n + pref[i]].emplace_back(i);
  }
  while (q--) {
    cin >> L >> R;
    int x = pref[R] - pref[L - 1];
    if (x == 0)
      cout << "0\n";
    else if (x & 1) {
      cout << "1\n";
      int target = (x < 0 ? (x - 1) / 2 : (x + 1) / 2) + pref[L - 1];
      auto it = lower_bound(pos[n + target].begin(), pos[n + target].end(), L);
      cout << *it << '\n';
    } else {
      cout << "2\n";
      int target = x / 2 + pref[L - 1];
      auto it1 = lower_bound(pos[n + target].begin(), pos[n + target].end(), L);
      target = x + pref[L - 1];
      auto it2 = lower_bound(pos[n + target].begin(), pos[n + target].end(), L);
      cout << *it1 << ' ' << R << '\n';
    }
  }
}
int main() {
  cout << fixed << setprecision(12);
  cin.tie(0)->sync_with_stdio(0), cin.exceptions(cin.failbit);
  int t;
  for (cin >> t; t--;) solve();
  return 0;
}
