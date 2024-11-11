#include <bits/stdc++.h>
using namespace std;
void Get(int &T) {
  char C;
  bool F = 0;
  for (; C = getchar(), C < '0' || C > '9';)
    if (C == '-') F = 1;
  for (T = C - '0'; C = getchar(), C >= '0' && C <= '9'; T = T * 10 + C - '0')
    ;
  F && (T = -T);
}
void Get(char &C) {
  for (; C = getchar(), C < 'A' || C > 'Z';)
    ;
}
int N, M, K;
char A[1005][1005];
char B[1005][1005];
int Ans[1005][1005];
bool Flip;
void Debug() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) printf("%d ", Ans[i][j]);
    puts("");
  }
}
void Init() {
  Get(N);
  Get(M);
  Get(K);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < M; j++) Get(A[i][j]);
    if (i < N)
      for (int j = 1; j <= M; j++) Get(B[i][j]);
  }
  if (N > M) {
    Flip = 1;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j < i; j++) {
        std::swap(A[i][j], A[j][i]);
        std::swap(B[i][j], B[j][i]);
      }
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) std::swap(A[i][j], B[i][j]);
    std::swap(N, M);
  }
}
void Work() {
  if (K == 1) {
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++) Ans[i][j] = 1;
    int Cnt = 0, CntE = 0;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++) {
        CntE += (A[i][j] == 'E');
        CntE += (B[i][j] == 'E');
        Cnt += (A[i][j] == 'N');
        Cnt += (B[i][j] == 'N');
      }
    Cnt += CntE;
    if ((CntE << 2) < Cnt * 3) {
      puts("NO");
      exit(0);
    }
    return;
  }
  for (int i = 1; i <= N; i++) {
    Ans[i][1] = 1;
    for (int j = 2; j <= M; j++) {
      Ans[i][j] = Ans[i][j - 1];
      if (A[i][j - 1] == 'N') Ans[i][j] ^= 3;
    }
    if (i == 1) continue;
    int Ans0 = 0;
    for (int j = 1; j <= M; j++)
      Ans0 += ((Ans[i][j] == Ans[i - 1][j]) == (B[i - 1][j] == 'E'));
    if (M - Ans0 > Ans0)
      for (int j = 1; j <= M; j++) Ans[i][j] ^= 3;
  }
}
void Output() {
  if (Flip) {
    std::swap(N, M);
    for (int i = 1; i <= N; i++)
      for (int j = 1; j < i; j++) std::swap(Ans[i][j], Ans[j][i]);
  }
  puts("YES");
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) printf("%d ", Ans[i][j]);
    puts("");
  }
}
int main() {
  Init();
  Work();
  Output();
  return 0;
}
