#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int viz;
  int cap;
  int idx;
  Edge() {}
  Edge(int viz, int cap, int idx) : viz(viz), cap(cap), idx(idx) {}
};
const int MAXN = (int)1e5 + 5;
int f[MAXN];
int ans[MAXN];
vector<Edge> g[MAXN];
int main(void) {
  int n, m;
  int a, b, c;
  queue<int> fila;
  scanf(" %d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf(" %d %d %d", &a, &b, &c);
    f[a] += c;
    f[b] += c;
    g[a].push_back(Edge(b, c, i));
    g[b].push_back(Edge(a, c, -i));
    ans[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    f[i] /= 2;
  }
  fila.push(1);
  while (!fila.empty()) {
    int next = fila.front();
    fila.pop();
    for (int i = 0; i < (int)g[next].size(); i++) {
      int viz = g[next][i].viz;
      int idx = g[next][i].idx;
      int cap = g[next][i].cap;
      if (ans[abs(idx)] == -1) {
        ans[abs(idx)] = idx < 0 ? 1 : 0;
        f[viz] -= cap;
        if (f[viz] == 0 && viz != n) {
          fila.push(viz);
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
