#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, q, l[N], r[N], level[N], p[N][20];
pair<int, int> res[N];
int import[N], numCity, numVirus, node[N], total_num;
vector<int> adj[N], newAdj[N];
struct T {
  int city, speed;
};
T virus[N];
int cnt = 0;
void dfs(int x, int pa) {
  cnt++;
  l[x] = cnt;
  p[x][0] = pa;
  for (auto &u : adj[x]) {
    if (u == pa) continue;
    level[u] = level[x] + 1;
    dfs(u, x);
  }
  r[x] = cnt;
}
void init_lca() {
  for (int k = 1; k <= 18; k++) {
    for (int i = 1; i <= n; i++) p[i][k] = p[p[i][k - 1]][k - 1];
  }
}
int lca(int x, int y) {
  if (x == 1 || y == 1) return 1;
  if (level[x] > level[y]) swap(x, y);
  int diff = level[y] - level[x];
  for (int k = 18; k >= 0; k--)
    if (diff >> k & 1) y = p[y][k];
  if (x == y) return x;
  for (int k = 18; k >= 0; k--) {
    if (p[x][k] != p[y][k]) {
      x = p[x][k];
      y = p[y][k];
    }
  }
  return p[x][0];
}
bool isParent(int p, int u) { return (l[p] <= l[u] && l[u] <= r[p]); }
bool lf(const int &x, const int &y) { return l[x] < l[y]; }
int dist(int x, int y) { return level[x] + level[y] - 2 * level[lca(x, y)]; }
void compress_tree() {
  total_num = numCity + numVirus;
  for (int i = 1; i <= numVirus; i++) node[i] = virus[i].city;
  for (int i = numVirus + 1; i <= total_num; i++)
    node[i] = import[i - numVirus];
  sort(node + 1, node + total_num + 1, lf);
  total_num = unique(node + 1, node + total_num + 1) - node - 1;
  int now = total_num;
  for (int i = 1; i < now; i++) {
    total_num++;
    node[total_num] = lca(node[i], node[i + 1]);
  }
  sort(node + 1, node + total_num + 1, lf);
  total_num = unique(node + 1, node + total_num + 1) - node - 1;
  for (int i = 1; i <= total_num; i++) newAdj[node[i]].clear();
  stack<int> st;
  st.push(node[1]);
  for (int i = 2; i <= total_num; i++) {
    while (!st.empty() && !isParent(st.top(), node[i])) st.pop();
    if (!st.empty()) {
      int par = st.top();
      newAdj[par].push_back(node[i]);
      newAdj[node[i]].push_back(par);
    }
    st.push(node[i]);
  }
}
int calc(int dist, int s) { return (dist - 1 + s) / s; }
void solve() {
  for (int i = 1; i <= total_num; i++) res[node[i]] = make_pair(1e9, 0);
  priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>,
                 greater<pair<pair<int, int>, int>>>
      pq;
  for (int i = 1; i <= numVirus; i++) {
    int id = virus[i].city;
    res[id] = make_pair(0, i);
    pq.push(make_pair(res[id], id));
  }
  while (!pq.empty()) {
    auto now = pq.top();
    pq.pop();
    if (res[now.second] != now.first) continue;
    for (auto &u : newAdj[now.second]) {
      if (res[u] > make_pair(calc(dist(u, virus[now.first.second].city),
                                  virus[now.first.second].speed),
                             now.first.second)) {
        res[u] = make_pair(calc(dist(u, virus[now.first.second].city),
                                virus[now.first.second].speed),
                           now.first.second);
        pq.push(make_pair(res[u], u));
      }
    }
  }
  for (int i = 1; i <= numCity; i++) cout << res[import[i]].second << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  init_lca();
  cin >> q;
  while (q--) {
    cin >> numVirus >> numCity;
    for (int i = 1; i <= numVirus; i++) cin >> virus[i].city >> virus[i].speed;
    for (int i = 1; i <= numCity; i++) cin >> import[i];
    compress_tree();
    solve();
  }
}
