#include <bits/stdc++.h>
void Get(int &T) {
  char C;
  bool F = 0;
  for (; C = getchar(), C < '0' || C > '9';)
    if (C == '-') F = 1;
  for (T = C - '0'; C = getchar(), C >= '0' && C <= '9'; T = T * 10 + C - '0')
    ;
  F && (T = -T);
}
int N, M, K;
int A[1005][1005];
int X[1005];
int Y[1005];
int Z[1005];
bool UseX[1005];
bool UseY[1005];
int Mod;
void Init() {
  Get(N);
  Get(M);
  Get(K);
  for (int i = 1; i <= K; i++) {
    Get(X[i]);
    Get(Y[i]);
    UseX[X[i]] = UseY[Y[i]] = 1;
    Get(Z[i]);
  }
  Get(Mod);
}
long long F[1005][5];
long long G[1005][5];
void Debug() { printf("%d %d\n", G[M][0], G[M][1]); }
void Swap() {
  for (int i = 1; i <= N; i++)
    if (UseX[i] == 0) {
      for (int k = 1; k <= K; k++)
        if (X[k] == N) X[k] = i;
      return;
    }
  for (int i = 1; i <= M; i++)
    if (UseY[i] == 0) {
      std::swap(N, M);
      for (int k = 1; k <= K; k++) std::swap(X[k], Y[k]);
      for (int k = 1; k <= K; k++)
        if (X[k] == N) X[k] = i;
      return;
    }
}
void Work() {
  Swap();
  for (int i = 1; i <= K; i++) A[X[i]][Y[i]] = Z[i];
  F[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    memset(G, 0, sizeof G);
    G[0][0] = 1;
    for (int j = 1; j <= M; j++) {
      if (A[i][j] != -1) {
        (G[j][0] += G[j - 1][1]) %= Mod;
        (G[j][1] += G[j - 1][0]) %= Mod;
      }
      if (A[i][j] != 1) {
        (G[j][0] += G[j - 1][0]) %= Mod;
        (G[j][1] += G[j - 1][1]) %= Mod;
      }
    }
    (F[i][1] += F[i - 1][0] * G[M][1]) %= Mod;
    (F[i][0] += F[i - 1][1] * G[M][1]) %= Mod;
  }
}
void Output() { printf("%I64d\n", F[N - 1][(~M) & 1]); }
int main() {
  Init();
  Work();
  Output();
  return 0;
}
