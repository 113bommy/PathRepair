#include <bits/stdc++.h>
using namespace std;
const int mx = 1005;
int col[mx], cnt[mx];
bool mrk[mx];
vector<int> adj[mx];
int x;
void dfs(int v, int c) {
  mrk[v] = 1;
  col[v] = c;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    if (!mrk[u] && u != x) {
      dfs(u, c);
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n >> x;
    --x;
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      adj[v].push_back(u);
      adj[u].push_back(v);
    }
    if (adj[x].size() <= 1) {
      cout << "Ayush\n";
    } else {
      int k = 1;
      for (int i = 0; i < adj[x].size(); i++) {
        int u = adj[x][i];
        dfs(u, k);
        k++;
      }
      for (int i = 0; i < n; i++) {
        cnt[col[i]]++;
      }
      int o = 0;
      for (int i = 1; i < n; i++) {
        if (cnt[i] % 2 == 1) {
          o++;
        }
      }
      if (o % 2) {
        cout << "Ayush\n";
      } else {
        cout << "Ashish\n";
      }
    }
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      col[i] = 0;
      mrk[i] = 0;
      cnt[i] = 0;
    }
  }
}
