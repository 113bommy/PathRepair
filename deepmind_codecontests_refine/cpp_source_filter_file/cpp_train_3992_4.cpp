#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:16000000")
vector<int> edges[100001];
map<int, int> medges[100001];
vector<int> br[100001];
int bridges[5000][5000] = {0};
bool used[100001] = {0};
int tin[100001], fup[100001];
int timer = 0;
void dfs(int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = timer++;
  for (int i = 0; i < edges[v].size(); i++) {
    int to = edges[v][i];
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v]) {
        int vind = medges[to][v];
        br[v][i] = 1;
        br[to][vind] = 1;
      }
    }
  }
}
int dfs2(int a, int b) {
  if (a == b) return 0;
  used[a] = true;
  for (int i = 0; i < edges[a].size(); i++) {
    int next = edges[a][i];
    int t;
    if (!used[next] && (t = dfs2(next, b)) != -1) {
      if (bridges[next][a]) t++;
      return t;
    }
  }
  return -1;
}
int cnt = 0;
int color[100001] = {0};
void dfs3(int a) {
  color[a] = cnt;
  for (int i = 0; i < edges[a].size(); i++) {
    int next = edges[a][i];
    if (!color[next] && !br[a][i]) {
      dfs3(next);
    }
  }
}
vector<int> g[100001];
void build_tree_new(int n) {
  for (int i = 0; i < n; i++) {
    int from = color[i] - 1;
    for (int j = 0; j < edges[i].size(); j++) {
      if (br[i][j]) {
        int to = color[edges[i][j]] - 1;
        g[from].push_back(to);
        g[to].push_back(from);
      }
    }
  }
}
vector<int> lca_h, lca_dfs_list, lca_first, lca_tree;
vector<char> lca_dfs_used;
void lca_dfs(int v, int h = 1) {
  lca_dfs_used[v] = true;
  lca_h[v] = h;
  lca_dfs_list.push_back(v);
  for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); ++i)
    if (!lca_dfs_used[*i]) {
      lca_dfs(*i, h + 1);
      lca_dfs_list.push_back(v);
    }
}
void lca_build_tree(int i, int l, int r) {
  if (l == r)
    lca_tree[i] = lca_dfs_list[l];
  else {
    int m = (l + r) >> 1;
    lca_build_tree(i + i, l, m);
    lca_build_tree(i + i + 1, m + 1, r);
    if (lca_h[lca_tree[i + i]] < lca_h[lca_tree[i + i + 1]])
      lca_tree[i] = lca_tree[i + i];
    else
      lca_tree[i] = lca_tree[i + i + 1];
  }
}
void lca_prepare(int root, int n) {
  lca_h.resize(n);
  lca_dfs_list.reserve(n * 2);
  lca_dfs_used.assign(n, 0);
  lca_dfs(root);
  int m = (int)lca_dfs_list.size();
  lca_tree.assign(lca_dfs_list.size() * 4 + 1, -1);
  lca_build_tree(1, 0, m - 1);
  lca_first.assign(n, -1);
  for (int i = 0; i < m; ++i) {
    int v = lca_dfs_list[i];
    if (lca_first[v] == -1) lca_first[v] = i;
  }
}
int lca_tree_min(int i, int sl, int sr, int l, int r) {
  if (sl == l && sr == r) return lca_tree[i];
  int sm = (sl + sr) >> 1;
  if (r <= sm) return lca_tree_min(i + i, sl, sm, l, r);
  if (l > sm) return lca_tree_min(i + i + 1, sm + 1, sr, l, r);
  int ans1 = lca_tree_min(i + i, sl, sm, l, sm);
  int ans2 = lca_tree_min(i + i + 1, sm + 1, sr, sm + 1, r);
  return lca_h[ans1] < lca_h[ans2] ? ans1 : ans2;
}
int lca(int a, int b) {
  int left = lca_first[a], right = lca_first[b];
  if (left > right) swap(left, right);
  return lca_tree_min(1, 0, (int)lca_dfs_list.size() - 1, left, right);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    ai--;
    bi--;
    edges[ai].push_back(bi);
    edges[bi].push_back(ai);
    medges[bi][ai] = edges[ai].size() - 1;
    medges[ai][bi] = edges[bi].size() - 1;
    br[ai].push_back(0);
    br[bi].push_back(0);
  }
  timer = 0;
  for (int i = 0; i < n; ++i) used[i] = false;
  for (int i = 0; i < n; ++i)
    if (!used[i]) dfs(i);
  for (int i = 0; i < n; i++) {
    if (!color[i]) {
      cnt++;
      dfs3(i);
    }
  }
  build_tree_new(n);
  lca_prepare(1, n);
  int k;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    int ci, di;
    scanf("%d%d", &ci, &di);
    ci--;
    di--;
    if (color[ci] == color[di])
      cout << 0 << endl;
    else {
      int t1 = color[ci] - 1, t2 = color[di] - 1;
      int pr = lca(color[ci] - 1, color[di] - 1);
      cout << abs(lca_h[t1] - lca_h[pr]) + abs(lca_h[t2] - lca_h[pr]) << endl;
    }
  }
}
