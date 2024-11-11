#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  long long l = v.size();
  for (long long i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
const long long N = 1e5 + 100;
vector<vector<pair<long long, long long>>> g1(N);
vector<vector<pair<long long, long long>>> g2(N);
long long vis[N];
long long n, m;
set<pair<long long, long long>> edgDone;
map<long long, vector<long long>> shortest_path;
void dfs(long long v, long long p, long long w) {
  if (vis[v] == 1) {
    return;
  }
  if (p != 0) {
    g2[v].push_back(make_pair(p, w));
    g2[p].push_back(make_pair(v, w));
    edgDone.insert(make_pair(min(v, p), max(v, p)));
  }
  vis[v] = 1;
  for (auto edg : g1[v]) {
    long long u = edg.first;
    long long w = edg.second;
    dfs(u, v, w);
  }
}
void dijistra(long long s) {
  vector<long long> d(n + 1, 1000000000000000001);
  set<pair<long long, long long>> q;
  d[s] = 0;
  q.insert(make_pair(d[s], s));
  while (!q.empty()) {
    long long v = (*q.begin()).second;
    long long v_d = (*q.begin()).first;
    q.erase(q.begin());
    for (auto t : g1[v]) {
      long long to = t.first;
      long long weight = t.second;
      long long get_out = v_d + weight;
      if (get_out < d[to]) {
        d[to] = get_out;
        q.insert(make_pair(get_out, to));
      }
    }
  }
  shortest_path[s] = d;
}
long long timer;
vector<long long> tin, tout;
vector<vector<long long>> up;
long long l;
long long level[N];
void dfs2(long long v, long long p) {
  tin[v] = ++timer;
  up[v][0] = p;
  level[v] = level[p] + 1;
  for (long long i = 1; i <= l; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  for (auto e : g2[v]) {
    long long u = e.first;
    if (u != p) dfs2(u, v);
  }
  tout[v] = ++timer;
}
bool is_ancetor(long long u, long long v) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}
long long lca(long long u, long long v) {
  if (is_ancetor(u, v)) return u;
  if (is_ancetor(v, u)) return v;
  for (long long i = l; i >= 0; --i) {
    if (!is_ancetor(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}
void preprocess(long long root) {
  tin.resize(n + 1);
  tout.resize(n + 1);
  timer = 0;
  l = ceil(log2(n)) + 10;
  up.assign(n + 1, vector<long long>(l + 1));
  dfs2(root, root);
}
long long dist[N];
void dfs3(long long v, long long p, long long w) {
  dist[v] = w;
  for (auto e : g2[v]) {
    long long u = e.first;
    long long ww = e.second;
    if (u == p) continue;
    dfs3(u, v, w + ww);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long i = 1; i <= m; i++) {
    long long v, u, w;
    cin >> v >> u >> w;
    g1[u].push_back(make_pair(v, w)), g1[v].push_back(make_pair(u, w));
  }
  dfs(1, 0, 0);
  set<long long> test;
  for (long long i = 1; i <= n; i++) {
    for (auto j : g1[i]) {
      long long v = j.first;
      pair<long long, long long> p = make_pair(min(i, v), max(i, v));
      if (edgDone.find(p) == edgDone.end()) {
        test.insert(i), test.insert(v);
      }
    }
  }
  for (auto i : test) {
    dijistra(i);
  }
  preprocess(1);
  dfs3(1, 0, 0);
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    long long a, b;
    cin >> a >> b;
    long long ans = 1000000000000000001;
    if (is_ancetor(a, b)) {
      long long temp = dist[b] - dist[a];
      ans = min(ans, temp);
    } else if (is_ancetor(b, a)) {
      long long temp = dist[a] - dist[b];
      ans = min(ans, temp);
    } else {
      long long temp = dist[a] + dist[b] - dist[lca(a, b)];
      ans = min(ans, temp);
    }
    for (auto j : test) {
      long long temp = shortest_path[j][a] + shortest_path[j][b];
      ans = min(ans, temp);
    }
    cout << ans << "\n";
  }
}
