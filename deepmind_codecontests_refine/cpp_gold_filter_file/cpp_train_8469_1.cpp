#include <bits/stdc++.h>
using namespace std;
int Get() {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  int X = 0;
  while (c >= '0' && c <= '9') {
    X = X * 10 + c - 48;
    c = getchar();
  }
  return X;
}
void Output(int X) {
  int Len = 0, Data[20];
  while (X) {
    Data[Len++] = X % 10;
    X /= 10;
  }
  if (!Len) Data[Len++] = 0;
  while (Len--) putchar(Data[Len] + 48);
  putchar('\n');
}
int main() {
  string S;
  cin >> S;
  int N = S.size();
  static int DP[5000][5000];
  for (int i = 0; i < N; i++) DP[i][i] = 1;
  for (int i = 1; i < N; i++) DP[i - 1][i] = (S[i - 1] == S[i]);
  for (int Len = 2; Len < N; Len++)
    for (int i = 0, j = Len; j < N; i++, j++)
      DP[i][j] = (S[i] == S[j]) && DP[i + 1][j - 1];
  for (int Len = 1; Len < N; Len++)
    for (int i = 0, j = Len; j < N; i++, j++)
      DP[i][j] += DP[i + 1][j] + DP[i][j - 1] - DP[i + 1][j - 1];
  int Query = Get();
  while (Query--) {
    int L = Get() - 1, R = Get() - 1;
    Output(DP[L][R]);
  }
  return 0;
}
