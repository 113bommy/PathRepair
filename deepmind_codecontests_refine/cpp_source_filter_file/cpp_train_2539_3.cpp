#include <bits/stdc++.h>
using namespace std;
struct Suffix {
  int Num, X;
};
int Get() {
  char c;
  while (c = getchar(), (c < '0' || c > '9') && (c != '-'))
    ;
  bool Flag = (c == '-');
  if (Flag) c = getchar();
  int X = 0;
  while (c >= '0' && c <= '9') {
    X = X * 10 + c - 48;
    c = getchar();
  }
  return Flag ? -X : X;
}
void Output(int X) {
  if (X < 0) {
    putchar('-');
    X = -X;
  }
  int Len = 0, Data[10];
  while (X) {
    Data[Len++] = X % 10;
    X /= 10;
  }
  if (!Len) Data[Len++] = 0;
  while (Len--) putchar(Data[Len] + 48);
  putchar('\n');
}
const int Base = 19961021;
const int inf = 1000000000;
int N;
string S[11];
long long Hash[11][50001];
long long Pow[50001];
Suffix SA[11][100000];
int Height[11][100000], Pos[11][50000], Sum[11][100001];
int ST[17][11][100000], Log[100001];
long long GetHash(int P, int X, int Len) {
  return Hash[P][X + Len] - Hash[P][X] * Pow[Len];
}
int LCP(Suffix A, Suffix B) {
  int Left = 0, Right = min(S[A.Num].size() - A.X, S[B.Num].size() - B.X);
  while (Left < Right) {
    int Mid = (Left + Right + 1) / 2;
    if (GetHash(A.Num, A.X, Mid) == GetHash(B.Num, B.X, Mid))
      Left = Mid;
    else
      Right = Mid - 1;
  }
  return Left;
}
bool operator<(Suffix A, Suffix B) {
  int Len = LCP(A, B);
  if (B.X + Len == S[B.Num].size()) return false;
  if (A.X + Len == S[A.Num].size()) return true;
  return S[A.Num][A.X + Len] < S[B.Num][B.X + Len];
}
int GetMin(int T, int L, int R) {
  int P = Log[R - L + 1];
  return min(ST[T][P][L], ST[T][P][R - (1 << P) + 1]);
}
int Solve(int T, int L, int R) {
  if (L > R) return inf;
  if (R == S[0].size()) return -inf;
  int Len = R - L + 1, X = Pos[T][L];
  int Left = 0, Right = X;
  while (Left < Right) {
    int Mid = (Left + Right) / 2;
    if (GetMin(T, Mid + 1, X) >= Len)
      Right = Mid;
    else
      Left = Mid + 1;
  }
  int LB = Left;
  Left = X;
  Right = S[0].size() + S[T].size() - 1;
  while (Left < Right) {
    int Mid = (Left + Right + 1) / 2;
    if (GetMin(T, X + 1, Mid) >= Len)
      Left = Mid;
    else
      Right = Mid - 1;
  }
  int UB = Left;
  return Sum[T][UB + 1] - Sum[T][LB];
}
int main() {
  cin >> S[0];
  N = Get();
  static int LB[11], UB[11];
  for (int i = 1; i <= N; i++) cin >> S[i] >> LB[i] >> UB[i];
  for (int i = 0; i <= N; i++) {
    Hash[i][0] = 0;
    for (int j = 0; j < S[i].size(); j++)
      Hash[i][j + 1] = Hash[i][j] * Base + S[i][j];
  }
  Pow[0] = 1;
  for (int i = 0; i < 50000; i++) Pow[i + 1] = Pow[i] * Base;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < S[0].size(); j++) SA[i][j] = (Suffix){0, j};
    for (int j = 0; j < S[i].size(); j++)
      SA[i][S[0].size() + j] = (Suffix){i, j};
    int M = S[0].size() + S[i].size();
    sort(SA[i], SA[i] + M);
    for (int j = 0; j < M; j++)
      if (!SA[i][j].Num) Pos[i][SA[i][j].X] = j;
    for (int j = 1; j < M; j++) Height[i][j] = LCP(SA[i][j], SA[i][j - 1]);
    Sum[i][0] = 0;
    for (int j = 0; j < M; j++) {
      Sum[i][j + 1] = Sum[i][j];
      if (SA[i][j].Num) Sum[i][j + 1]++;
    }
    for (int j = 0; j < M; j++) ST[i][0][j] = Height[i][j];
    for (int j = 1; j < 17; j++)
      for (int k = 0; k <= M - (1 << j); k++)
        ST[i][j][k] = min(ST[i][j - 1][k], ST[i][j - 1][k + (1 << (j - 1))]);
  }
  for (int i = 1, j = 0; i <= 100000; i++) {
    if ((1 << (j + 1)) <= i) j++;
    Log[i] = j;
  }
  static int L[50000], R[50000];
  int Len0 = S[0].size();
  for (int i = 0, P = -1, Q = -1; i < Len0; i++) {
    while (P < Len0) {
      bool Flag = true;
      for (int j = 1; j <= N; j++)
        if (Solve(j, i, P) > UB[j]) Flag = false;
      if (Flag) break;
      P++;
    }
    while (Q < Len0) {
      bool Flag = true;
      for (int j = 1; j <= N; j++)
        if (Solve(j, i, Q + 1) < LB[j]) Flag = false;
      if (!Flag) break;
      Q++;
    }
    L[i] = P;
    R[i] = Q;
  }
  static Suffix Data[50000];
  for (int i = 0; i < Len0; i++) Data[i] = (Suffix){0, i};
  sort(Data, Data + Len0);
  long long Ans = 0;
  for (int i = 0; i < Len0; i++) {
    int Min = L[Data[i].X], Max = R[Data[i].X];
    Min = max(Min, Data[i].X);
    Max = min(Max, Len0 - 1);
    if (i) Min = max(Min, Data[i].X + LCP(Data[i], Data[i - 1]));
    Ans += max(Max - Min + 1, 0);
  }
  cout << Ans << endl;
  return 0;
}
