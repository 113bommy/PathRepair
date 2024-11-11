#include <bits/stdc++.h>
const int MaxN = 30;
int N, A[MaxN];
int NumAns, Ans[1100000][2];
void Push(int a, int b, int Cnt) {
  for (register int i = 1; i <= Cnt; i++) {
    ++NumAns;
    Ans[NumAns][0] = a;
    Ans[NumAns][1] = b;
  }
}
void Dp(int i, int a, int b, int c, bool ord) {
  if (i == N + 1) return;
  int j;
  for (j = i; j <= N && A[j] == A[i]; j++)
    ;
  int Cnt = j - i;
  if (j == N + 1 && ord) {
    Push(a, b, Cnt - 1);
    Push(a, c, 1);
    Push(b, c, Cnt - 1);
    return;
  }
  if (j == i + 1 || !ord) {
    Dp(j, a, c, b, 0);
    Push(a, c, Cnt);
    Dp(j, b, a, c, 0);
  } else {
    Dp(j, a, b, c, 0);
    Push(a, b, Cnt);
    Dp(j, c, a, b, 0);
    Push(b, c, Cnt);
    Dp(j, a, b, c, 1);
  }
}
int main() {
  scanf("%d", &N);
  for (register int i = 1; i <= N; i++) scanf("%d", &A[i]);
  Dp(1, 1, 2, 3, 1);
  printf("%d\n", NumAns);
  for (register int i = 1; i <= NumAns; i++)
    printf("%d %d\n", Ans[i][0], Ans[i][1]);
  return 0;
}
