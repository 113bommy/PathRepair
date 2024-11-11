#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
template <typename T, typename U>
static inline void amin(T& x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T& x, U y) {
  if (x < y) x = y;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long min(long long a, long long b) { return (a < b) ? a : b; }
long long solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v(n);
  for (long long i = 0; i < n; i++) cin >> v[i].first;
  for (long long i = 0; i < n; i++) cin >> v[i].second;
  long long m1, m2;
  m1 = m2 = 0;
  priority_queue<pair<long long, long long> > p1, p2;
  for (long long i = 0; i < n; i++) {
    p1.push({v[i].first, i});
    p2.push({v[i].second, i});
    m1 = max(m1, v[i].first);
    m2 = max(m2, v[i].second);
  }
  bool vis[n];
  memset(vis, 0, sizeof(vis));
  queue<long long> q;
  for (long long i = 0; i < n; i++) {
    if (v[i].first == m1 || v[i].second == m2) {
      vis[i] = 1;
      q.push(i);
    }
  }
  while (!q.empty()) {
    auto f = q.front();
    q.pop();
    long long v1 = v[f].first, v2 = v[f].second;
    while (p1.size() && p1.top().first >= v1) {
      if (vis[p1.top().second] == 0) q.push(p1.top().second);
      vis[p1.top().second] = 1;
      p1.pop();
    }
    while (p2.size() && p2.top().first >= v2) {
      if (vis[p2.top().second] == 0) q.push(p2.top().second);
      vis[p2.top().second] = 1;
      p2.pop();
    }
  }
  for (auto i : vis) cout << i;
  cout << '\n';
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
