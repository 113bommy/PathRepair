#include <bits/stdc++.h>
using namespace std;
long long GetWord() {
  char c;
  while (c = getchar(), c < 'a' || c > 'z')
    ;
  long long S = c - 96;
  while (c = getchar(), c >= 'a' && c <= 'z') S = S * 26 + c - 96;
  return S;
}
const int inf = 1000000000;
int main() {
  int N;
  scanf("%d", &N);
  static long long A[15];
  for (int i = 0; i < N; i++) A[i] = GetWord();
  static int Count[32768];
  Count[0] = 0;
  for (int i = 1; i < (1 << N); i++) Count[i] = Count[i ^ (i & -i)] + 1;
  int Total;
  scanf("%d", &Total);
  int Ans = 0, Best;
  for (int Number = 1; Number <= Total; Number++) {
    int M, Temp = 0;
    scanf("%d", &M);
    static int B[500000];
    static bool Flag[15];
    memset(Flag, 0, sizeof(Flag));
    for (int i = 0; i < M; i++) {
      long long X = GetWord();
      int T = -1;
      for (int j = 0; j < N && T == -1; j++)
        if (A[j] == X) T = j;
      if (T != -1) {
        B[Temp++] = T;
        Flag[T] = true;
      }
    }
    M = Temp;
    bool OK = true;
    for (int i = 0; i < N; i++) OK = OK && Flag[i];
    if (!OK) continue;
    static int Next[500000][15];
    for (int i = 0; i < N; i++)
      Next[M - 1][i] = (B[M - 1] == i) ? (M - 1) : inf;
    for (int i = M - 2; i >= 0; i--)
      for (int j = 0; j < N; j++) Next[i][j] = (B[i] == j) ? i : Next[i + 1][j];
    static int DP[32768][106];
    for (int i = 0; i < (1 << N); i++)
      for (int j = 0; j <= N * (N - 1) / 2; j++) {
        DP[i][j] = inf;
        if (j > Count[i] * (Count[i] - 1) / 2) continue;
        if (!i) {
          DP[i][j] = 0;
          continue;
        }
        int One = Count[i];
        for (int k = 0; k < N; k++)
          if (i & (1 << k)) {
            if (j < --One) continue;
            int T = DP[i ^ (1 << k)][j - One];
            if (T == inf) continue;
            DP[i][j] = min(DP[i][j], Next[T][k]);
          }
      }
    int Score = N * (N - 1) / 2 + 1;
    while (Score && DP[(1 << N) - 1][N * (N - 1) / 2 + 1 - Score] == inf)
      Score--;
    if (Score > Ans) {
      Ans = Score;
      Best = Number;
    }
  }
  if (!Ans)
    printf("Brand new problem!\n");
  else {
    printf("%d\n[:", Best);
    while (Ans--) putchar('|');
    printf(":]\n");
  }
  return 0;
}
