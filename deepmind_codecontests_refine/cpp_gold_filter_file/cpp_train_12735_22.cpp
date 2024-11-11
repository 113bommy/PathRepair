#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 1e3;
const int LOG = 20;
vector<pair<int, int> > al[maxN];
int h[maxN];
int par[maxN][LOG];
int plc[maxN], dep[maxN], place[maxN];
set<int> white[maxN];
int root = 0, Max = 0;
void dfs(int v, int p) {
  if (p + 1) h[v] = h[p] + 1;
  par[v][0] = p;
  int cur = p;
  for (int i = 1; i < LOG; i++) {
    if (cur != -1) cur = par[cur][i - 1];
    par[v][i] = cur;
  }
  int tmp = 0;
  for (int i = 0; i < al[v].size(); i++)
    if (al[v][i].first == p) tmp = plc[al[v][i].second];
  for (int i = 0; i < al[v].size(); i++) {
    int u = al[v][i].first, ednum = al[v][i].second;
    if (u == p) continue;
    dep[ednum] = h[v];
    if (root == v)
      plc[ednum] = i, place[u] = i;
    else
      plc[ednum] = tmp, place[u] = tmp;
    dfs(u, v);
  }
  return;
}
int LCA(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int i = LOG - 1; i + 1; i--)
    if ((h[u] - h[v]) & (1 << i)) u = par[u][i];
  if (u == v) return v;
  for (int i = LOG - 1; i + 1; --i)
    if (par[v][i] != par[u][i]) v = par[v][i], u = par[u][i];
  v = par[v][0];
  return v;
}
int ans(int u, int v) {
  int anc = LCA(u, v);
  int get = h[u] + h[v] - 2 * h[anc];
  if (anc != u && anc != v && v != root && u != root) {
    if (ans(u, root) < 0 || ans(v, root) < 0) return -2 * maxN;
    return get;
  }
  int p = place[u];
  if ((white[p].lower_bound(min(h[u], h[v]))) != white[p].end() &&
      *(white[p].lower_bound(min(h[u], h[v]))) <= max(h[v], h[u]) - 1) {
    return -maxN * 2;
  }
  return get;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    al[--u].push_back(make_pair(--v, i));
    al[v].push_back(make_pair(u, i));
  }
  for (int i = 0; i < n; i++) {
    if (al[i].size() > Max) Max = al[i].size(), root = i;
  }
  dfs(root, -1);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    if (t == 3) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u, --v;
      if (place[u] < place[v]) swap(u, v);
      int tmp = ans(u, v);
      if (tmp < 0) {
        printf("-1\n");
        continue;
      }
      printf("%d\n", tmp);
      continue;
    }
    int x;
    scanf("%d", &x);
    --x;
    if (t == 2)
      white[plc[x]].insert(dep[x]);
    else
      white[plc[x]].erase(dep[x]);
  }
}
