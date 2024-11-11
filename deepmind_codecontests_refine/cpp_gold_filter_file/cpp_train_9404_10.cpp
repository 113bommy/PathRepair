#include <bits/stdc++.h>
using namespace std;
long long num[100050], low[100050], tinh = 0, n, m, u, v, dem, c[100050],
                                    d[100050], lab[100050], h[100050],
                                    pr[100050][30], k;
vector<int> a[100050], b[100050];
map<pair<int, int>, int> mp;
pair<int, int> pp[100050];
void visit(int u, int p) {
  num[u] = low[u] = ++tinh;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v != p) {
      if (num[v] != 0) {
        low[u] = min(low[u], num[v]);
      } else {
        visit(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] >= num[v]) {
          mp[pair<int, int>(u, v)] = mp[pair<int, int>(v, u)] = 1;
        }
      }
    }
  }
}
void dfs(int x) {
  d[x] = 1;
  for (int i = 0; i < a[x].size(); i++) {
    int v = a[x][i];
    if (d[v] == 0 && mp[pair<int, int>(x, v)] == 0) {
      c[v] = dem;
      dfs(v);
    }
  }
}
int tim(int x) {
  if (lab[x] < 0)
    return x;
  else
    return lab[x] = tim(lab[x]);
}
void ghep(int x, int y) {
  lab[x] = lab[x] + lab[y];
  lab[y] = x;
}
void dfs1(int x) {
  d[x] = 1;
  for (int i = 0; i < b[x].size(); i++) {
    int v = b[x][i];
    if (d[v] == 0) {
      h[v] = h[x] + 1;
      pr[v][0] = x;
      dfs1(v);
    }
  }
}
void khoitao() {
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i <= dem; i++) {
      pr[i][j] = pr[pr[i][j - 1]][j - 1];
    }
  }
}
int lca(int x, int y) {
  if (h[x] < h[y]) swap(x, y);
  for (int i = 20; i >= 0; i--) {
    if (h[pr[x][i]] >= h[y]) x = pr[x][i];
  }
  if (x == y) return x;
  for (int i = 20; i >= 0; i--) {
    if (pr[x][i] != pr[y][i]) {
      x = pr[x][i];
      y = pr[y][i];
    }
  }
  return pr[x][0];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
    pp[i].first = u;
    pp[i].second = v;
  }
  for (int i = 1; i <= n; i++) {
    if (num[i] == 0) visit(i, i);
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0) {
      dem++;
      c[i] = dem;
      dfs(i);
    }
  }
  for (int i = 1; i <= dem; i++) {
    lab[i] = -1;
  }
  for (int i = 1; i <= m; i++) {
    if (mp[pair<int, int>(pp[i].first, pp[i].second)] == 1) {
      int x = tim(c[pp[i].first]);
      int y = tim(c[pp[i].second]);
      if (x != y) {
        ghep(x, y);
        b[c[pp[i].first]].push_back(c[pp[i].second]);
        b[c[pp[i].second]].push_back(c[pp[i].first]);
      }
    }
  }
  h[1] = 1;
  memset(d, 0, sizeof(d));
  dfs1(1);
  khoitao();
  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> u >> v;
    if (lca(c[u], c[v]) != c[u] && lca(c[u], c[v]) != c[v]) {
      cout << abs(2 * h[lca(c[u], c[v])] - h[c[u]] - h[c[v]]) << "\n";
    } else
      cout << abs(h[c[u]] - h[c[v]]) << "\n";
  }
}
