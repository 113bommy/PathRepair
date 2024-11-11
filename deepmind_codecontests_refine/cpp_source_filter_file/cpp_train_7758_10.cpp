#include <bits/stdc++.h>
using namespace std;
const int maxN = 342;
const long double E = 1e-12;
struct Max_flow {
  vector<int>* G;
  int source, target, bfsctr, parent[maxN], vis[maxN];
  long long* cap[maxN];
  int Q[maxN];
  bool bfs() {
    int qfront = 0, qback = 0;
    vis[source] = ++bfsctr;
    Q[qback++] = source;
    while (qfront != qback) {
      int v = Q[qfront++];
      for (int u : G[v]) {
        if (vis[u] == bfsctr or cap[v][u] <= 0) continue;
        vis[u] = bfsctr;
        parent[u] = v;
        Q[qback++] = u;
        if (u == target) {
          qfront = qback;
          break;
        }
      }
    }
    return vis[target] == bfsctr;
  }
  long long max_flow(vector<int>* Gin, long long Cin[maxN][maxN], int n,
                     int src, int trg) {
    G = Gin;
    source = src;
    target = trg;
    for (int i = 0; i < (n + 1); i++) cap[i] = &Cin[i][0];
    long long res = 0;
    while (bfs()) {
      long long mc = 1e15;
      for (int v = target; v != source; v = parent[v])
        mc = min(mc, cap[parent[v]][v]);
      for (int v = target; v != source; v = parent[v]) {
        cap[parent[v]][v] -= mc;
        cap[v][parent[v]] += mc;
      }
      res += mc;
    }
    return res;
  }
} alg;
long long c0[maxN][maxN], cap[maxN][maxN];
vector<int> G[maxN];
int main() {
  int n, m, x;
  scanf("%d%d%d", &n, &m, &x);
  int num = n;
  while (m--) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (c0[b][a] != 0) {
      num++;
      G[b].push_back(num);
      G[a].push_back(num);
      G[num].push_back(a);
      G[num].push_back(a);
      c0[a][num] = c0[num][b] = c;
    } else {
      G[a].push_back(b);
      G[b].push_back(a);
      c0[a][b] = c;
    }
  }
  long double bn = 0, ed = 1000042;
  while (ed - bn > E) {
    long double w = (bn + ed) / 2;
    for (int i = 1; i < (n + 1); i++)
      for (int j = 1; j < (n + 1); j++) cap[i][j] = c0[i][j] / w;
    alg.max_flow(G, cap, num, 1, n) >= x ? bn = w : ed = w;
  }
  printf("%.18Lf\n", bn * x);
  return 0;
}
