#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9, MOD = 998244353;
const int N = 3e5 + 5, LOG = 20;
int n, k, COL[N], PAR[N][LOG], H[N], DP[N][2];
vector<int> LOC[N], G[N], T[N];
int Power(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = 1LL * a * a % MOD)
    if (b & 1) res = 1LL * res * a % MOD;
  return res;
}
int Inverse(int a) { return Power(a % MOD, MOD - 2); }
void DFS_LCA(int v = 1, int p = 0) {
  PAR[v][0] = p, H[v] = H[p] + 1;
  for (int pw = 1; pw < LOG; pw++) PAR[v][pw] = PAR[PAR[v][pw - 1]][pw - 1];
  for (int u : G[v])
    if (u != p) DFS_LCA(u, v);
}
int GetPar(int v, int h) {
  for (int pw = 0; pw < LOG; pw++)
    if (h & (1 << pw)) v = PAR[v][pw];
  return v;
}
int GetLCA(int v, int u) {
  if (H[v] < H[u]) swap(v, u);
  v = GetPar(v, H[v] - H[u]);
  if (v == u) return v;
  for (int pw = LOG - 1; pw >= 0; pw--)
    if (PAR[v][pw] != PAR[u][pw]) v = PAR[v][pw], u = PAR[u][pw];
  return PAR[v][0];
}
void DFS(int v = 1, int p = 0) {
  DP[v][0] = 1;
  for (int u : G[v])
    if (u != p) {
      DFS(u, v);
      DP[v][0] = 1LL * DP[v][0] * (DP[u][0] + DP[u][1]) % MOD;
    }
  for (int u : G[v])
    if (u != p) {
      DP[v][1] = (DP[v][1] + 1LL * DP[v][0] * Inverse(DP[u][0] + DP[u][1]) *
                                 DP[u][1] % MOD) %
                 MOD;
    }
  if (COL[v]) DP[v][1] = DP[v][0], DP[v][0] = 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> COL[i];
    LOC[COL[i]].push_back(i);
  }
  for (int i = 1; i <= n - 1; i++) {
    int v, u;
    cin >> v >> u;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  DFS_LCA();
  for (int col = 1; col <= k; col++) {
    int lca = LOC[col][0];
    for (int v : LOC[col]) lca = GetLCA(v, lca);
    for (int v : LOC[col]) {
      while (v != lca) {
        v = PAR[v][0];
        if (COL[v] == col) break;
        if (COL[v] == 0)
          COL[v] = col;
        else
          return cout << 0 << "\n", 0;
      }
    }
  }
  DFS();
  cout << DP[1][1] << "\n";
  return 0;
}
