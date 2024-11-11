#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
int parent[100005];
int color[100005];
int bycolor[100005];
int ds[100005];
int st = -1, en = -1;
int k;
void ini() {
  for (int i = 0; i < 100005; i++) {
    adj[i].clear();
    parent[i] = i;
    color[i] = -1;
    ds[i] = 0;
  }
}
void dfs(int u) {
  color[u] = 1;
  for (auto v : adj[u]) {
    if (color[v] == -1) {
      parent[v] = u;
      ds[v] = ds[u] + 1;
      int col = 1 - bycolor[u];
      bycolor[v] = 1 - bycolor[u];
      dfs(v);
    } else if (color[v] == 1 && parent[u] != v) {
      int dis = ds[u] - ds[v] + 1;
      bycolor[u] = 1 - bycolor[v];
      if (dis <= k) {
        st = u;
        en = v;
      }
    }
  }
  color[u] = 2;
}
int main() {
  int n, m;
  while (cin >> n >> m >> k) {
    ini();
    st = -1;
    en = -1;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1);
    if (st != -1) {
      vector<int> ans;
      for (int i = st; i != en; i = parent[i]) {
        ans.push_back(i);
      }
      ans.push_back(en);
      cout << "2\n" << ans.size() << "\n";
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
    } else {
      cout << "1\n";
      int cnt = 0;
      int need = k / 2 + k % 2;
      vector<int> ans;
      for (int i = 1; i <= n; i++) {
        if (bycolor[i] == 0) {
          ans.push_back(i);
        }
      }
      if (ans.size() >= need) {
        for (int i = 0; i < need; i++) {
          cout << ans[i] << " ";
        }
        cout << "\n";
      } else {
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
          if (bycolor[i] == 1) {
            ans.push_back(i);
          }
        }
        for (int i = 0; i < need; i++) {
          cout << ans[i] << " ";
        }
        cout << "\n";
      }
    }
  }
  return 0;
}
