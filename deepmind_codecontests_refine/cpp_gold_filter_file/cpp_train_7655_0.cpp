#include <bits/stdc++.h>
using namespace std;
const int C = 200001, D = 700;
vector<vector<int> > tab(C);
int ij[C], a, b, n, i, j, last = 1;
int s[C], is = 0, ip = 1, pre[C], dep[C], son[C], par[C], ji[C], x, alen = 0;
int e[2][22][2 * C], si = 0, fa[C], pl2[2 * C];
void proc_tree(int a, int n) {
  s[0] = a, is = 1, pre[a] = 1, dep[a] = 1, ip = 2;
  int b;
  for (int z = 1; z <= n; z++) ji[z] = ij[z], fa[z] = -1;
  while (is > 0) {
    a = s[is - 1], e[0][0][si] = e[1][0][si] = a, si++;
    if (fa[a] == -1) fa[a] = si - 1;
    if (ji[a] > 0 && tab[a][ji[a] - 1] == par[a]) ji[a]--;
    if (ji[a] > 0)
      b = s[is] = tab[a][ji[a] - 1], pre[b] = ip, par[b] = a, dep[b] = is + 1,
      ip++, is++, ji[a]--;
    else
      son[a]++, son[par[a]] += son[a], is--;
  }
  for (int i = 1; i < 20; i++) {
    x = 1 << (i - 1);
    for (int z = 0; z < si; z++) {
      if (z + x >= si || dep[e[0][i - 1][z]] < dep[e[0][i - 1][z + x]])
        e[0][i][z] = e[0][i - 1][z];
      else
        e[0][i][z] = e[0][i - 1][z + x];
      if (z - x < 0 || dep[e[1][i - 1][z]] < dep[e[1][i - 1][z - x]])
        e[1][i][z] = e[1][i - 1][z];
      else
        e[1][i][z] = e[1][i - 1][z - x];
    }
  }
}
int lca(int a, int b) {
  if (fa[a] > fa[b]) a = a + b, b = a - b, a = a - b;
  a = fa[a], b = fa[b];
  int x = pl2[b - a];
  if (dep[e[0][x][a]] < dep[e[1][x][b]])
    return e[0][x][a];
  else
    return e[1][x][b];
}
int d[2][C], l[C];
void rear(int a, int n) {
  int i = 2, b;
  for (i = 1; i <= n; i++) d[0][i] = d[1][i] = 0;
  for (i = n; i > 1; i--) {
    b = par[i];
    if (d[0][i] + 1 > d[0][b])
      d[1][b] = d[0][b], d[0][b] = d[0][i] + 1, l[b] = i;
    else if (d[0][i] + 1 > d[1][b])
      d[1][b] = d[0][i] + 1;
  }
  for (i = 2; i <= n; i++) {
    a = par[i];
    if (d[0][a] + 1 > d[0][i] && l[a] != i)
      d[0][i] = d[0][a] + 1, l[i] = -1;
    else if (d[1][a] + 1 > d[0][i])
      d[0][i] = d[1][a] + 1, l[i] = -1;
    else if (d[0][a] + 1 > d[1][i] && l[a] != i)
      d[1][i] = d[0][a] + 1;
    else if (d[1][a] + 1 > d[1][i])
      d[1][i] = d[1][a] + 1;
  }
}
inline int dis(int a, int b) { return dep[a] + dep[b] - 2 * dep[lca(a, b)]; }
int main() {
  pl2[0] = 0, pl2[1] = 0;
  for (i = 2; i < 2 * C; i++) pl2[i] = pl2[i / 2] + 1;
  scanf("%d", &n);
  for (i = 2; i <= n; i++) {
    scanf("%d", &a);
    tab[i].push_back(a), tab[a].push_back(i);
    ij[a]++, ij[i]++;
  }
  proc_tree(1, n);
  for (i = 1; i <= n; i++) ij[i] = 0;
  for (i = 2; i <= n; i++) {
    if (d[0][par[i]] + 1 > alen) alen++;
    d[0][i] = d[0][par[i]] + 1;
    ij[i]++, ij[par[i]]++;
    for (j = last; j < i; j++) {
      if (dis(i, j) > alen) {
        alen++;
        break;
      }
    }
    if (i % D == 0) rear(1, i), last = i + 1;
    printf("%d ", alen);
  }
  return 0;
}
