#include <bits/stdc++.h>
using namespace std;
string to_string(bool b) { return (b ? "true" : "false"); }
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using V = vector<T>;
template <typename T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
using ll = long long;
using db = long double;
using vd = vector<db>;
using vs = vector<string>;
using pi = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vpi = vector<pi>;
const int mod = 1000000007;
const ll INF = 1e18;
const db PI = acos((db)-1);
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
const int mx = 1e5 + 10;
int n, m;
int arr[mx][10], nex[mx][10];
void solve() {
  cin >> n >> m;
  for (int j = (0); j < (m); ++j)
    for (int i = (0); i < (n); ++i) cin >> arr[i][j];
  for (int j = (0); j < (m); ++j) {
    for (int i = (0); i < (n - 1); ++i) nex[arr[i][j]][j] = arr[i + 1][j];
  }
  for (int j = (1); j < (m); ++j) {
    for (int i = (1); i < (n + 1); ++i) {
      if (nex[i][0] && (nex[i][0] != nex[i][j])) nex[i][0] = 0;
    }
  }
  ll ans = 0;
  int prev = -1;
  for (int i = (0); i < (n); ++i) {
    if (!nex[arr[i][0]][0]) {
      int len = i - prev;
      ans += len * (len + 1) / 2;
      prev = i;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  for (int ii = 1; ii <= tt; ii++) solve();
}
