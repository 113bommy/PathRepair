#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
const int MAXM = 1e4 + 10;
struct node {
  int u, v, w;
};
int T, n, m, h[MAXN], a[MAXM], ans[MAXM];
vector<node> edge;
vector<int> g[MAXN][2];
bool visited[MAXN][2];
node MN(int u, int v, int w) {
  node res;
  res.u = u;
  res.v = v;
  res.w = w;
  return res;
}
void dfs(int v, int c) {
  visited[v][c] = true;
  for (auto e : g[v][c]) {
    int u = a[e] ^ v;
    if (!visited[u][c]) {
      dfs(u, c);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int u, v;
      cin >> u >> v;
      a[i] = u ^ v;
      g[u][0].push_back(i);
      g[v][1].push_back(i);
    }
    dfs(1, 0);
    dfs(n, 1);
    for (int i = 1; i <= n; i++) {
      if (visited[i][0]) {
        for (auto e : g[i][0]) {
          int j = a[e] ^ i;
          if (visited[j][1]) {
            edge.push_back(MN(i, j, 2));
            edge.push_back(MN(j, i, -1));
          }
        }
      }
    }
    memset(h, 127, sizeof h);
    h[1] = 0;
    for (int i = 1; i <= n; i++) {
      for (auto e : edge) {
        if (i == n && h[e.u] + e.w < h[e.v]) {
          cout << "No";
          return 0;
        }
        h[e.v] = min(h[e.v], h[e.u] + e.w);
      }
    }
    cout << "Yes" << '\n';
    for (int i = 1; i <= n; i++) {
      for (auto e : g[i][0]) {
        int j = a[e] ^ i;
        if (h[i] + 1 == h[j]) {
          ans[e] = 1;
        } else {
          ans[e] = 2;
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      cout << ans[i] << '\n';
    }
  }
  return 0;
}
