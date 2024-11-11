#include <bits/stdc++.h>
using namespace std;
int st[100100][20];
vector<int> graph[100100], ind[100100];
int lev[100100];
int t[100100], l[100100], lg[100100];
int s[100100];
void blg(int n) {
  lg[0] = -1;
  for (int i = 0; i < n; ++i) lg[i + 1] = lg[i] + !(i & (i + 1));
}
void dfs(int u, int p, int l) {
  st[u][0] = p;
  for (int i = 1; (1 << i) <= l; ++i) st[u][i] = st[st[u][i - 1]][i - 1];
  lev[u] = l;
  for (int v : graph[u])
    if (v != p) dfs(v, u, l + 1);
}
int getParent(int u, int d) {
  if (lev[u] < d) return -1;
  for (int i = d; i; i -= i & -i) u = st[u][lg[i & -i]];
  return u;
}
int LCA(int u, int v) {
  if (lev[u] < lev[v]) v = getParent(v, lev[v] - lev[u]);
  if (lev[u] > lev[v]) u = getParent(u, lev[u] - lev[v]);
  if (u == v) return u;
  int l = lg[lev[u]];
  for (int i = l; i >= 0; i--) {
    if (st[u][i] != st[v][i]) u = st[u][i], v = st[u][i];
  }
  return st[u][0];
}
int solve(int u, int p) {
  int y = l[u] - t[u];
  for (int j = 0; j < graph[u].size(); ++j) {
    int v = graph[u][j];
    if (v != p) {
      y += s[ind[u][j]] = solve(v, u);
    }
  }
  return y;
}
int main() {
  int n, k, x, y;
  cin >> n;
  blg(n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    graph[x].push_back(y), graph[y].push_back(x);
    ind[x].push_back(i);
    ind[y].push_back(i);
  }
  dfs(1, 1, 0);
  cin >> k;
  while (k--) {
    scanf("%d%d", &x, &y);
    t[LCA(x, y)] += 2;
    l[x]++, l[y]++;
  }
  solve(1, 0);
  for (int i = 1; i < n; ++i) cout << s[i] << " ";
}
