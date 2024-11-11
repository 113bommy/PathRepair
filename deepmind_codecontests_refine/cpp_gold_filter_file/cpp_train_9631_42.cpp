#include <bits/stdc++.h>
const int Mod = 1000000007;
const int ML = 2005;
inline void Add(int &x, int y) { x -= (x += y) >= Mod ? Mod : 0; }
int N, M, Ans;
char S[2][ML], T[ML];
int LCP1[2][ML][ML], LCP2[2][ML][ML];
int LCS1[2][ML][ML], LCS2[2][ML][ML];
bool U1[2][ML][ML], U2[2][ML][ML];
int F[2][ML][ML], G[2][ML][ML];
void Calc() {
  for (int i = (0); i <= (1); ++i) {
    for (int k = (M); k >= (1); --k) {
      for (int j = (N); j >= (1); --j)
        LCP1[i][j][k] = S[i][j] == T[k] ? 1 + LCP1[i][j + 1][k + 1] : 0;
      for (int j = (1); j <= (N); ++j)
        LCP2[i][j][k] = S[i][j] == T[k] ? 1 + LCP2[i][j - 1][k + 1] : 0;
    }
    for (int k = (1); k <= (M); ++k) {
      for (int j = (N); j >= (1); --j)
        LCS1[i][j][k] = S[i][j] == T[k] ? 1 + LCS1[i][j + 1][k - 1] : 0;
      for (int j = (1); j <= (N); ++j)
        LCS2[i][j][k] = S[i][j] == T[k] ? 1 + LCS2[i][j - 1][k - 1] : 0;
    }
  }
  for (int i = (0); i <= (1); ++i) {
    for (int j = (1); j <= (N); ++j) {
      for (int k = (2); k <= (std::min(N - j + 1, M / 2)); ++k)
        U1[i][j][k] = LCS1[!i][j][M] >= k && LCS2[i][j + k - 1][M - k] >= k;
      for (int k = (2); k <= (std::min(j, M / 2)); ++k)
        U2[i][j][k] = LCP2[!i][j][1] >= k && LCP1[i][j - k + 1][k + 1] >= k;
    }
  }
  if (~M & 1)
    for (int i = (1); i <= (N); ++i) {
      Add(Ans, U1[1][i][M / 2]), Add(Ans, U2[1][i][M / 2]);
      for (int j = (0); j <= (1); ++j)
        for (int k = (2); k <= (M / 2 - 2); ++k)
          Add(Ans, U2[j][i][k] && U1[j][i + 1][M / 2 - k]);
    }
  for (int i = (1); i <= (N); ++i) {
    for (int j = (0); j <= (1); ++j) {
      if (S[j][i] == T[1]) Add(F[j][i][1], 1);
      for (int k = (2); k <= (M / 2); ++k)
        if (U2[j][i - 1][k] && S[j][i] == T[k + k + 1])
          Add(F[j][i][k + k + 1], 1);
      for (int k = (1); k <= (M); ++k)
        if (S[j][i] == T[k + 1])
          Add(F[j][i][k + 1], F[j][i - 1][k]),
              Add(F[j][i][k + 1], G[j][i - 1][k]);
      for (int k = (1); k <= (M); ++k)
        if (S[!j][i] == T[k + 1]) Add(G[!j][i][k + 1], F[j][i][k]);
    }
    for (int j = (0); j <= (1); ++j) {
      Add(Ans, F[j][i][M]), Add(Ans, G[j][i][M]);
      for (int k = (2); k <= (M / 2); ++k)
        if (U1[j][i + 1][k])
          Add(Ans, F[j][i][M - k - k]), Add(Ans, G[j][i][M - k - k]);
    }
  }
}
int main() {
  scanf("%s%s%s", S[0] + 1, S[1] + 1, T + 1);
  N = strlen(S[0] + 1), M = strlen(T + 1);
  if (M == 1) {
    for (int i = (0); i <= (1); ++i)
      for (int j = (1); j <= (N); ++j) Ans += S[i][j] == T[1];
    return printf("%d\n", Ans), 0;
  }
  if (M == 2) {
    for (int i = (0); i <= (1); ++i)
      for (int j = (1); j <= (N); ++j)
        if (S[i][j] == T[1])
          Ans += (S[!i][j] == T[2]) + (S[i][j - 1] == T[2]) +
                 (S[i][j + 1] == T[2]);
    return printf("%d\n", Ans), 0;
  }
  Calc();
  std::reverse(T + 1, T + M + 1);
  memset(F, 0, sizeof F), memset(G, 0, sizeof G);
  Calc();
  printf("%d\n", Ans);
  return 0;
}
