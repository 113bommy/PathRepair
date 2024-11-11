#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 400, LOGN = 19;
int n, q, a[N], dpLCA[LOGN][N], lca[N], kraw[N], dist[N];
vector<pair<int, int> > G[N];
long long dp[N], dp2[N], tree[N], odl[N], wynik[N], pom[N];
vector<int> zapytania[N];
void insert(int v, long long x) {
  while (v <= n) {
    tree[v] += x;
    v += (v & (-v));
  }
}
long long query(int v) {
  long long wynik = 0;
  while (v > 0) {
    wynik += tree[v];
    v -= (v & (-v));
  }
  return wynik;
}
long long pytaj(int a, int b) {
  if (a > b) return 0;
  return query(b) - query(a - 1);
}
void preDFS(int u) {
  dp[u] = a[u];
  for (auto v : G[u]) {
    if (v.first != dpLCA[0][u]) {
      dpLCA[0][v.first] = u;
      dist[v.first] = dist[u] + 1;
      odl[v.first] = odl[u] + v.second;
      kraw[v.first] = v.second;
      preDFS(v.first);
      pom[v.first] = max(0LL, dp[v.first] - 2 * v.second);
      dp[u] += pom[v.first];
    }
  }
}
int LCA(int a, int b) {
  if (dist[a] < dist[b]) swap(a, b);
  int d = dist[a] - dist[b];
  for (int i = 0; i < LOGN; i++)
    if (d & (1 << i)) a = dpLCA[i][a];
  if (a == b) return a;
  for (int i = LOGN - 1; i >= 0; i--) {
    if (dpLCA[i][a] != dpLCA[i][b]) {
      a = dpLCA[i][a];
      b = dpLCA[i][b];
    }
  }
  return dpLCA[0][a];
}
void preDP(int u) {
  int ojciec = dpLCA[0][u];
  dp2[u] = dp[u] + (u != 1 ? max(0LL, dp[ojciec] - 2 * kraw[u]) : 0);
  long long blep = dp[u] - (u != 1 ? pom[u] : 0);
  insert(dist[u], blep);
  for (auto ID : zapytania[u]) wynik[ID] += pytaj(dist[lca[ID]], dist[u]);
  for (auto v : G[u]) {
    if (v.first != dpLCA[0][u]) {
      long long pomek = dp[u];
      dp[u] = dp2[u] - pom[v.first];
      preDP(v.first);
      dp[u] = pomek;
    }
  }
  insert(dist[u], -blep);
}
int32_t main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  dpLCA[0][1] = 1;
  dist[1] = 1;
  preDFS(1);
  for (int i = 1; i < LOGN; i++)
    for (int j = 1; j <= n; j++) dpLCA[i][j] = dpLCA[i - 1][dpLCA[i - 1][j]];
  for (int i = 1; i <= q; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    lca[i] = LCA(a, b);
    wynik[i] = odl[a] + odl[b] - 2 * odl[lca[i]];
    zapytania[a].push_back(i);
    zapytania[b].push_back(i);
  }
  preDP(1);
  for (int i = 1; i <= q; i++) {
    int u = lca[i];
    int ojciec = dpLCA[0][u];
    wynik[i] = wynik[i] - dp[u];
    long long pomek = dp[ojciec];
    dp[ojciec] = dp2[ojciec] - pom[u];
    printf("%lld\n",
           wynik[i] +
               (u != 1 ? max(0LL, dp[ojciec] - 2 * kraw[u]) + 2 * pom[u] : 0));
    dp[ojciec] = pomek;
  }
  getchar();
  getchar();
  return 0;
}
