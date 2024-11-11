#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
bool ldequal(long double a, long double b) { return abs(a - b) < 1e-9; }
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
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const int N = 1e5 + 1;
int dp[N];
int ans[N];
vector<int> adj[N];
int val;
bool an = false;
int dfs(int u, int p, int nn) {
  if (an) return 0;
  if (ans[u] != 0) return 0;
  int res = 1;
  for (auto x : adj[u]) {
    if (x == p || ans[x] != 0) continue;
    res += dfs(x, u, nn);
    if (an) return 0;
  }
  dp[u] = res;
  dp[p] = nn - res;
  an = true;
  for (auto x : adj[u]) {
    if (ans[x] != 0) continue;
    if (dp[x] > nn / 2) an = false;
  }
  if (an) val = u;
  return res;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i < n + 1; i++) {
    ;
  }
  dfs(1, 0, n);
  queue<pair<int, int> > q;
  q.push({val, 26});
  ans[val] = 26;
  while (!q.empty()) {
    int temp = q.front().first;
    int cc = q.front().second;
    q.pop();
    for (auto x : adj[temp]) {
      an = false;
      if (ans[x] != 0) continue;
      dfs(x, temp, dp[x]);
      q.push({val, cc - 1});
      ans[val] = cc - 1;
    }
  }
  for (int i = 1; i < n + 1; i++) {
    char c = ('A' + 26 - ans[i]);
    cout << c << " ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long test = 1;
  for (int i = 1; i < test + 1; i++) {
    ;
    solve();
    cout << "\n";
  }
  return 0;
}
