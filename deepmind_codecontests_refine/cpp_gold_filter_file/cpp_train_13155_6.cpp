#include <bits/stdc++.h>
using namespace std;
clock_t start;
mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
template <typename T>
void _F(const char *name, T arg1) {
  cerr << name << " = " << arg1 << '\n';
}
template <typename T, typename... Args>
void _F(const char *names, T arg1, Args... args) {
  const char *name = strchr(names, ',');
  cerr.write(names, name - names) << " = " << arg1 << '\n';
  _F(name + 2, args...);
}
const long long N = 1e5 + 1;
std::vector<long long> is(N);
vector<pair<long long, long long> > g[N];
long long c[N], black, white;
void dfs(long long v) {
  is[v] = 1;
  if (c[v])
    white = v;
  else
    black = v;
  for (auto u : g[v]) {
    if (is[u.first]) continue;
    dfs(u.first);
  }
}
void solve() {
  long long n;
  cin >> n;
  long long s[n];
  bool vis[n];
  set<long long> w, b;
  for (long long i = 0; i < n; i++) {
    vis[i] = 0;
    cin >> c[i] >> s[i];
    if (c[i])
      w.insert(i);
    else
      b.insert(i);
  }
  for (long long i = 0; i < n; i++) {
    if (vis[i]) continue;
    queue<long long> q;
    vis[i] = 1;
    q.push(i);
    if (c[i])
      w.erase(i);
    else
      b.erase(i);
    while (!q.empty()) {
      long long v = q.front();
      q.pop();
      if (c[v]) {
        std::vector<long long> temp;
        for (auto u : b) {
          if (!s[v]) break;
          if (!vis[u]) {
            vis[u] = 1;
            long long wt = min(s[v], s[u]);
            s[v] -= wt;
            s[u] -= wt;
            g[v].push_back({u, wt});
            q.push(u);
          }
          if (!s[u]) temp.push_back(u);
        }
        for (auto u : temp) b.erase(u);
      } else {
        std::vector<long long> temp;
        for (auto u : w) {
          if (!s[v]) break;
          if (!vis[u]) {
            vis[u] = 1;
            long long wt = min(s[v], s[u]);
            s[v] -= wt;
            s[u] -= wt;
            g[v].push_back({u, wt});
            q.push(u);
          }
          if (!s[u]) temp.push_back(u);
        }
        for (auto u : temp) w.erase(u);
      }
    }
  }
  bool f = 1;
  pair<long long, long long> p = {-1, -1};
  std::vector<long long> bb, ww;
  for (long long i = 0; i < n; i++) {
    if (is[i]) continue;
    black = -1;
    white = -1;
    dfs(i);
    if (black != -1 && white != -1 && f)
      p = {black, white}, f = 0;
    else if (black != -1)
      bb.push_back(black);
    else
      ww.push_back(white);
  }
  if (p.first != -1) {
    for (auto u : bb) g[p.second].push_back({u, 0});
    for (auto u : ww) g[p.first].push_back({u, 0});
  } else {
    for (auto u : bb) {
      g[ww[0]].push_back({u, 0});
    }
    for (long long i = 1; i < (long long)((ww).size()); i++)
      g[bb[0]].push_back({ww[i], 0});
  }
  for (long long i = 0; i < n; i++) {
    for (auto u : g[i]) {
      cout << i + 1 << " " << u.first + 1 << " " << u.second << '\n';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  start = clock();
  cout << fixed << setprecision(12);
  for (long long i = 1; i <= t; ++i) {
    solve();
    cout << '\n';
  }
  return 0;
}
