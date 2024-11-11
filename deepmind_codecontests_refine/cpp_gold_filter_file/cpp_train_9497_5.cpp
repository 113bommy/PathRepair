#include <bits/stdc++.h>
#pragma GCC optimizte("Ofast,fast-math,unroll-loops")
#pragma comment(linker, "/STACK:36777216")
using namespace std;
const int nax = 1005;
int used[nax];
int deg[nax];
int g[nax][nax];
int ask(int u, int v) {
  cout << "? " << u + 1 << ' ' << v + 1 << endl;
  int lca;
  cin >> lca;
  lca--;
  return lca;
}
void answer(int v) {
  cout << "! " << v + 1 << endl;
  exit(0);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  cout.setf(ios::fixed);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u][v] = 1;
    g[v][u] = 1;
    deg[u]++;
    deg[v]++;
  }
  set<int> leaf;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1) {
      used[i] = 1;
      leaf.insert(i);
    }
  }
  while (leaf.size() > 1) {
    int u = *leaf.begin();
    leaf.erase(u);
    int v = *leaf.begin();
    leaf.erase(v);
    int lca = ask(u, v);
    if (lca == u || lca == v) {
      answer(lca);
    }
    for (int i = 0; i < n; i++) {
      if (g[v][i]) {
        deg[v]--;
        deg[i]--;
        g[v][i] = 0;
        g[i][v] = 0;
      }
      if (g[u][i]) {
        deg[u]--;
        deg[i]--;
        g[u][i] = 0;
        g[i][u] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      if (deg[i] <= 1 && !used[i]) {
        used[i] = 1;
        leaf.insert(i);
      }
    }
  }
  answer(*leaf.begin());
  return 0;
}
