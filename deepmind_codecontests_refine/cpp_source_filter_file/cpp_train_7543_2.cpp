#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100010;
int N, A[NMAX], Freq[NMAX], Pref, Suf;
bool Palindrome(int Left, int Right) {
  while (Left <= Right) {
    if (A[Left] != A[Right]) return 0;
    Left++;
    Right--;
  }
  return 1;
}
bool PossiblePalindrome() {
  int CntNegative = 0, CntOdd = 0;
  for (int i = 1; i <= N; ++i) {
    CntNegative += (Freq[i] < 0);
    CntOdd += (Freq[i] % 2 == 1);
  }
  if (CntNegative > 0 || CntOdd > 1) return 0;
  return 1;
}
int Solve(int Left, int Right) {
  int St = Left, Dr = Right, X, Y, Ans;
  while (St <= Dr) {
    X = (St + Dr) / 2;
    Y = Dr - (X - St);
    bool Good = 0;
    if (Palindrome(X + 1, Y - 1)) {
      memset(Freq, 0, sizeof(Freq));
      for (int i = Left; i <= X; ++i) Freq[A[i]]++;
      for (int i = max(X + 1, Y); i <= Right; ++i) Freq[A[i]]--;
      Good |= PossiblePalindrome();
    }
    if (Good)
      Ans = X - Left + 1, Dr = X - 1;
    else
      St = X + 1;
  }
  return Ans;
}
int main() {
  scanf("%i", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%i", &A[i]);
    Freq[A[i]]++;
  }
  if (Palindrome(1, N)) {
    printf("%I64d\n", (1LL * N * (N + 1)) / 2);
    return 0;
  }
  if (PossiblePalindrome() == 0) {
    printf("0\n");
    return 0;
  }
  int Left = 1, Right = N, L;
  while (Left <= Right && A[Left] == A[Right]) Left++, Right--;
  L = Right - Left + 1;
  Pref = Solve(Left, Right);
  reverse(A + 1, A + N + 1);
  Suf = Solve(Left, Right);
  long long Ans = (N - L) / 2 + 1;
  Ans *= ((N - L) / 2 + 1 + 2 * L - Pref - Suf);
  printf("%I64d\n", Ans);
}
