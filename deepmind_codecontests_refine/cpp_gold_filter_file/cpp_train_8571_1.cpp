#include <bits/stdc++.h>
using namespace std;
vector<int> lev, E;
vector<int> g[100100], ind[100100];
int sparse_table[100100 * 3][20];
int lg[100100 * 3];
int mp[100100];
int t[100100], l[100100], s[100100];
void build_sparse_table(int n) {
  lg[0] = -1;
  for (int i = 0; i <= n; ++i)
    sparse_table[i][0] = i, lg[i + 1] = lg[i] + !(i & (i + 1));
  for (int j = 1; (1 << j) <= n; ++j)
    for (int i = 0; i + (1 << j) <= n; ++i) {
      int x = sparse_table[i][j - 1];
      int y = sparse_table[i + (1 << (j - 1))][j - 1];
      sparse_table[i][j] = lev[x] < lev[y] ? x : y;
    }
}
int getMin_sparse_table(int l, int r) {
  if (r < l) swap(l, r);
  int s = lg[r - l + 1];
  int x = sparse_table[l][s];
  int y = sparse_table[r + 1 - (1 << s)][s];
  return lev[x] < lev[y] ? x : y;
}
void dfs(int e, int p, int l) {
  E.push_back(e), lev.push_back(l);
  if (!mp[e]) mp[e] = lev.size();
  for (int i : g[e])
    if (i != p) {
      dfs(i, e, l + 1);
      lev.push_back(l);
      E.push_back(e);
    }
}
int LCA(int u, int v) { return E[getMin_sparse_table(mp[u] - 1, mp[v] - 1)]; }
int solve(int u, int p) {
  int y = l[u] - t[u];
  for (int j = 0; j < g[u].size(); ++j) {
    int v = g[u][j];
    if (v != p) {
      y += s[ind[u][j]] = solve(v, u);
    }
  }
  return y;
}
int main() {
  int n, k, x, y;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
    ind[x].push_back(i);
    ind[y].push_back(i);
  }
  dfs(1, 0, 0);
  build_sparse_table(lev.size());
  cin >> k;
  while (k--) {
    scanf("%d%d", &x, &y);
    t[LCA(x, y)] += 2;
    l[x]++, l[y]++;
  }
  solve(1, 0);
  for (int i = 1; i < n; ++i) cout << s[i] << " ";
}
