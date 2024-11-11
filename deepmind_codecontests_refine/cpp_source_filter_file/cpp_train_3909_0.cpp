#include <bits/stdc++.h>
using namespace std;
const int maxn = 477;
const int INF = 1E9 + 7;
int N, M, D[maxn][maxn], V[maxn], cv = 0, W[maxn][maxn], cw[maxn];
bool vis[maxn];
double ans = 0.0, P[maxn], VP[maxn];
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= N; ++j)
      if (i != j) D[i][j] = INF;
  for (int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    W[a][cw[a]++] = b;
    W[b][cw[b]++] = a;
    D[a][b] = D[b][a] = 1;
  }
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= N; ++j)
        if (D[i][k] + D[k][j] < D[i][j]) {
          D[i][j] = D[i][k] + D[k][j];
        }
  }
  for (int i = 1; i <= N; ++i) {
    double tans = 0.0;
    for (int j = 0; j < N; ++j) {
      double pp = 0.0;
      int cntp = 0;
      cv = 0;
      for (int k = 1; k <= N; ++k) P[k] = 0.0, vis[k] = false;
      for (int k = 1; k <= N; ++k)
        if (D[i][k] == j) {
          ++cntp;
          for (int l = 0; l < cw[k]; ++l) {
            int v = W[k][l];
            P[v] += 1.0 / N / cw[k];
            if (!vis[v]) {
              vis[v] = true;
              V[cv++] = v;
            }
          }
        }
      if (!cntp) break;
      pp = 1.0 / N;
      for (int k = 1; k <= N; ++k) {
        double p2 = 0.0;
        for (int l = 0; l < cv; ++l) {
          int v = V[l];
          VP[D[k][v]] = 0;
        }
        for (int l = 0; l < cv; ++l) {
          int v = V[l], d = D[k][v];
          if (P[v] > VP[d]) {
            p2 -= VP[d];
            p2 += P[v];
            VP[d] = v;
          }
        }
        pp = max(pp, p2);
      }
      tans += pp;
    }
    ans = max(ans, tans);
  }
  printf("%.20lf\n", ans);
}
