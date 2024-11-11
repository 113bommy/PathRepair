#include <bits/stdc++.h>
using namespace std;
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
const int Mod = 1000000007;
long long Pow(long long A, int B) {
  if (!B) return 1;
  long long T = Pow(A * A % Mod, B / 2);
  if (B & 1) T = T * A % Mod;
  return T;
}
int Solve(int N) {
  if (N <= 1) return 1;
  if (N == 2) return 2;
  long long S = 1, Ans = 1;
  for (int i = 1; i <= N / 2; i++) {
    S = S * (N - i * 2 + 2) % Mod * (N - i * 2 + 1) % Mod;
    S = S * Pow(i, Mod - 2) % Mod;
    if (S & 1) S += Mod;
    S /= 2;
    Ans = (Ans + S) % Mod;
  }
  return Ans;
}
int main() {
  int N = Get(), M = 0;
  for (int i = 0; i < N; i++) M += Get() & 1;
  long long Ans = Solve(M);
  for (int i = M + 1; i <= N; i++) Ans = Ans * i % Mod;
  Output(Ans);
  return 0;
}
