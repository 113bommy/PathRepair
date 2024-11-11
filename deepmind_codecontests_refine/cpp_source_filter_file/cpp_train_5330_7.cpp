#include <bits/stdc++.h>
using namespace std;
vector<int> odr, cmp;
vector<bool> vis;
void dfs1(int v, vector<vector<int> > &g1) {
  vis[v] = true;
  for (int i = 0; i < g1[v].size(); i++) {
    if (!vis[g1[v][i]]) dfs1(g1[v][i], g1);
  }
  odr.push_back(v);
}
void dfs2(int v, vector<vector<int> > &g2) {
  vis[v] = true;
  cmp.push_back(v);
  for (int i = 0; i < g2[v].size(); i++) {
    if (!vis[g2[v][i]]) dfs2(g2[v][i], g2);
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<vector<int> > g1(n), g2(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a == b) continue;
    g1[a].push_back(b);
    g2[b].push_back(a);
  }
  odr.clear();
  cmp.clear();
  vis.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs1(i, g1);
  }
  vis.assign(n, false);
  set<int> ss;
  set<int> s;
  bool b = true;
  int k = 0;
  for (int i = 0; i < n; i++) {
    int v = odr[n - 1 - i];
    if (!vis[v]) {
      dfs2(v, g2);
      if (b) {
        for (int j = 0; j < cmp.size(); j++) ss.insert(cmp[j] + 1);
        b = false;
      } else {
        k = 1;
        for (int j = 0; j < cmp.size(); j++) s.insert(cmp[j] + 1);
      }
      cmp.clear();
    }
  }
  if (k == 0) {
    cout << "NO\n";
  } else {
    cout << "YES\n" << ss.size() << " " << s.size() << "\n";
    set<int>::iterator it;
    for (it = ss.begin(); it != ss.end(); it++) {
      cout << *it << " ";
    }
    cout << "\n";
    for (it = s.begin(); it != s.end(); it++) {
      cout << *it << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
