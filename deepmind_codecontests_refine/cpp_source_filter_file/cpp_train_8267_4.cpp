#include <bits/stdc++.h>
using namespace std;
void dfs(int v, vector<vector<int> > &g, vector<int> &u, vector<int> &c,
         vector<int> &p) {
  u[v] = 1;
  for (int i = 0; i < (g[v]).size(); ++i) {
    int to = g[v][i];
    if (!u[to]) {
      p[to] = v;
      dfs(to, g, u, c, p);
    }
  }
  bool f = 0;
  for (int i = 0; i < (g[v]).size(); ++i) {
    int to = g[v][i];
    if (u[to] == 1) continue;
    if (c[to] == 0 || p[to] != v) {
      if (!f) {
        cout << to + 1 << ' ' << v + 1 << ' ';
        f = 1;
      } else {
        cout << to + 1 << endl;
        f = 0;
      }
    } else {
      continue;
    }
  }
  if (f) {
    c[v] = 1;
    cout << p[v] + 1 << endl;
  }
  u[v] = 2;
}
int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);
  if (m % 2 == 0) {
    cout << "No solution";
    return 0;
  }
  vector<vector<int> > g(n);
  vector<int> u(n), c(n), p(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d\n", &x, &y);
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0, g, u, c, p);
  return 0;
}
