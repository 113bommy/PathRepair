#include <bits/stdc++.h>
using namespace std;
const int N = 1e5, LOG = 20;
int n, q, p[N], cnt[N], pp[LOG][N], lvl[N];
vector<int> adj[N];
bool visit[N];
void dfs(int ii, int pii) {
  visit[ii] = 1;
  p[ii] = pii;
  for (int i = 0; i < adj[ii].size(); ++i) {
    if (!visit[adj[ii][i]]) dfs(adj[ii][i], ii);
  }
  return;
}
void dfs0(int ii) {
  cnt[ii] = 1;
  visit[ii] = 1;
  for (int i = 0; i < adj[ii].size(); ++i) {
    dfs0(adj[ii][i]);
    cnt[ii] += cnt[adj[ii][i]];
  }
  return;
}
void dfs1(int ii, int l) {
  visit[ii] = 1;
  lvl[ii] = l;
  for (int i = 0; i < adj[ii].size(); ++i) {
    dfs1(adj[ii][i], l + 1);
  }
  return;
}
int lca(int ii, int jj) {
  if (lvl[ii] > lvl[jj]) swap(ii, jj);
  for (int i = LOG - 1; i >= 0; i--) {
    if (lvl[pp[i][jj]] < lvl[ii]) continue;
    jj = pp[i][jj];
  }
  if (ii == jj) return ii;
  for (int i = LOG - 1; i >= 0; --i) {
    if (pp[i][ii] != pp[i][jj]) ii = pp[i][ii], jj = pp[i][jj];
  }
  return pp[0][ii];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  for (int i = 0; i < n; ++i) {
    adj[i].clear();
    visit[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    if (p[i] != -1) {
      adj[p[i]].push_back(i);
    }
  }
  dfs0(0);
  for (int i = 0; i < n; ++i) {
    pp[0][i] = p[i];
  }
  for (int i = 1; i < LOG; ++i) {
    for (int j = 0; j < n; ++j) {
      int temp = pp[i - 1][pp[i - 1][j]];
      pp[i][j] = (temp != -1 ? temp : pp[i - 1][j]);
    }
  }
  for (int i = 0; i < n; ++i) visit[i] = 0;
  dfs1(0, 0);
  cin >> q;
  while (q--) {
    int w, u, v;
    cin >> u >> v;
    u--, v--;
    if (u == v) {
      cout << n << "\n";
      continue;
    }
    w = lca(u, v);
    if (lvl[u] > lvl[v]) swap(u, v);
    if (lvl[u] == lvl[v]) {
      for (int i = LOG - 1; i >= 0; i--) {
        if (lvl[pp[i][u]] > lvl[w]) u = pp[i][u];
        if (lvl[pp[i][v]] > lvl[w]) v = pp[i][v];
      }
      cout << n - (cnt[u] + cnt[v]) << "\n";
    } else {
      int sz = lvl[v] + lvl[u] - 2 * lvl[w];
      if (sz & 1) {
        cout << "0\n";
      } else {
        sz /= 2;
        for (int i = LOG - 1; i >= 0; i--) {
          if ((1 << i) < sz) {
            sz -= (1 << i);
            v = pp[i][v];
          }
        }
        cout << cnt[pp[0][v]] - cnt[v] << "\n";
      }
    }
  }
  return 0;
}
