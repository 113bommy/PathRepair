#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 63 - 1, MOD = 1e9 + 7;
const int L = 17, N = 1 << L;
int pp[3][L][N];
int d[3][N];
vector<int> E[3][N];
int par[N], rnk[N];
void dfs1(int t, int v, int _d = 0, int _p = -1) {
  d[t][v] = _d;
  pp[t][0][v] = _p;
  for (int i = 1; i < L; i++)
    if (pp[t][i - 1][v] != -1)
      pp[t][i][v] = pp[t][i - 1][pp[t][i - 1][v]];
    else
      pp[t][i][v] = -1;
  for (int nn : E[t][v]) dfs1(t, nn, _d + 1, v);
}
int lca(int t, int u, int v) {
  if (d[t][u] > d[t][v]) swap(u, v);
  for (int i = L; i--;)
    if (d[t][v] - (1 << i) >= d[t][u]) v = pp[t][i][v];
  if (u == v) return u;
  for (int i = L; i--;)
    if (pp[t][i][u] != pp[t][i][v]) u = pp[t][i][u], v = pp[t][i][v];
  return pp[t][0][u];
}
int find(int x) {
  if (par[x] == -1) return x;
  return par[x] = find(par[x]);
}
void uni(int x, int y) {
  x = find(x), y = find(y);
  if (rnk[x] > rnk[y]) swap(x, y);
  par[x] = y;
  if (rnk[x] == rnk[y]) rnk[y]++;
}
long long n;
int main() {
  memset(par, -1, sizeof par);
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int pi, ti;
    cin >> pi >> ti;
    if (ti == 0) {
      E[0][pi].push_back(i);
      E[1][0].push_back(i);
      E[2][pi].push_back(i);
    } else if (ti == 1) {
      E[0][0].push_back(i);
      E[1][pi].push_back(i);
      E[2][pi].push_back(i);
    } else {
      E[0][0].push_back(i);
      E[1][0].push_back(i);
      E[2][0].push_back(i);
    }
  }
  dfs1(0, 0);
  dfs1(1, 0);
  dfs1(2, 0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int ti, ui, vi;
    cin >> ti >> ui >> vi;
    if (ui == vi) {
      cout << "NO\n";
      continue;
    }
    if (ti == 1) {
      if (lca(0, ui, vi) == ui) {
        cout << "YES\n";
      } else
        cout << "NO\n";
    } else {
      int parr = lca(2, ui, vi);
      if (parr == -1 || parr == vi) {
        cout << "NO\n";
        continue;
      }
      if (lca(1, vi, parr) == parr && lca(0, ui, parr) == parr)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
  return 0;
}
