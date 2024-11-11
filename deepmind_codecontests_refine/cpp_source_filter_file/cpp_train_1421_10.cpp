#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC tartget("sse,sse2,sse3,sse4")
using namespace std;
const long long N = 1e6 + 10;
const long long B = 1700;
const long long N2 = 5e5 + 10;
const long long off = 1e3;
const long long inf = 1e18 + 10ll;
const long long mod = 1e9 + 7;
const double eps = 1e-12;
const double pi = 3.14159265358979323846;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
using namespace std;
long long n, m;
vector<long long> g[N];
set<long long> stg[N];
long long d[N];
long long pr[N];
long long ans = inf;
vector<long long> comp;
bool used[N];
void bfs() {
  fill(d, d + N, inf);
  queue<pair<pair<long long, long long>, long long>> q;
  q.emplace(make_pair(0, 0), 0);
  while (!q.empty()) {
    auto pp = q.front();
    long long v = pp.first.first;
    long long dst = pp.first.second;
    long long prevv = pp.second;
    q.pop();
    if (d[v] <= dst) continue;
    d[v] = dst;
    pr[v] = prevv;
    for (auto u : g[v])
      if (dst + 1 < d[u]) {
        q.emplace(make_pair(u, dst + 1), v);
      }
  }
  ans = min(ans, d[n - 1]);
}
vector<long long> getpath(long long v) {
  vector<long long> res;
  while (v) {
    res.push_back(v);
    v = pr[v];
  }
  res.push_back(v);
  reverse((res).begin(), (res).end());
  return move(res);
}
void dfs(long long v) {
  used[v] = true;
  comp.push_back(v);
  for (auto u : g[v])
    if (u && !used[u]) dfs(u);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  cin >> n >> m;
  for (long long i = 0; i < m; ++i) {
    long long v, u;
    cin >> v >> u;
    --v;
    --u;
    g[v].push_back(u);
    g[u].push_back(v);
    stg[v].insert(u);
    stg[u].insert(v);
  }
  bfs();
  if (ans <= 4) {
    cout << ans << "\n";
    auto v = getpath(n - 1);
    for (auto it : v) cout << (it + 1) << " ";
    cout << "\n";
    return 0;
  }
  for (long long i = 0; i < n; ++i)
    if (d[i] == 2) {
      vector<long long> v = getpath(i);
      v.push_back(0);
      v.push_back(n - 1);
      cout << 4 << "\n";
      for (auto it : v) cout << (it + 1) << " ";
      return 0;
    }
  for (long long i = 0; i < n; ++i)
    if (d[i] == 1) {
      comp.clear();
      dfs(i);
      long long sz = comp.size();
      for (auto v : comp)
        if ((long long)g[v].size() - 1 < sz - 1) {
          long long v2 = -1;
          vector<long long> good;
          for (auto u : comp)
            if (!stg[u].count(v) && u != v) good.push_back(u);
          for (auto u : good)
            for (auto u2 : g[u])
              if (stg[u2].count(v)) {
                v2 = u;
                cout << 5 << "\n";
                cout << 1 << " " << (v + 1) << " " << (u2 + 1) << " "
                     << (v2 + 1) << " " << (v + 1) << " " << n << "\n";
                return 0;
              }
        }
    }
  if (ans != inf) {
    cout << ans << "\n";
    auto v = getpath(n - 1);
    for (auto it : v) cout << (it + 1) << " ";
    cout << "\n";
    return 0;
  }
  cout << -1 << "\n";
}
