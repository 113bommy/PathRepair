#include <bits/stdc++.h>
using namespace std;
long long N, A[1000001], Dp[1000001], E[100001];
inline long long Read() {
  register long long Return(0), Flag(0);
  register char C(getchar());
  for (; !isdigit(C); C = getchar()) Flag ^= !(C ^ 45);
  for (; isdigit(C); C = getchar())
    Return = (Return << 1) + (Return << 3) + (C ^ '0');
  if (Flag) Return = -Return;
  return Return;
}
inline void Write(long long X) {
  if (X < 0) X = -X, putchar('-');
  if (X > 9) Write(X / 10);
  putchar(X % 10 ^ 48);
}
signed main(void) {
  ios::sync_with_stdio(false);
  register long long Case(Read());
  while (Case--) {
    register long long i;
    N = Read();
    for (i = 1; i <= N + 5; i++) Dp[i] = E[i] = 0;
    Dp[0] = 1;
    for (i = 1; i <= N; i++) A[i] = Read();
    register long long Ret(0);
    for (i = 1; i <= N; i++) {
      Ret += E[A[i]] + E[A[i] + 2];
      if (A[i]) Ret += Dp[A[i] - 1];
      Ret %= 998244353;
      E[A[i]] = 2 * E[A[i]];
      E[A[i] + 2] = 2 * E[A[i] + 2];
      if (A[i]) E[A[i]] += Dp[A[i] - 1];
      E[A[i]] %= 998244353;
      E[A[i] + 2] %= 998244353;
      if (!A[i])
        Ret += Dp[0] + Dp[1], Ret %= 998244353;
      else
        Ret += Dp[A[i] + 1] + Dp[A[i]], Ret %= 998244353;
      Dp[A[i] + 1] = Dp[A[i] + 1] * 2 + Dp[A[i]], Dp[A[i] + 1] %= 998244353;
    }
    Write(Ret), putchar('\n');
  }
  return 0;
}
