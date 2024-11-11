#include <bits/stdc++.h>
const int Mod = 1000000000 + 7;
int N, M, K;
int C[107][107];
int F[2][100 + 7][100 + 7][100 + 7];
int Answer = 0;
void update(int& x, const int& b) {
  x += b;
  if (x > Mod) x -= Mod;
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i <= 100; i++)
    for (int j = 0, t; j <= i; j++)
      C[i][j] = (!j ? 1 : (t = C[i - 1][j] + C[i - 1][j - 1]) > K ? K + 1 : t);
  int cur = 0;
  int nxt = 0;
  for (int i = 0; i < M; i++) {
    cur ^= 1;
    nxt = cur ^ 1;
    for (int k = 1; k <= N; k++) update(F[nxt][k][k][1], 1);
    for (int n = 0; n <= N; n++)
      for (int v = 1; n + v <= N; v++)
        for (int k = 1; k <= K; k++)
          if (F[cur][n][v][k]) {
            update(Answer, F[cur][n][v][k]);
            for (int d = v + 1; d + n <= N; d++) {
              int l1 = k * C[d - 1][v - 1];
              if (l1 > K) break;
              update(F[nxt][n + d][d - v][l1], F[cur][n][v][k]);
            }
            F[cur][n][v][k] = 0;
          }
  }
  printf("%d\n", Answer);
  return 0;
}
