#include <bits/stdc++.h>
using namespace std;
int vis[300005], low[300005], h[300005], x[300005], y[300005], z[300005],
    mark[300005], e[300005], vis2[300005];
vector<pair<int, int> > a[300005];
vector<int> out[300005];
vector<pair<int, int> > b[300005];
int bcmp1;
bool bl = false;
void dfs1(int i, int p) {
  vis[i] = 1;
  low[i] = h[i];
  for (int j = 0; j < a[i].size(); j++) {
    if (vis[a[i][j].first] == 0) {
      h[a[i][j].first] = h[i] + 1;
      dfs1(a[i][j].first, i);
      low[i] = min(low[i], low[a[i][j].first]);
      if (low[a[i][j].first] > h[i]) {
        e[a[i][j].second] = 1;
      }
    } else if (a[i][j].first != p)
      low[i] = min(low[i], low[a[i][j].first]);
  }
}
void dfs2(int i) {
  vis[i] = bcmp1;
  for (int j = 0; j < a[i].size(); j++) {
    if (e[a[i][j].second] == 1) {
      out[bcmp1].push_back(a[i][j].second);
    } else {
      if (z[a[i][j].second] = 1) mark[bcmp1] = 1;
      if (vis[a[i][j].first] == 0) {
        dfs2(a[i][j].first);
      }
    }
  }
}
void dfs3(int i, int j, int u) {
  u = max(u, mark[i]);
  vis2[i] = 1;
  if (i == j) {
    if (u == 1) bl = true;
    return;
  }
  for (int k = 0; k < b[i].size(); k++) {
    if (vis2[b[i][k].first] == 0)
      dfs3(b[i][k].first, j, max(u, b[i][k].second));
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i] >> z[i];
    a[x[i]].push_back(make_pair(y[i], i));
    a[y[i]].push_back(make_pair(x[i], i));
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      dfs1(i, 0);
    }
  }
  bcmp1 = 0;
  for (int i = 1; i <= n; i++) vis[i] = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      bcmp1++;
      dfs2(i);
    }
  }
  for (int i = 1; i <= bcmp1; i++) {
    for (int j = 0; j < out[i].size(); j++) {
      if (vis[x[out[i][j]]] != i) {
        b[i].push_back(make_pair(vis[x[out[i][j]]], z[out[i][j]]));
      } else {
        b[i].push_back(make_pair(vis[y[out[i][j]]], z[out[i][j]]));
      }
    }
  }
  int x1, y1;
  cin >> x1 >> y1;
  dfs3(vis[x1], vis[y1], 0);
  if (bl)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
