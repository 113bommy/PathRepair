#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400 * 1000 + 7;
const int INF = 1000 * 1000 * 1000 + 7;
vector<int> G[4 * MAXN], Gp[4 * MAXN];
bool vis[4 * MAXN];
int post[4 * MAXN];
int scc[4 * MAXN];
pair<int, int> range[MAXN];
pair<int, int> lefts[MAXN], rights[MAXN];
int it = 1;
void DFS_post(int v) {
  vis[v] = true;
  for (auto u : G[v]) {
    if (!vis[u]) DFS_post(u);
  }
  post[it++] = v;
}
void DFS_scc(int v, int nr) {
  scc[v] = nr;
  for (auto u : Gp[v]) {
    if (scc[u] == 0) DFS_scc(u, nr);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, p, M, m;
  cin >> n >> p >> M >> m;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    G[x + p].push_back(y);
    Gp[y].push_back(x + p);
    G[y + p].push_back(x);
    Gp[x].push_back(y + p);
  }
  for (int i = 1; i <= p; i++) {
    int l, r;
    cin >> l >> r;
    range[i] = {l, r};
    lefts[i] = {l, i};
    rights[i] = {r, i};
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v + p);
    Gp[v + p].push_back(u);
    G[v].push_back(u + p);
    Gp[u + p].push_back(v);
  }
  sort(lefts + 1, lefts + 1 + p);
  sort(rights + 1, rights + 1 + p);
  for (int i = 1; i <= p; i++) {
    auto [tmp1, x] = rights[i - 1];
    auto [tmp2, y] = rights[i];
    if (i > 1) {
      G[y + 2 * p].push_back(x + 2 * p);
      Gp[x + 2 * p].push_back(y + 2 * p);
    }
    G[y + 2 * p].push_back(y + p);
    Gp[y + p].push_back(y + 2 * p);
  }
  for (int i = p; i >= 1; i--) {
    auto [tmp1, x] = lefts[i + 1];
    auto [tmp2, y] = lefts[i];
    if (i < p) {
      G[y + 3 * p].push_back(x + 3 * p);
      Gp[x + 3 * p].push_back(y + 3 * p);
    }
    G[y + 3 * p].push_back(y + p);
    Gp[y + p].push_back(y + 3 * p);
  }
  rights[p + 1] = {INF, 0};
  int ind = 0;
  for (int i = 1; i <= p; i++) {
    auto [l, x] = lefts[i];
    while (rights[ind + 1].first < l) ind++;
    int y = rights[ind + 1].second;
    if (ind > 0) {
      G[x].push_back(y + 2 * p);
      Gp[y + 2 * p].push_back(x);
    }
  }
  lefts[0] = {-INF, 0};
  ind = p + 1;
  for (int i = p; i >= 1; i--) {
    auto [r, x] = rights[i];
    while (lefts[ind - 1].first > r) ind--;
    int y = lefts[ind - 1].second;
    if (ind <= p) {
      G[x].push_back(y + 3 * p);
      Gp[y + 3 * p].push_back(x);
    }
  }
  for (int i = 1; i <= 4 * p; i++) {
    if (!vis[i]) DFS_post(i);
  }
  int l = 1;
  for (int i = 4 * p; i >= 1; i--) {
    int v = post[i];
    if (scc[v] == 0) DFS_scc(v, l++);
  }
  vector<int> res;
  for (int i = 1; i <= p; i++) {
    if (scc[i] == scc[i + p]) {
      cout << "-1\n";
      return 0;
    }
    if (scc[i] > scc[i + p]) res.push_back(i);
  }
  int f = M;
  for (auto i : res) {
    f = min(range[i].second, f);
  }
  cout << res.size() << ' ' << f << '\n';
  for (auto i : res) cout << i << ' ';
  cout << '\n';
  return 0;
}
