#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const long long N = 3e5 + 5;
const long long MAX = 2e6 + 5;
const long long MOD = 998244353LL;
long long pwr(long long base, long long p, long long mod) {
  long long ans = 1;
  while (p) {
    if (p & 1LL) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2LL;
  }
  return ans;
}
long long n, m;
long long depth[N], dep[N];
long long vis[N];
long long u[N], v[N];
vector<long long> adj[N];
long long ans;
vector<int> vec;
int flag = 0;
void bfs(long long src) {
  queue<long long> q;
  q.push(src);
  depth[src] = 0;
  vis[src] = 1;
  vec.push_back(src);
  while (!q.empty()) {
    long long u = q.front();
    q.pop();
    for (auto v : adj[u]) {
      if (!vis[v]) {
        depth[v] = depth[u] + 1;
        q.push(v);
        vis[v] = 1;
        vec.push_back(v);
      } else {
        if (depth[u] == depth[v]) flag = 1;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(NULL));
  cout << fixed << setprecision(10);
  clock_t clk;
  clk = clock();
  ;
  long long tt;
  cin >> tt;
  while (tt--) {
    ans = 1;
    for (long long i = (0); i <= (n); ++i) {
      dep[i] = 0;
      depth[i] = 0;
      vis[i] = 0;
      adj[i].clear();
    }
    cin >> n >> m;
    for (long long i = (1); i <= (m); ++i) {
      long long x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
      u[i] = x;
      v[i] = y;
    }
    int sz = 0;
    for (long long i = (1); i <= (n); ++i) {
      if (!vis[i]) {
        if (sz)
          for (long long i = 0; i < (sz); ++i) dep[depth[vec[i]]] = 0;
        vec.clear();
        flag = 0;
        bfs(i);
        if (flag) cout << 0 << "\n";
        sz = vec.size();
        for (long long i = 0; i < (sz); ++i) dep[depth[vec[i]]]++;
        long long mx = 0;
        for (long long i = 0; i < (sz); ++i) mx = max(mx, depth[vec[i]]);
        long long cnt1 = 1;
        long long cnt2 = 1;
        for (long long i = (0); i <= (mx); ++i) {
          if (i & 1LL) {
            cnt1 = (cnt1 * pwr(2LL, dep[i], MOD)) % MOD;
          } else {
            cnt2 = (cnt2 * pwr(2LL, dep[i], MOD)) % MOD;
          }
        }
        ans = (ans * (cnt1 + cnt2)) % MOD;
      }
      if (flag) break;
    }
    if (flag) continue;
    cout << ans << "\n";
  }
  clk = clock() - clk;
  cerr << fixed << setprecision(6) << "Time: " << ((double)clk) / CLOCKS_PER_SEC
       << "\n";
  return 0;
  ;
}
