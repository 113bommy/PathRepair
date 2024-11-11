#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
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
using grafo = vector<vi>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
template <class T>
int lwb(V<T>& a, const T& b) {
  return int(lower_bound(begin(a), end(a), b) - begin(a));
}
const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ll INFI = 1e9;
const db PI = acos((db)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
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
template <class T>
void remDup(vector<T>& v) {
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));
}
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.second == b.second) return a.first < b.first;
  return (a.second < b.second);
}
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vi a(n);
  map<int, int> m;
  for (int i = (0); i < (n); ++i) {
    cin >> a[i];
    m[a[i] % 3]++;
  }
  int x = min(m[1], m[2]);
  m[1] -= x;
  m[2] -= x;
  cout << m[0] + x + m[1] / 3 + m[2] / 6 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
