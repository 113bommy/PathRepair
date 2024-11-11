#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
map<string, int> mapper;
int N, M, color[maxn], sz[maxn], big[maxn], tmp[maxn], depth[maxn];
unordered_map<char, int> cnt[maxn];
unordered_map<int, int> res[maxn];
unordered_set<int> depths[maxn];
vector<int> graph[maxn];
void addd(int c, int d) {
  if (++cnt[d][c] == 1) {
    tmp[d]++;
  }
}
void remove(int c, int d) {
  if (--cnt[d][c] == 0) {
    tmp[d]--;
  }
}
void init(int u, int p, int d) {
  sz[u] = 1;
  depth[u] = d;
  for (auto &v : graph[u]) {
    if (v == p) continue;
    init(v, u, d + 1);
    sz[u] += sz[v];
  }
}
void add(int u, int p, int x) {
  if (x == 1)
    addd(color[u], depth[u]);
  else
    remove(color[u], depth[u]);
  for (auto &v : graph[u]) {
    if (v == p || big[v]) continue;
    add(v, u, x);
  }
}
void dfs(int u, int p, int keep) {
  int maxi = -1, idx = -1;
  for (auto &v : graph[u]) {
    if (v == p) continue;
    if (sz[v] > maxi) {
      maxi = sz[v];
      idx = v;
    }
  }
  for (auto &v : graph[u]) {
    if (v == p || v == idx) continue;
    dfs(v, u, 0);
  }
  if (idx != -1) {
    dfs(idx, u, 1);
    big[idx] = 1;
  }
  add(u, p, 1);
  for (auto &x : depths[u]) {
    res[u][x] = tmp[x + depth[u]];
  }
  if (idx != -1) big[idx] = 0;
  if (!keep) add(u, p, -1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  vector<int> root;
  int c = 1;
  for (int i = 0; i < N; i++) {
    string str;
    int p;
    cin >> str >> p;
    p--;
    if (mapper.find(str) == mapper.end()) {
      mapper[str] = c++;
    }
    color[i] = mapper[str];
    if (p == -1) {
      root.push_back(i);
      continue;
    }
    graph[i].push_back(p);
    graph[p].push_back(i);
  }
  cin >> M;
  vector<pair<int, int> > queries;
  while (M--) {
    int u, d;
    cin >> u >> d;
    u--;
    depths[u].insert(d);
    queries.push_back({u, d});
  }
  for (auto &x : root) {
    init(x, x, 0);
    dfs(x, x, 0);
  }
  for (auto &x : queries) {
    cout << res[x.first][x.second] << '\n';
  }
  return 0;
}
