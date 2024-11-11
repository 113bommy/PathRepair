#include <bits/stdc++.h>
using namespace std;
int N, Ans, A[25][25], B[25][25], w[25][25];
int Tim, LA[25], LB[25], VA[25], VB[25], QA[25], QB[25], Mat[25], Suf[25];
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
bool Find(int u) {
  VA[u] = Tim;
  for (int i = 1; i <= N; i++)
    if (VB[i] != Tim && LA[u] + LB[i] == w[u][i]) {
      VB[i] = Tim;
      if (!Mat[i] || Find(Mat[i])) {
        Mat[i] = u;
        return 1;
      }
    }
  return 0;
}
void Change() {
  int Min = 1 << 30;
  *QA = *QB = 0;
  for (int i = 1; i <= N; i++)
    if (VA[i] == Tim) QA[++*QA] = i;
  for (int i = 1; i <= N; i++)
    if (VB[i] != Tim) QB[++*QB] = i;
  for (int i = 1; i <= *QA; i++)
    for (int j = 1; j <= *QB; j++)
      Min = min(Min, LA[QA[i]] + LB[QB[j]] - w[QA[i]][QB[j]]);
  for (int i = 1; i <= N; i++) {
    if (VA[i] == Tim) LA[i] -= Min;
    if (VB[i] == Tim) LB[i] += Min;
  }
}
int KM(int s) {
  for (int i = 1; i <= N; i++) {
    int Now = 0;
    for (int j = 1; j <= N; j++) Now += w[Mat[j]][j];
    if (Now + Suf[i] <= Ans) return 0;
    for (int j = 1; j <= N; j++)
      w[i][j] = ((1 << i - 1) & s) ? A[i][j] : B[i][j];
    for (;;) {
      Tim++;
      if (Find(i)) break;
      Change();
    }
  }
  int ret = 0;
  for (int i = 1; i <= N; i++) ret += w[Mat[i]][i];
  return ret;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      scanf("%d", &A[i][j]), A[i][0] = max(A[i][0], A[i][j]);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      scanf("%d", &B[i][j]), B[i][0] = max(B[i][0], B[i][j]);
  int U = (1 << N) - 1;
  for (int s = 0; s <= U; s++) {
    int t = 0;
    for (int i = 1; i <= N; i++)
      if ((1 << i - 1) & s) t++;
    if (t != N / 2) continue;
    for (int i = 1; i <= N; i++)
      LA[i] = ((1 << i - 1) & s) ? A[i][0] : B[i][0], Suf[i] = LA[i],
      LB[i] = Mat[i] = 0;
    ;
    for (int i = N - 1; i; i--) Suf[i] += Suf[i + 1];
    Ans = max(Ans, KM(s));
    if (clock() / (double)(CLOCKS_PER_SEC) >= 1.7) break;
  }
  printf("%d\n", Ans);
}
