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
void Get(long long &T) {
  char C;
  bool F = 0;
  for (; C = getchar(), C < '0' || C > '9';)
    if (C == '-') F = 1;
  for (T = C - '0'; C = getchar(), C >= '0' && C <= '9'; T = T * 10 + C - '0')
    ;
  F && (T = -T);
}
int N, M, P;
int A[20005];
int B[20005];
long long F[25005];
int IDA[20005];
int IDB[20005];
long long FA[145][20005];
long long FB[145][20005];
int SqrtN;
int SqrtM;
void Init() {
  Get(N);
  Get(M);
  Get(P);
  SqrtN = floor(sqrtl(N));
  SqrtM = floor(sqrtl(M));
  for (int i = 0; i * SqrtN <= N; i++) IDA[i * SqrtN] = i + 1;
  for (int i = 0; i * SqrtM <= M; i++) IDB[i * SqrtM] = i + 1;
  for (int i = 1; i <= N; i++) Get(A[i]);
  for (int i = 1; i <= M; i++) Get(B[i]);
}
bool Ans[40005];
int AnsTop;
void Rebuild(int X, int Y) {
  if (X == 0 || Y == 0) return;
  int X0 = X - 1;
  int Y0 = Y - 1;
  for (; IDA[X0] == 0; X0--)
    ;
  for (; IDB[Y0] == 0; Y0--)
    ;
  for (int i = X0; i <= X; i++)
    for (int j = Y0; j <= Y; j++)
      F[(i - X0) * (Y - Y0 + 1) + (j - Y0)] = 0xc0c0c0c0c0c0c0c0ll;
  for (int j = Y0; j <= Y; j++) F[(j - Y0)] = FA[IDA[X0]][j];
  for (int i = X0; i <= X; i++) F[(i - X0) * (Y - Y0 + 1)] = FB[IDB[Y0]][i];
  for (int i = X0 + 1; i <= X; i++)
    for (int j = Y0 + 1; j <= Y; j++) {
      if (i > X0 && F[(i - X0) * (Y - Y0 + 1) + (j - Y0)] <
                        F[(i - X0 - 1) * (Y - Y0 + 1) + (j - Y0)])
        F[(i - X0) * (Y - Y0 + 1) + (j - Y0)] =
            F[(i - X0 - 1) * (Y - Y0 + 1) + (j - Y0)];
      if (j > Y0 && F[(i - X0) * (Y - Y0 + 1) + (j - Y0)] <
                        F[(i - X0) * (Y - Y0 + 1) + (j - Y0 - 1)])
        F[(i - X0) * (Y - Y0 + 1) + (j - Y0)] =
            F[(i - X0) * (Y - Y0 + 1) + (j - Y0 - 1)];
      F[(i - X0) * (Y - Y0 + 1) + (j - Y0)] += (A[i] + B[j]) % P;
    }
  for (int i = X, j = Y;;) {
    if (i == X0 || j == Y0) {
      Rebuild(i, j);
      break;
    }
    if (F[(i - X0 - 1) * (Y - Y0 + 1) + (j - Y0)] + (A[i] + B[j]) % P ==
        F[(i - X0) * (Y - Y0 + 1) + (j - Y0)]) {
      i--;
      Ans[++AnsTop] = 1;
    } else {
      j--;
      Ans[++AnsTop] = 0;
    }
  }
}
long long AnsF;
void Work() {
  fprintf(stderr, "%lf\n",
          (sizeof(FA) + sizeof(FB) + sizeof(IDA) + sizeof(IDB) + sizeof(A) +
           sizeof(B) + sizeof(F) + sizeof(N) + sizeof(M) + sizeof(Ans) +
           sizeof(AnsTop) + sizeof(P)) /
              1024 / 1024.);
  for (int i = 0; i <= M; i++) F[i] = 0xc0c0c0c0c0c0c0c0ll;
  F[1] = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i > 0 && j > 0) {
        if (F[j] < F[j - 1]) F[j] = F[j - 1];
        F[j] += (A[i] + B[j]) % P;
      }
      if (IDB[j] >= 1) FB[IDB[j]][i] = F[j];
      if (IDA[i] >= 1) FA[IDA[i]][j] = F[j];
    }
  }
  AnsF = F[M];
  Rebuild(N, M);
}
void Output() {
  printf("%I64d\n", AnsF);
  for (int i = AnsTop - 1; i >= 1; i--) printf(Ans[i] == 1 ? "C" : "S");
  puts("");
}
int main() {
  Init();
  Work();
  Output();
  return 0;
}
