#include <bits/stdc++.h>
using namespace std;
int vis[100005], n, m, x, y, mi, eg, re;
char t;
vector<vector<pair<int, int> > > adj;
vector<vector<int> > re1;
vector<int> t0, t1;
void dfs(int u, int ty) {
  if (vis[u] == -1) {
    vis[u] = ty;
    if (ty == 0)
      t0.push_back(u);
    else
      t1.push_back(u);
    for (int j = 0; j < adj[u].size(); j++) {
      pair<int, int> te = adj[u][j];
      if (te.second == eg)
        dfs(te.first, ty);
      else
        dfs(te.first, 1 - ty);
    }
  } else if (vis[u] != ty) {
    mi = -1;
    return;
  }
}
int main() {
  cin >> n >> m;
  adj.assign(n + 1, vector<pair<int, int> >(0));
  re1.assign(2, vector<int>(0));
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> t;
    adj[x].push_back(pair<int, int>(y, t == 'B'));
    adj[y].push_back(pair<int, int>(x, t == 'B'));
  }
  memset(vis, -1, sizeof(vis));
  mi = 0;
  eg = 1;
  for (int i = 1; i <= n; i++) {
    t0.clear();
    t1.clear();
    if (vis[i] == -1) dfs(i, 0);
    if (mi == -1) break;
    if (t0.size() < t1.size()) {
      mi += t0.size();
      for (int j = 0; j < t0.size(); j++) re1[0].push_back(t0[j]);
    } else {
      mi += t1.size();
      for (int j = 0; j < t1.size(); j++) re1[0].push_back(t1[j]);
    }
  }
  re = mi;
  memset(vis, -1, sizeof(vis));
  mi = 0;
  eg = 0;
  for (int i = 1; i <= n; i++) {
    t0.clear();
    t1.clear();
    if (vis[i] == -1) dfs(i, 0);
    if (mi == -1) break;
    if (t0.size() < t1.size()) {
      mi += t0.size();
      for (int j = 0; j < t0.size(); j++) re1[1].push_back(t0[j]);
    } else {
      mi += t1.size();
      for (int j = 0; j < t1.size(); j++) re1[1].push_back(t1[j]);
    }
  }
  if (mi == -1) {
    if (re == -1)
      cout << -1 << endl;
    else {
      cout << re << endl;
      for (int i = 0; i < re1[0].size(); i++) cout << re1[0][i] << " ";
      cout << endl;
    }
  } else if (re == -1) {
    cout << mi << endl;
    for (int i = 0; i < re1[1].size(); i++) cout << re1[1][i] << " ";
    cout << endl;
  } else {
    if (mi < re) {
      cout << mi << endl;
      for (int i = 0; i < re1[1].size(); i++) cout << re1[1][i] << " ";
      cout << endl;
    } else {
      cout << re << endl;
      for (int i = 0; i < re1[0].size(); i++) cout << re1[0][i] << " ";
      cout << endl;
    }
  }
  return 0;
}
