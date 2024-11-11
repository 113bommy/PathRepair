#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<long long> c, u, num;
vector<set<int> > G;
int h(int col) {
  vector<set<int> > g = G;
  set<int> se[3];
  for (int v = 0; v < n; ++v)
    if (g[v].size() == 1) se[c[v]].insert(v);
  int res = 0;
  int N = n;
  for (; N; ++res) {
    for (bool go = true; go;) {
      for (int co = 0; co < 3; ++co) {
        if (co == col) continue;
        if (se[co].empty()) continue;
        int v = *se[co].begin();
        se[co].erase(v);
        --N;
        int w = *g[v].begin();
        g[v].erase(w);
        g[w].erase(v);
        if (g[w].size() == 1) se[c[w]].insert(w);
        if (g[w].size() == 0) {
          se[c[w]].erase(w);
          --N;
          res += (c[w] == col);
        }
      }
      go = false;
      for (int co = 0; co < 3; ++co)
        if (co != col && se[co].size() > 0) go = true;
    }
    col = 3 - col;
  }
  return res;
}
int f() {
  cin >> n;
  c.resize(n);
  num.assign(3, 0);
  for (auto& x : c) {
    cin >> x;
    ++num[x];
  }
  G.clear();
  G.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].insert(b);
    G[b].insert(a);
  }
  if (!num[1] || !num[2]) return 1;
  return min(h(1), h(2));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << f() << "\n";
  return 0;
}
