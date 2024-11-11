#include <bits/stdc++.h>
using namespace std;
int n, m, q, X, Y, dis, node, P, f[300010];
int comp[300010];
vector<int> adj[300010];
int find_parent(int z) {
  if (z == f[z]) return z;
  return (f[z] = find_parent(f[z]));
}
void Connect(int x, int y) {
  int par1 = find_parent(x), par2 = find_parent(y);
  if (par1 == par2) return;
  f[par2] = par1;
  comp[par1] = max(max(comp[par1], comp[par2]),
                   ((comp[par1] + 1) / 2) + ((comp[par2] + 1) / 2) + 1);
}
void DFS(int d, int x, int prv) {
  f[d] = P;
  if (d > dis) dis = d, node = x;
  for (int i = 0; i < adj[x].size(); i++)
    if (prv != adj[x][i]) DFS(d + 1, adj[x][i], x);
}
void First() {
  for (int i = 1; i <= n; i++) {
    if (f[i] != i) continue;
    P = i, dis = 0, node = 0;
    DFS(0, i, -1);
    DFS(0, node, -1);
    comp[i] = dis;
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &X, &Y);
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  First();
  for (int i = 0; i < q; i++) {
    int a, b, type;
    scanf("%d %d", &type, &a);
    if (type == 1)
      printf("%d\n", comp[find_parent(a)]);
    else {
      scanf("%d", &b);
      Connect(a, b);
    }
  }
  return 0;
}
