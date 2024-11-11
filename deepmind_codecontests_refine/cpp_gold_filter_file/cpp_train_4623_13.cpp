#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 5;
int N, M;
int X[MaxN], Y[MaxN];
int A[MaxN], B[MaxN];
long long Ans;
bool F0, F1, Tag;
int main() {
  int i, mx, my, dx, dy;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf("%d%d", &X[i], &Y[i]);
    A[i] = X[i], B[i] = Y[i];
  }
  sort(X + 1, X + N + 1);
  sort(Y + 1, Y + N + 1);
  M = N + 1 >> 1;
  mx = X[M], my = Y[M];
  dx = X[M + 1] - X[M], dy = Y[M + 1] - Y[M];
  if (N & 1) {
    dx = min(dx, X[M] - X[M - 1]);
    dy = min(dy, Y[M] - Y[M - 1]);
  }
  for (i = 1; i <= N; i++) {
    Ans += abs(X[i] - X[M]) + abs(Y[i] - Y[M]);
    F0 |= A[i] > mx && B[i] > my;
    F1 |= A[i] > mx && B[i] <= my;
    Tag |= A[i] == mx && B[i] == my;
  }
  if (F0 && F1 && (~N & 1 || Tag)) Ans -= min(dx, dy);
  printf("%I64d\n", Ans << 1);
  return 0;
}
