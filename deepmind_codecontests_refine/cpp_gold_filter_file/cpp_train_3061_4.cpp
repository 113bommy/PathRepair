#include <bits/stdc++.h>
using namespace std;
const int Sn = 55;
const int mod = (int)1e9 + 7;
int n, m;
int G[Sn][Sn];
vector<int> V[Sn][Sn];
int T[Sn * 4], tT;
int Ms[Sn][Sn], Mo[Sn][Sn];
int bf[Sn][Sn][Sn * 2];
int dp[Sn][Sn * 2];
int suf[Sn][Sn * 2];
vector<pair<int, int> > trP[Sn];
int trC[Sn][Sn * Sn * Sn * 2];
int trN[Sn];
bool contain(int u, int v, int& pu, int& pv) {
  int sz = V[u][v].size();
  for (int l = 0; l <= sz - 2; l++)
    if (V[u][v][l] == u && V[u][v][l + 1] == v) return pu = l, pv = l + 1, 1;
  return 0;
}
int find(int d, int q, int wk) {
  if (q == tT) return d;
  if (tT > 2 * n + 1) return -1;
  int k = T[q + 1], sz = V[d][k].size();
  if (G[d][k] == wk) {
    for (int l = 0; l <= sz - 1; l++) T[++tT] = V[d][k][l];
    return find(k, q + 1, wk);
  } else
    return -1;
}
void add(int& a, int b) { a = (a + b) % mod; }
void transform(int i, int j, vector<pair<int, int> >& P, int C[]) {
  int N = P.size();
  for (int l = 0; l <= N - 1; l++)
    if (j >= P[l].second)
      add(dp[i][j],
          (long long)C[l + 1] * suf[P[l].first][j - P[l].second] % mod);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v, sz, x; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &sz);
    G[u][v] = 1, G[v][u] = -1;
    for (int l = 1; l <= sz; l++) scanf("%d", &x), V[u][v].push_back(x);
    for (int l = 1; l <= sz; l++) V[v][u].push_back(V[u][v][sz - l]);
  }
  for (int u = 1; u <= n; u++)
    for (int v = 1; v <= n; v++)
      if (G[u][v] == 1 && V[u][v].size()) {
        int sz = V[u][v].size();
        if (V[u][v][0] != v) continue;
        tT = 0;
        for (int l = 0; l <= sz - 1; l++) T[++tT] = V[u][v][l];
        int vt = find(v, 1, 1);
        if (vt != -1) Ms[u][v] = tT, Mo[u][v] = vt;
      }
  for (int i = 1; i <= n; i++) bf[i][i][0] = 1;
  for (int j = 1; j <= 2 * n; j++) {
    for (int i = 1; i <= n; i++)
      for (int k = 1; k <= n; k++)
        if (G[i][k] == -1 && V[i][k].size()) {
          int sz = V[i][k].size();
          if (V[i][k][0] != k) continue;
          tT = 0;
          for (int l = 0; l <= sz - 1; l++) T[++tT] = V[i][k][l];
          int vt = find(k, 1, -1);
          if (vt != -1 && j >= tT)
            for (int o = 1; o <= n; o++) add(bf[i][o][j], bf[vt][o][j - tT]);
        }
  }
  int pu, pv, ld, lx, rd, rx, sz;
  for (int u = 1; u <= n; u++)
    for (int v = 1; v <= n; v++) {
      sz = V[u][v].size();
      if (G[u][v] == 1 && contain(u, v, pu, pv)) {
        tT = 0;
        for (int l = pu; l >= 0; l--) T[++tT] = V[u][v][l];
        ld = find(u, 1, -1), lx = tT - 1;
        tT = 0;
        for (int l = pv; l <= sz - 1; l++) T[++tT] = V[u][v][l];
        rd = find(v, 1, 1), rx = tT - 1;
        int len = lx + rx + 1;
        if (ld == -1 || rd == -1 || len > 2 * n) continue;
        int cc;
        for (int i = 1; i <= n; i++)
          for (int j0 = 0; j0 <= 2 * n - len; j0++)
            if (cc = bf[ld][i][j0], cc) {
              trP[i].push_back(make_pair(rd, j0 + len));
              trC[i][++trN[i]] = cc;
            }
      }
    }
  for (int i = 1; i <= n; i++) suf[i][0] = 1;
  for (int j = 1; j <= 2 * n; j++) {
    for (int i = 1; i <= n; i++)
      for (int k = 1; k <= n; k++)
        if (Ms[i][k] && j >= Ms[i][k])
          add(suf[i][j], suf[Mo[i][k]][j - Ms[i][k]]);
    int ansj = 0;
    for (int i = 1; i <= n; i++) {
      transform(i, j, trP[i], trC[i]);
      add(ansj, dp[i][j]);
      for (int k = 1; k <= n; k++)
        if (G[k][i] == 1 && !V[k][i].size()) add(suf[k][j + 1], dp[i][j]);
    }
    printf("%d\n", ansj);
  }
}
