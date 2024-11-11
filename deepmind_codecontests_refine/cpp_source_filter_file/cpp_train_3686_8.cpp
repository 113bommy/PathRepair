#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
vector<set<int> > gr;
vector<int> para, ht;
int maxad;
int l;
int timw, timi[200005], timo[200005];
int up[200005][20];
void lcaini(int n) {
  gr = vector<set<int> >(n + 1);
  para = vector<int>(n + 1);
  ht = vector<int>(n + 1);
  timw = 0;
  l = 20;
}
int dfsr(int u, int par, int dep) {
  timi[u] = timw++;
  para[u] = par;
  ht[u] = dep;
  int ko = dep + 1;
  up[u][0] = par;
  for (int i = 1; i <= l; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  maxad = max(maxad, dep);
  for (auto x : gr[u]) {
    if (x == par) continue;
    dfsr(x, u, ko);
  }
  timo[u] = timw++;
  return 0;
}
bool is_ancestor(int u, int v) {
  return timi[u] <= timi[v] && timo[u] >= timo[v];
}
int lca(int a, int b) {
  if (ht[a] > ht[b]) swap(a, b);
  int d = ht[b] - ht[a];
  for (int i = 0; i < l; i++)
    if (d & (1 << i)) b = up[b][i];
  if (a == b) return a;
  for (int i = l - 1; i >= 0; i--)
    if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
  return up[a][0];
}
int lcdist(int u, int v) { return ht[u] + ht[v] - 2 * ht[lca(u, v)]; }
int nn;
int cpar[200005], sub[200005];
void cdfs1(int u, int p) {
  sub[u] = 1;
  nn++;
  for (auto it : gr[u]) {
    if (it != p) {
      cdfs1(it, u);
      sub[u] += sub[it];
    }
  }
}
int cdfs2(int u, int p) {
  for (auto it : gr[u])
    if (it != p && sub[it] > nn / 2) return cdfs2(it, u);
  return u;
}
void decompose(int root, int p) {
  nn = 0;
  cdfs1(root, root);
  int centroid = cdfs2(root, root);
  if (p == -1) p = centroid;
  cpar[centroid] = p;
  for (auto it : gr[centroid]) {
    gr[it].erase(centroid);
    decompose(it, centroid);
  }
  gr[centroid].clear();
}
int ans[200005];
void update(int u) {
  int x = u;
  ans[x] = 0;
  while (x != cpar[x]) {
    x = cpar[x];
    ans[x] = min(ans[x], lcdist(x, u));
  }
}
void query(int u) {
  int ansa = ans[u];
  int x = u;
  while (x != cpar[x]) {
    x = cpar[x];
    ansa = min(ansa, ans[x] + lcdist(x, u));
  }
  cout << ansa << "\n";
}
int main() {
  int n, m;
  cin >> n >> m;
  lcaini(n + 1);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    gr[x].insert(y);
    gr[y].insert(x);
  }
  dfsr(1, 1, 3);
  decompose(1, -1);
  for (int i = 1; i <= n; i++) ans[i] = INF;
  update(1);
  while (m--) {
    int x, y;
    cin >> x >> y;
    switch (x) {
      case 1:
        update(y);
        break;
      case 2:
        query(y);
        break;
    }
  }
}
