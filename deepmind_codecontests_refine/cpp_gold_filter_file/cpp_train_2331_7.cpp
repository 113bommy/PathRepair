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
int main() {
  int N = Get();
  static int A[1000];
  for (int i = 0; i < N * 2 - 1; i++) A[i] = Get();
  sort(A, A + N * 2 - 1);
  if (N & 1)
    for (int i = 0; i < N * 2 - 1; i++) A[i] = abs(A[i]);
  else
    for (int i = 0; i + 1 < N * 2 - 1; i += 2)
      if (A[i] + A[i + 1] <= 0) {
        A[i] = -A[i];
        A[i + 1] = -A[i + 1];
      }
  int Ans = 0;
  for (int i = 0; i < N * 2 - 1; i++) Ans += A[i];
  Output(Ans);
  return 0;
}
