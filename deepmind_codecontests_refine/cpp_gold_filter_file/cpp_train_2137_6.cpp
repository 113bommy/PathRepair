#include <bits/stdc++.h>
using namespace std;
int n, m, ed[2005];
set<int> g[105], gg[105];
void dfs(int v, vector<int> &cir) {
  while (!g[v].empty()) {
    int u = *g[v].begin();
    g[v].erase(u);
    g[u].erase(v);
    dfs(u, cir);
  }
  cir.push_back(v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(32);
  cin >> n >> m;
  for (int i = 0; i <= m; i++) {
    cin >> ed[i];
  }
  for (int i = 1; i <= m; i++) {
    gg[ed[i]].insert(ed[i - 1]);
    gg[ed[i - 1]].insert(ed[i]);
  }
  for (int len = m - 1; len >= 0; len--) {
    int vert = ed[len];
    set<int> st = gg[vert];
    for (int i = 1; i <= len; i++) {
      if (ed[i] == vert) {
        st.erase(ed[i - 1]);
      }
      if (ed[i - 1] == vert) {
        st.erase(ed[i]);
      }
    }
    for (int nxt : st) {
      if (nxt > ed[len + 1]) {
        for (int i = len + 1; i <= m; i++) {
          g[ed[i]].insert(ed[i - 1]);
          g[ed[i - 1]].insert(ed[i]);
        }
        g[nxt].erase(vert);
        g[vert].erase(nxt);
        vector<int> cir;
        dfs(nxt, cir);
        bool flg = true;
        for (int i = 1; i <= n; i++) {
          if (!g[i].empty()) {
            g[i].clear();
            flg = false;
          }
        }
        if (flg) {
          for (int i = 0; i <= len; i++) {
            cout << ed[i] << " ";
          }
          while (!cir.empty()) {
            cout << cir.back() << " ";
            cir.pop_back();
          }
          exit(0);
        }
      }
    }
  }
  cout << "No solution";
  return 0;
}
