#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
const long long int mod = 998244353;
const int inf = 1e9 + 100;
int r[N], l[N], k = 0, par[N], ans[N], sz[N];
vector<pair<int, pair<int, int>>> v;
vector<int> node[N], adj[N], vec;
map<pair<int, int>, int> id;
bool dead[N];
void dfs(int u) {
  vec.push_back(u);
  sz[u] = 1;
  for (auto x : adj[u]) {
    if (!dead[x] && x != par[u]) {
      par[x] = u;
      dfs(x);
      sz[u] += sz[x];
    }
  }
}
inline void cl() {
  for (auto x : vec) {
    par[x] = -1;
    sz[x] = 0;
  }
  vec.clear();
}
int find_centroid(int u, int k) {
  for (auto x : adj[u]) {
    if (!dead[x] && x != par[u] && sz[x] > k / 2) return find_centroid(x, k);
  }
  return u;
}
void solve(int u, int c) {
  dfs(u);
  u = find_centroid(u, sz[u]);
  cl();
  ans[u] = c;
  dead[u] = true;
  for (auto x : adj[u]) {
    if (!dead[x]) solve(x, c - 1);
  }
}
inline void add(int x, int y, bool b) {
  while (y != x) {
    node[k].push_back(y);
    if (b)
      y = r[y];
    else
      y = l[y];
  }
  node[k].push_back(x);
}
inline void add_edge(int x, int y, int i) {
  if (x == y + 1) return;
  pair<int, int> p = make_pair(x, y);
  if (id.find(p) != id.end()) {
    adj[i].push_back(id[p] - 1);
    adj[id[p] - 1].push_back(i);
  } else {
    id[p] = i + 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    r[i] = i + 1;
    l[i] = i - 1;
  }
  l[1] = n;
  r[n] = 1;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x < y) swap(x, y);
    int len = min(x - y, n - x + y);
    v.push_back({len, {x, y}});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    int x = v[i].second.first, y = v[i].second.second;
    bool b = (x - y <= n - x + y);
    add(x, y, b);
    if (b) {
      r[y] = x;
      l[x] = y;
    } else {
      l[y] = x;
      r[x] = y;
    }
    for (auto it : node[k]) {
      if (it != x && it != y) l[it] = r[it] = -1;
    }
    k++;
  }
  for (int i = 1; i <= n; i++) {
    if (l[i] != -1) node[k].push_back(i);
  }
  if (node[k].size()) k++;
  for (int i = 0; i < k; i++) {
    sort(node[i].begin(), node[i].end());
    reverse(node[i].begin(), node[i].end());
  }
  sort(node, node + k);
  for (int i = 0; i < k; i++) {
    int sz = node[i].size();
    for (int j = 0; j < sz - 1; j++) add_edge(node[i][j], node[i][j + 1], i);
    if (node[i][0] != n || node[i][sz - 1] != 1)
      add_edge(node[i][0], node[i][sz - 1], i);
  }
  solve(0, 20);
  for (int i = 0; i < k; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
