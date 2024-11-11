#include <bits/stdc++.h>
using namespace std;
int n;
int Neg(int x) { return x + n; }
vector<int> G[1000], GI[1000];
int scc[1000], cc;
bool check[1000];
vector<int> order;
void dfs1(int x) {
  check[x] = 1;
  for (int i = 0; i < (int)G[x].size(); i++)
    if (!check[G[x][i]]) dfs1(G[x][i]);
  order.push_back(x);
}
void dfs2(int x) {
  scc[x] = cc;
  for (int i = 0; i < (int)GI[x].size(); i++)
    if (!scc[GI[x][i]]) dfs2(GI[x][i]);
}
int x, y, e, m;
int main() {
  cc = 1;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &x, &y, &e);
    if (e) {
      G[Neg(y)].push_back(Neg(x));
      G[x].push_back(y);
      G[Neg(x)].push_back(Neg(y));
      G[y].push_back(x);
      GI[Neg(x)].push_back(Neg(y));
      GI[y].push_back(x);
      GI[Neg(y)].push_back(Neg(x));
      GI[x].push_back(y);
    } else {
      G[Neg(y)].push_back(x);
      G[Neg(x)].push_back(y);
      G[x].push_back(Neg(y));
      G[y].push_back(Neg(x));
      GI[x].push_back(Neg(y));
      GI[y].push_back(Neg(x));
      GI[Neg(y)].push_back(x);
      GI[Neg(x)].push_back(y);
    }
  }
  for (int i = 1; i <= n; i++)
    if (!check[i]) dfs1(i);
  for (int i = order.size() - 1; i >= 0; i--)
    if (!scc[order[i]]) {
      dfs2(order[i]);
      cc++;
    }
  bool ok = true;
  int cant = 0;
  for (int i = 1; i <= n; i++) {
    if (scc[i] == scc[Neg(i)]) ok = false;
    if (scc[i] < scc[Neg(i)]) cant++;
  }
  if (ok) {
    printf("%d\n", cant);
    for (int i = 1; i <= n; i++)
      if (scc[i] < scc[Neg(i)]) printf("%d ", i);
  } else
    printf("Impossible\n");
  return 0;
}
