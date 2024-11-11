#include <bits/stdc++.h>
using namespace std;
int n, m, s, M[128][128];
vector<vector<int> > dist[128][128];
vector<vector<pair<int, int> > > paidist[128][128];
short int terminal[128][128];
pair<int, int> S[12];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int PD[(1 << 7)][101][101][2];
bool split[(1 << 7)][101][101][2];
pair<pair<int, int>, pair<int, int> > pai[(1 << 7)][101][101][2];
char R[128][128];
inline void imprime() {
  for (int i = 0; i < n; i++) printf("%s\n", R[i]);
}
void pinta_caminho(int i1, int j1, int i2, int j2) {
  if (i1 == i2 and j1 == j2) {
    R[i1][j1] = 'X';
    return;
  }
  pair<int, int> p = paidist[i1][j1][i2][j2];
  if (p.first == i1 and p.second == j1) {
    R[i1][j1] = 'X';
    R[i2][j2] = 'X';
    return;
  }
  pinta_caminho(i1, j1, p.first, p.second);
  pinta_caminho(p.first, p.second, i2, j2);
}
void pinta_arvore(int bm, int i, int j, int pfolha) {
  if (bm == 0) {
    R[i][j] = 'X';
    return;
  }
  if (__builtin_popcount(bm) == 1) {
    int t = __builtin_ctz(bm);
    pinta_caminho(S[t].first, S[t].second, i, j);
    return;
  }
  pair<pair<int, int>, pair<int, int> > u = pai[bm][i][j][pfolha];
  int nbm = u.first.first, npfolha = u.first.second;
  int ni = u.second.first, nj = u.second.second;
  if (split[bm][i][j][pfolha]) {
    pinta_arvore(nbm, i, j, npfolha);
    pinta_arvore(bm ^ nbm, i, j, npfolha);
    return;
  }
  pinta_caminho(i, j, ni, nj);
  pinta_arvore(nbm, ni, nj, npfolha);
}
int calc(int bm, int i, int j, int pfolha) {
  if (bm == 0) return M[i][j];
  int &pd = PD[bm][i][j][pfolha];
  pair<pair<int, int>, pair<int, int> > &papai = pai[bm][i][j][pfolha];
  bool &sp = split[bm][i][j][pfolha];
  if (pd != -1) return pd;
  if (__builtin_popcount(bm) == 1) {
    int t = __builtin_ctz(bm);
    return pd = dist[S[t].first][S[t].second][i][j];
  }
  int best = 0x3f3f3f3f;
  int x = (bm - 1) & bm;
  while (x) {
    int t1 = calc(x, i, j, 1);
    int t2 = calc(bm ^ x, i, j, 1);
    int opc = t1 + t2 - M[i][j];
    if (opc < best) {
      best = opc;
      papai = pair<pair<int, int>, pair<int, int> >(pair<int, int>(x, 1),
                                                    pair<int, int>(i, j));
      sp = true;
    }
    x = (x - 1) & bm;
  }
  if (pfolha) {
    for (int k = 0; k < s; k++)
      if (bm & (1 << k)) {
        int opc = dist[i][j][S[k].first][S[k].second] +
                  calc(bm ^ (1 << k), S[k].first, S[k].second, 1) -
                  M[S[k].first][S[k].second];
        if (opc < best) {
          best = opc;
          sp = false;
          papai = pair<pair<int, int>, pair<int, int> >(
              pair<int, int>(bm ^ (1 << k), 1),
              pair<int, int>(S[k].first, S[k].second));
        }
      }
    for (int k = 0; k < n; k++)
      for (int l = 0; l < m; l++)
        if ((k != i or l != j) and terminal[k][l] < 0) {
          int opc = dist[i][j][k][l] + calc(bm, k, l, 0) - M[k][l];
          if (opc < best) {
            best = opc;
            sp = false;
            papai = pair<pair<int, int>, pair<int, int> >(pair<int, int>(bm, 0),
                                                          pair<int, int>(k, l));
          }
        }
  }
  return pd = best;
}
int main() {
  scanf("%d %d %d", &n, &m, &s);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      R[i][j] = '.';
      dist[i][j].resize(n);
      paidist[i][j].resize(n);
      for (int k = 0; k < n; k++) {
        dist[i][j][k].resize(m);
        paidist[i][j][k].resize(m);
        for (int l = 0; l < m; l++) dist[i][j][k][l] = 0x3f3f3f3f;
      }
    }
    R[i][m] = '\0';
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%d", &M[i][j]);
      dist[i][j][i][j] = M[i][j];
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (!(0 <= ni and ni < n and 0 <= nj and nj < m)) continue;
        dist[i][j][ni][nj] = M[i][j] + M[ni][nj];
        paidist[i][j][ni][nj] = pair<int, int>(i, j);
      }
  for (int k1 = 0; k1 < n; k1++)
    for (int k2 = 0; k2 < m; k2++)
      for (int i1 = 0; i1 < n; i1++)
        for (int i2 = 0; i2 < m; i2++)
          for (int j1 = 0; j1 < n; j1++)
            for (int j2 = 0; j2 < m; j2++) {
              int opc = dist[i1][i2][k1][k2] + dist[k1][k2][j1][j2] - M[k1][k2];
              if (opc < dist[i1][i2][j1][j2]) {
                dist[i1][i2][j1][j2] = opc;
                paidist[i1][i2][j1][j2] = pair<int, int>(k1, k2);
              }
            }
  memset(terminal, 0xff, sizeof(terminal));
  for (int i = 0; i < s; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    terminal[a][b] = i;
    S[i] = pair<int, int>(a, b);
  }
  if (s == 1) {
    printf("%d\n", M[S[0].first][S[0].second]);
    R[S[0].first][S[0].second] = 'X';
    imprime();
    return 0;
  }
  if (s == 2) {
    printf("%d\n", dist[S[0].first][S[0].second][S[1].first][S[1].second]);
    pinta_caminho(S[0].first, S[0].second, S[1].first, S[1].second);
    imprime();
    return 0;
  }
  memset(PD, 0xff, sizeof(PD));
  int resp = calc((1 << s) - 1 - 1, S[0].first, S[0].second, 1);
  int bm = (1 << s) - 1 - 1, i = S[0].first, j = S[0].second, pf = 1;
  pinta_arvore(bm, i, j, pf);
  printf("%d\n", resp);
  imprime();
  int tot = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (R[i][j] == 'X') tot += M[i][j];
  if (resp != tot) printf("PAU! resp = %d, cert = %d\n", resp, tot);
  return 0;
}
