#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n, m, tc, cs = 1, q, len, k;
const int N = 2e5 + 5;
vector<int> g[N];
int leaf;
int depth[N], father[N], in_chain[N];
void dfs(int from, int par) {
  father[from] = par;
  for (int to : g[from]) {
    if (to ^ par) {
      depth[to] = depth[from] + 1;
      dfs(to, from);
    }
  }
}
void dfs2(int from, int par) {
  father[from] = par;
  for (int to : g[from]) {
    if (to ^ par) {
      depth[to] = depth[from] + 1;
      dfs2(to, from);
    }
  }
}
void dfs3(int from, int par) {
  for (int to : g[from]) {
    if (in_chain[to] or to == par) continue;
    depth[to] = depth[from] + 1;
    dfs3(to, from);
  }
}
void HalfDead() {
  cin >> n;
  int u, v;
  for (int i = 0; i < (int)n - 1; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  int mx = 0, node;
  for (int i = 1; i <= n; ++i) {
    if (depth[i] > mx) mx = depth[i], node = i;
  }
  memset(depth, 0, sizeof depth);
  dfs(node, 0);
  vector<int> res;
  res.push_back(node);
  mx = 0;
  for (int i = 1; i <= n; ++i) {
    if (depth[i] > mx) mx = depth[i], node = i;
  }
  int chain_size = depth[node];
  res.push_back(node);
  vector<int> chain;
  while (node != 0) {
    chain.push_back(node);
    node = father[node];
  }
  for (int x : chain) {
    in_chain[x] = 1;
  }
  memset(depth, 0, sizeof depth);
  for (int x : chain) {
    dfs3(x, 0);
  }
  mx = -1, node = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == res[0] or i == res[1]) continue;
    if (depth[i] > mx) {
      mx = depth[i];
      node = i;
    }
  }
  chain_size += (depth[node]);
  res.push_back(node);
  cout << chain_size << "\n";
  for (int x : res) cout << x << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(0);
  int tc = 1;
  while (tc--) {
    HalfDead();
  }
  return 0;
}
