#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
void accell() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
}
const long long N = 200000;
const long long inf = 1e18;
long long tin[N], tout[N];
long long tt = 0;
const long long LG = 19;
long long dp[N][LG];
long long d[N];
vector<long long> g[N];
void dfs(long long v, long long p = -1) {
  long long f = p;
  if (f == -1) f = v;
  dp[v][0] = f;
  for (long long i = 1; i < LG; ++i) dp[v][i] = dp[dp[v][i - 1]][i - 1];
  tin[v] = tt++;
  for (long long to : g[v]) {
    if (to != p) {
      d[to] = d[v] + 1;
      dfs(to, v);
    }
  }
  tout[v] = tt++;
}
long long get_lca(long long a, long long b) {
  if (d[a] < d[b]) swap(a, b);
  for (long long i = LG - 1; i >= 0; --i)
    if (d[a] - d[b] >= (1 << i)) a = dp[a][i];
  if (a == b) return a;
  for (long long i = LG - 1; i >= 0; --i)
    if (dp[a][i] != dp[b][i]) a = dp[a][i], b = dp[b][i];
  return dp[a][0];
}
vector<long long> g1[N];
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return tin[a.first] < tin[b.first];
}
bool cmp1(long long a, long long b) { return tin[a] < tin[b]; }
bool is_par(long long a, long long b) {
  return tin[a] <= tin[b] && tout[a] >= tout[b];
}
pair<long long, long long> dist[N];
long long pp[N];
signed main() {
  accell();
  long long n;
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    pp[i] = -1;
    dist[i] = {inf, inf};
  }
  for (long long i = 1; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  long long q;
  cin >> q;
  while (q--) {
    long long k, m;
    cin >> k >> m;
    vector<pair<long long, long long> > vec;
    vector<pair<long long, long long> > tt;
    vector<long long> curs(k);
    for (long long i = 0; i < k; ++i) {
      long long v, s;
      cin >> v >> s;
      --v;
      curs[i] = s;
      tt.push_back({v, s});
      vec.push_back({v, s});
    }
    vector<long long> vv;
    for (long long i = 0; i < m; ++i) {
      long long v;
      cin >> v;
      --v;
      vv.push_back(v);
      vec.push_back({v, -1});
    }
    sort(vec.begin(), vec.end(), &cmp);
    vector<long long> cur;
    for (long long i = 0; i + 1 < vec.size(); ++i) {
      cur.push_back(vec[i].first);
      cur.push_back(get_lca(vec[i].first, vec[i + 1].first));
    }
    cur.push_back(vec.back().first);
    sort(cur.begin(), cur.end());
    cur.erase(unique(cur.begin(), cur.end()), cur.end());
    sort(cur.begin(), cur.end(), &cmp1);
    stack<long long> st;
    for (long long i = 0; i < cur.size(); ++i) {
      long long v = cur[i];
      if (st.empty()) {
        st.push(v);
        continue;
      }
      while (st.size() > 0 && !is_par(st.top(), v)) st.pop();
      if (st.size() > 0) {
        g1[st.top()].push_back(v);
        g1[v].push_back(st.top());
      }
      st.push(v);
    }
    set<pair<pair<long long, long long>, long long> > s;
    for (long long i = 0; i < tt.size(); ++i) {
      s.insert({{0, i}, tt[i].first});
      dist[tt[i].first] = {0LL, i};
    }
    while (s.size() > 0) {
      long long v = s.begin()->second;
      long long dd = (*s.begin()).first.first;
      long long nm = (*s.begin()).first.second;
      s.erase(s.begin());
      if (dd != dist[v].first || nm != dist[v].second) continue;
      long long kek = dist[v].second;
      for (auto to : g1[v]) {
        long long ff =
            d[tt[nm].first] + d[to] - 2 * d[get_lca(tt[nm].first, to)];
        pair<long long, long long> lol = {(ff + curs[kek] - 1) / curs[kek], nm};
        if (dist[to].first > lol.first ||
            (lol.second < dist[to].second && dist[to].first == lol.first)) {
          dist[to] = lol;
          s.insert({dist[to], to});
        }
      }
    }
    for (long long i = 0; i < vv.size(); ++i) {
      cout << dist[vv[i]].second + 1 << ' ';
    }
    cout << '\n';
    for (long long i = 0; i < cur.size(); ++i) {
      long long v = cur[i];
      g1[v].clear();
      dist[v] = {inf, inf};
      pp[v] = -1;
    }
  }
  return 0;
}
