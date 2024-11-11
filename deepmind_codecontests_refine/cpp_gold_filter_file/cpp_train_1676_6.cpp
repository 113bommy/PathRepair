#include <bits/stdc++.h>
using namespace std;
int dp[20010][2];
int ins[20010][2];
int p;
int X[20010];
int Y[20010];
int sol[20010];
int T;
int b;
inline int f(int i, int j) { return (X[i] + Y[j]) % p; }
void compute(int si, int sj, int ei, int ej) {
  if (si > ei || sj > ej) return;
  if (si == ei && ej == sj) {
    if (!b) {
      printf("%d\n", f(si, sj));
      b = 1;
    }
    return;
  }
  if ((ei - si + 1) * (ej - sj + 1) == 2) {
    if (!b) {
      printf("%d\n", f(si, sj) + f(ei, sj));
      b = 1;
    }
    sol[T++] = si;
    return;
  }
  int i, ss, mx, j;
  ss = ei + ej;
  mx = (ss + si + sj) / 2;
  for (i = si; i <= ei + 1; ++i) dp[i][ss & 1] = -(1LL << 30);
  dp[ei][ss & 1] = f(ei, ss - ei);
  for (; --ss >= mx;) {
    for (i = si; i <= ei + 1; ++i) dp[i][ss & 1] = -(1LL << 30);
    for (i = max(si, ss - ej); i <= ei && ss - i >= sj; ++i) {
      dp[i][ss & 1] =
          max(dp[i][(ss & 1) ^ 1], dp[i + 1][(ss & 1) ^ 1]) + f(i, ss - i);
    }
  }
  ++ss;
  for (i = si; i <= ei; ++i) ins[i][ss & 1] = i;
  for (; --ss >= (si + sj);) {
    for (i = si; i <= ei + 1; ++i) dp[i][ss & 1] = -(1LL << 30);
    for (i = max(si, ss - ej); i <= ei && ss - i >= sj; ++i) {
      if (dp[i][(ss & 1) ^ 1] > dp[i + 1][(ss & 1) ^ 1]) {
        dp[i][ss & 1] = dp[i][(ss & 1) ^ 1] + f(i, ss - i);
        ins[i][ss & 1] = ins[i][(ss & 1) ^ 1];
      } else {
        dp[i][ss & 1] = dp[i + 1][(ss & 1) ^ 1] + f(i, ss - i);
        ins[i][ss & 1] = ins[i + 1][(ss & 1) ^ 1];
      }
    }
  }
  ++ss;
  if (!b) {
    printf("%d\n", dp[si][ss & 1]);
    b = 1;
  }
  i = ins[si][ss & 1];
  j = mx - i;
  compute(si, sj, i, j);
  compute(i, j, ei, ej);
}
int N, M;
int main() {
  int i;
  scanf("%d%d%d", &N, &M, &p);
  for (i = 0; i < N; ++i) scanf("%d", &X[i]);
  for (i = 0; i < M; ++i) scanf("%d", &Y[i]);
  compute(0, 0, N - 1, M - 1);
  sol[T] = N - 1;
  for (i = 0; i < T; ++i) {
    printf("%c", (sol[i] == sol[i + 1]) ? 'S' : 'C');
  }
  return 0;
}
