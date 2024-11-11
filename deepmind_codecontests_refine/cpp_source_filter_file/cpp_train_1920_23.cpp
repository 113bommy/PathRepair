#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10, L = 18;
vector<int> e[MAXN];
int n, dep[MAXN], f[MAXN], sf[MAXN], ssf[MAXN], u[MAXN], fa[MAXN][L],
    g[MAXN][L], h[MAXN][L], dfn[MAXN], df[MAXN], tot;
void DFS(int first, int Fa) {
  df[++tot] = first, dfn[first] = tot;
  for (int i = 0; i < (int)e[first].size(); ++i)
    if (e[first][i] != Fa) fa[e[first][i]][0] = first, DFS(e[first][i], first);
}
void init() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int first, second;
    scanf("%d%d", &first, &second);
    e[first].push_back(second), e[second].push_back(first);
  }
  DFS(1, 0);
  for (int i = n; i >= 1; --i) {
    int first = df[i];
    if (f[first] + 1 >= f[fa[first][0]])
      ssf[fa[first][0]] = sf[fa[first][0]], sf[fa[first][0]] = f[fa[first][0]];
    else if (f[first] + 1 >= sf[fa[first][0]])
      ssf[fa[first][0]] = sf[fa[first][0]],
      sf[fa[first][0]] = max(sf[fa[first][0]], f[first] + 1);
    else
      ssf[fa[first][0]] = max(ssf[fa[first][0]], f[first] + 1);
    f[fa[first][0]] = max(f[first] + 1, f[fa[first][0]]);
  }
  u[0] = f[0] = sf[0] = -1;
  for (int i = 1; i <= n; ++i) {
    int first = df[i];
    dep[first] = dep[fa[first][0]] + 1;
    if (f[first] + 1 == f[fa[first][0]])
      u[first] = sf[fa[first][0]];
    else
      u[first] = f[fa[first][0]];
    g[first][0] = u[first], h[first][0] = u[first] + 1;
    for (int j = 1; j < L; ++j)
      fa[first][j] = fa[fa[first][j - 1]][j - 1],
      g[first][j] =
          max(g[first][j - 1] + (1 << (j - 1)), g[fa[first][j - 1]][j - 1]),
      h[first][j] =
          max(h[first][j - 1], h[fa[first][j - 1]][j - 1] + (1 << (j - 1)));
    u[first] = max(u[first] + 1, u[fa[first][0]] + 1);
    if (i == 1) u[first] = 0;
  }
}
int LCA(int first, int second) {
  if (dep[first] > dep[second]) swap(first, second);
  for (int j = L - 1; j >= 0; --j)
    if (dep[fa[second][j]] >= dep[first]) second = fa[second][j];
  if (first == second) return first;
  for (int j = L - 1; j >= 0; --j)
    if (fa[first][j] != fa[second][j])
      first = fa[first][j], second = fa[second][j];
  return fa[first][0];
}
int Getlen(int first, int second) {
  return dep[first] + dep[second] - dep[LCA(first, second)] * 2;
}
int calc1(int first, int second, int d) {
  int Tohka = -1;
  for (int j = L - 1; j >= 0; --j)
    if (dep[fa[second][j]] >= dep[first] + d)
      Tohka = max(Tohka + (1 << j), g[second][j]), second = fa[second][j];
  return Tohka;
}
int calc(int first, int a, int b) {
  if (a < b) swap(a, b);
  if (f[first] != a) return f[first];
  if (sf[first] != b) return sf[first];
  return ssf[first];
}
int Getfa(int first, int dep) {
  for (int j = L - 1; j >= 0; --j)
    if ((dep >> j) & 1) first = fa[first][j];
  return first;
}
int calc(int first, int second) {
  if (dep[first] < dep[second] && LCA(first, second) == first) {
    return max(calc1(first, second, 0), u[first]);
  } else {
    int lca = LCA(first, second);
    int Tohka = max(u[lca], calc1(lca, second, 1)) + dep[first] - dep[lca];
    Tohka = max(Tohka, calc(lca, f[Getfa(first, dep[first] - dep[lca] - 1)] + 1,
                            f[second] + dep[second] - dep[lca]) +
                           dep[first] - dep[lca]);
    if (lca == second) Tohka = 0;
    int Mashiro = -1, xx = first;
    for (int j = L - 1; j >= 0; --j)
      if (dep[fa[first][j]] >= dep[lca] + 1)
        Mashiro = max(Mashiro, h[first][j] + dep[xx] - dep[first]),
        first = fa[first][j];
    return max(max(Tohka, Mashiro), f[xx]);
  }
}
void solve() {
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    int first, second;
    scanf("%d%d", &first, &second);
    if (dep[first] > dep[second]) swap(first, second);
    int len = Getlen(first, second);
    if ((len & 1))
      printf("%d\n", max(calc(first, Getfa(second, len / 2)),
                         calc(second, Getfa(second, len / 2 + 1))));
    else {
      if (dep[first] == dep[second])
        printf("%d\n", max(calc(first, Getfa(second, len / 2 - 1)),
                           calc(second, Getfa(first, len / 2 - 1))));
      else
        printf("%d\n", max(calc(first, Getfa(second, len / 2 - 1)),
                           calc(second, Getfa(second, len / 2 + 1))));
    }
  }
}
int main() {
  init();
  solve();
  fclose(stdin);
  fclose(stdout);
  return 0;
}
