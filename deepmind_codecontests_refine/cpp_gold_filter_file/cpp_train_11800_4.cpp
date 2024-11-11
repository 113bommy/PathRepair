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
int N, K;
char S[2005][505];
int Order[2005];
bool Cmp(int X, int Y) { return strcmp(S[X] + 1, S[Y] + 1) == -1; }
void Init() {
  Get(N);
  Get(K);
  for (int i = 1; i <= N; i++) {
    scanf("%s", S[i] + 1);
    Order[i] = i;
  }
}
int Height[2005];
int Choose[2005][2005];
int F[2005][2005];
int FTop;
int DFS(int X, int Y) {
  if (X == Y) {
    return 0;
  }
  int IDL = DFS(X, Choose[X][Y] - 1);
  int IDR = DFS(Choose[X][Y], Y);
  FTop++;
  for (int i = 0; i <= Choose[X][Y] - X; i++)
    for (int j = 0; j <= Y - Choose[X][Y] + 1; j++) {
      if (F[FTop][j + i] < F[IDL][i] + F[IDR][j] + i * j * Height[Choose[X][Y]])
        F[FTop][j + i] = F[IDL][i] + F[IDR][j] + i * j * Height[Choose[X][Y]];
    }
  return FTop;
}
int Ans;
void Work() {
  std::sort(Order + 1, Order + N + 1, Cmp);
  for (int k = 2; k <= N; k++) {
    int p;
    for (p = 1; S[Order[k]][p] != 0 && S[Order[k]][p] == S[Order[k - 1]][p];
         p++)
      ;
    p--;
    Height[k] = p;
  }
  for (int k = 2; k <= N; k++) {
    Choose[k - 1][k] = k;
  }
  for (int i = 2; i < N; i++)
    for (int j = 1; j + i <= N; j++) {
      Choose[j][j + i] = Height[Choose[j][j + i - 1]] < Height[j + i]
                             ? Choose[j][j + i - 1]
                             : j + i;
    }
  int X = DFS(1, N);
  Ans = F[X][K];
}
void Output() { printf("%d\n", Ans); }
int main() {
  Init();
  Work();
  Output();
  return 0;
}
