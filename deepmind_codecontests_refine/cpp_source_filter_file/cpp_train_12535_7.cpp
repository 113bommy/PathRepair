#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e4 + 7;
const long long mod = 1e9 + 7;
const long long INF = 1e18 + 7;
const long long mlog = 20;
const long long SQ = 400;
vector<pair<long long, long long>> adj[maxn];
long long dis[maxn], mark[maxn];
vector<pair<long long, pair<long long, long long>>> g[maxn];
vector<pair<pair<long long, long long>, pair<long long, long long>>> edges;
void dij(long long s1, long long s2, long long f, char state) {
  map<pair<long long, long long>, long long> ans;
  dis[s1] = 0;
  dis[s2] = 0;
  mark[s1] = 1;
  mark[s2] = 2;
  set<pair<long long, long long>> st;
  st.insert({dis[s1], s1});
  st.insert({dis[s2], s2});
  while (!st.empty()) {
    long long v = st.begin()->second;
    st.erase({dis[v], v});
    for (auto edge : adj[v]) {
      long long u = edge.first;
      long long w = edge.second;
      if (dis[v] + w < dis[u]) {
        st.erase({dis[u], u});
        dis[u] = dis[v] + w;
        mark[u] = mark[v];
        st.insert({dis[u], u});
      } else if (dis[u] == dis[v] + w) {
        mark[u] |= mark[v];
      }
    }
    for (auto edge : g[v]) {
      long long w;
      long long u = edge.first;
      long long l = edge.second.first;
      long long r = edge.second.second;
      if (mark[v] == 1) w = l;
      if (mark[v] == 2) w = r;
      if (mark[v] == 3) w = (state == 'W' ? r : l);
      ans[{v, u}] = w;
      if (dis[v] + w < dis[u]) {
        st.erase({dis[u], u});
        dis[u] = dis[v] + w;
        mark[u] = mark[v];
        st.insert({dis[u], u});
      } else if (dis[u] == dis[v] + w) {
        mark[u] |= mark[v];
      }
    }
  }
  if (mark[f] == 1) {
    cout << "WIN"
         << "\n";
    for (auto edge : edges) {
      long long u = edge.first.first;
      long long v = edge.first.second;
      long long l = edge.second.first;
      long long r = edge.second.second;
      long long res = ((ans[{u, v}] ? ans[{u, v}] : l));
      if (res != r && res != l) res = r;
      cout << res << " ";
    }
    exit(0);
  }
  if (mark[f] == 3 && state == 'D') {
    cout << "DRAW"
         << "\n";
    for (auto edge : edges) {
      long long u = edge.first.first;
      long long v = edge.first.second;
      long long l = edge.second.first;
      long long r = edge.second.second;
      long long res = ((ans[{u, v}] ? ans[{u, v}] : l));
      cout << res << " ";
    }
    exit(0);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(), cout.tie();
  ;
  long long n, m, k;
  cin >> n >> m >> k;
  long long s1, s2, f;
  cin >> s1 >> s2 >> f;
  for (long long i = 0; i < m; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  for (long long i = 0; i < k; i++) {
    long long u, v, l, r;
    cin >> u >> v >> l >> r;
    edges.push_back({{u, v}, {l, r}});
    g[u].push_back({v, {l, r}});
  }
  for (long long i = 0; i < maxn; i++) dis[i] = +INF, mark[i] = 0;
  dij(s1, s2, f, 'W');
  for (long long i = 0; i < maxn; i++) dis[i] = +INF, mark[i] = 0;
  dij(s1, s2, f, 'D');
  cout << "LOSE"
       << "\n";
  return 0;
}
