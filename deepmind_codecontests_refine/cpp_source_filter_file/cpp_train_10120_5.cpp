#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-ffloat-store")
using namespace std;
clock_t time_p = clock();
void aryanc403() {}
const long long int INF = 0xFFFFFFFFFFFFFFFL;
long long int seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long int rnd(long long int l = 0, long long int r = INF) {
  return uniform_int_distribution<long long int>(l, r)(rng);
}
class CMP {
 public:
  bool operator()(pair<long long int, long long int> a,
                  pair<long long int, long long int> b) {
    return !(a.first < b.first || (a.first == b.first && a.second <= b.second));
  }
};
void add(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt == m.end())
    m.insert({x, cnt});
  else
    jt->second += cnt;
}
void del(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt->second <= cnt)
    m.erase(jt);
  else
    jt->second -= cnt;
}
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
const long long int mod = 1000000007L;
long long int T, n, i, j, k, in, cnt, l, r, u, v, x, y;
long long int m;
string s;
vector<long long int> dp, dpe;
vector<pair<long long int, long long int> > par;
vector<vector<pair<long long int, long long int> > > e;
vector<pair<long long int, long long int> > edges;
vector<long long int> vis;
struct UF {
  vector<long long int> e;
  UF(int n) : e(n, -1) {}
  bool same_set(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
void cycle(vector<long long int> &a) {
  long long int n = (int)(a).size();
  long long int i, mn = INF;
  for (i = 0; i < (n); ++i) {
    a.push_back(a[i]);
    mn = min(mn, a[i]);
  }
  n *= 2;
  for (l = 0; l < (n); ++l) {
    if (a[l] == mn) break;
  }
  for (r = (n - 1); r >= (0); --r) {
    if (a[r] == mn) break;
  }
  while (l + 1 < n && a[l] < a[l + 1]) l++;
  while (r - 1 >= 0 && a[r] < a[r - 1]) r--;
  if (l == r) dpe[mn] = l;
}
void dfs(long long int u, long long int p, long long int ed) {
  ;
  if (vis[u]) {
    if (vis[u] == 2) return;
    swap(u, p);
    vector<long long int> a;
    a.push_back(ed);
    while (u != p) {
      a.push_back(par[u].second);
      u = par[u].first;
    }
    cycle(a);
    return;
  }
  vis[u] = 1;
  par[u] = {p, ed};
  for (auto x : e[u]) {
    if (x.first == p) continue;
    dfs(x.first, u, x.second);
  }
  vis[u] = 2;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    cin >> n >> m;
    dp.resize(n + 1, 1);
    vis.resize(n + 1, 0);
    dpe.resize(m + 1, 0);
    par.resize(n + 1, {-1, -1});
    e.resize(n + 1, vector<pair<long long int, long long int> >());
    edges.push_back({0, 0});
    for (i = (1); i <= (m); ++i) {
      cin >> u >> v;
      e[u].push_back({v, i});
      e[v].push_back({u, i});
      edges.push_back({u, v});
    }
    dfs(1, 0, 0);
    UF d(n + 1);
    for (i = (m); i >= (1); --i) {
      u = edges[i].first;
      v = edges[i].second;
      if (d.join(u, v))
        dpe[i] = dp[u] + dp[v];
      else
        dpe[i] = dp[u] + dp[v] - dpe[dpe[i]];
      dp[u] = dp[v] = dpe[i];
    }
    for (i = (1); i <= (n); ++i) cout << dp[i] - 1 << " ";
    cout << "\n";
  }
  aryanc403();
  return 0;
}
