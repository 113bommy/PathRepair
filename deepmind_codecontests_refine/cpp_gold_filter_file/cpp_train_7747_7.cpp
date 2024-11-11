#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
int nxt(int _i, int _n) { return _i == _n - 1 ? 0 : _i + 1; }
int prv(int _i, int _n) { return _i == 0 ? _n - 1 : _i - 1; }
struct Tree {
  int n, n1, n3, id;
  long long sum, maxD, maxx;
  vector<vector<int> > gr;
  vector<long long> down, up, d, maxUp, maxDown[2];
  vector<int> child;
  void dfs1(int u, int p) {
    child[u] = 1;
    for (int v : gr[u])
      if (v != p) {
        dfs1(v, u);
        child[u] += child[v];
        down[u] += down[v] + child[v];
        sum += child[v] * (n - child[v]);
      }
  }
  void dfs2(int u, int p) {
    for (int v : gr[u])
      if (v != p) {
        up[v] = up[u] + down[u] - down[v] - child[v] + n - child[v];
        dfs2(v, u);
      }
  }
  void solve1(int u, int p) {
    maxDown[0][u] = d[u] * n3;
    for (int v : gr[u])
      if (v != p) {
        solve1(v, u);
        long long tmp = maxDown[0][v] + n1 * n3;
        for (int _ = 0; _ < 2; ++_)
          if (tmp > maxDown[_][u]) swap(maxDown[_][u], tmp);
      }
  }
  void solve2(int u, int p) {
    for (int v : gr[u])
      if (v != p) {
        maxUp[v] = maxUp[u] + n1 * n3;
        long long tmp = maxDown[0][v] + n1 * n3;
        maxUp[v] = max(
            maxUp[v],
            (tmp == maxDown[0][u] ? maxDown[1][u] : maxDown[0][u]) + n1 * n3);
        solve2(v, u);
      }
  }
  void prep() {
    down.assign(n + 5, 0);
    up.assign(n + 5, 0);
    d.assign(n + 5, 0);
    child.assign(n + 5, 0);
    maxx = maxD = sum = 0;
    dfs1(1, 1);
    dfs2(1, 1);
    for (int i = 1; i <= n; ++i) d[i] = down[i] + up[i], maxD = max(maxD, d[i]);
    maxUp.assign(n + 5, 0);
    maxDown[0].assign(n + 5, 0);
    maxDown[1].assign(n + 5, 0);
    solve1(1, 1);
    solve2(1, 1);
    for (int u = 1; u <= n; ++u)
      maxx = max(maxx, d[u] * n1 + max(maxUp[u], maxDown[0][u]));
  }
} tree[3];
int main() {
  for (int _ = 0; _ < 3; ++_) {
    scanf("%d", &tree[_].n);
    tree[_].gr.assign(tree[_].n + 5, vector<int>());
    tree[_].id = _;
  }
  for (int _ = 0; _ < 3; ++_) {
    for (int i = 1; i < tree[_].n; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      tree[_].gr[u].push_back(v);
      tree[_].gr[v].push_back(u);
    }
  }
  for (int _ = 0; _ < 3; ++_)
    tree[_].n1 = tree[prv(_, 3)].n, tree[_].n3 = tree[nxt(_, 3)].n,
    tree[_].prep();
  for (int _ = 0; _ < 3; ++_)
    ans = max(
        ans,
        tree[_].n * (tree[_].n1 + tree[_].n3) +
            tree[prv(_, 3)].maxD * (tree[prv(_, 3)].n1 + tree[prv(_, 3)].n3) +
            tree[nxt(_, 3)].maxD * (tree[nxt(_, 3)].n1 + tree[nxt(_, 3)].n3) +
            2 * tree[_].n1 * tree[_].n3 + tree[_].maxx);
  for (int _ = 0; _ < 3; ++_) ans += tree[_].sum;
  cout << ans;
  return 0;
}
