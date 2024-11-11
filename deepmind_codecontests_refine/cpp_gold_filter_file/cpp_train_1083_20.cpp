#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxpq = priority_queue<T>;
inline long long CC(long long n, long long y) {
  return (((n) + (y - 1) - 1) / (y - 1)) - (((n) + (y)-1) / (y));
}
inline long long FF(long long n, long long y) { return n / y - n / (y + 1); }
inline long long __gcd(long long a, long long b) {
  return !b ? a : __gcd(b, a % b);
}
inline int add(int a, int b, int p = 1000000007) {
  int c = a + b;
  if (c >= p) c -= p;
  return c;
}
inline int sub(int a, int b, int p = 1000000007) {
  int c = a - b;
  if (c < 0) c += p;
  return c;
}
inline int mul(int a, int b, int p = 1000000007) { return (a * 1ll * b) % p; }
const int inf = 1e9;
int grid[2005][2005];
int m, n, k, s, a[100005];
vector<pair<int, int>> adj[10];
int mxp[10], mxn[10], mnp[10], mnn[10];
int dist(int i, int j) {
  int ans = 0;
  ans = max(ans, mxp[i] - mnp[j]);
  ans = max(ans, mxp[j] - mnp[i]);
  ans = max(ans, mxn[i] - mnn[j]);
  ans = max(ans, mxn[j] - mnn[i]);
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  clock_t clk = clock();
  cerr << "I will return...\n";
  cin >> n >> m >> k >> s;
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++) {
      cin >> grid[i][j];
      adj[grid[i][j]].push_back({i, j});
    }
  for (int i = (0); i < (s); i++) cin >> a[i];
  for (int i = (1); i < (k + 1); i++) {
    mnp[i] = mnn[i] = inf;
    mxp[i] = mxn[i] = -inf;
    for (auto p : adj[i]) {
      mxp[i] = max(mxp[i], p.first + p.second);
      mxn[i] = max(mxn[i], p.first - p.second);
      mnp[i] = min(mnp[i], p.first + p.second);
      mnn[i] = min(mnn[i], p.first - p.second);
    }
    42;
  }
  int ans = 0;
  for (int i = (1); i < (s); i++) {
    int kk;
    ans = max(ans, kk = dist(a[i - 1], a[i]));
    42;
  }
  cout << ans << '\n';
  cerr << "...don't you ever hang your head.\n";
  cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC
       << '\n';
}
