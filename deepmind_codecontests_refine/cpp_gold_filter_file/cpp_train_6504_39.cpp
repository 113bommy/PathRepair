#include <bits/stdc++.h>
using namespace std;
int N;
int A[4155];
int MaxP;
int Path[4155];
int GetMax(int Q, int D) {
  if (D == N) return A[Q];
  Path[Q * 2] = GetMax(Q * 2, D + 1);
  Path[Q * 2 + 1] = GetMax(Q * 2 + 1, D + 1);
  return A[Q] + max(Path[Q * 2], Path[Q * 2 + 1]);
}
int Solve(int Q, int D, int P) {
  if (D == N + 1) return 0;
  int ToPut = MaxP - (max(Path[Q * 2], Path[Q * 2 + 1]) + P);
  return ToPut + Solve(Q * 2, D + 1, P + ToPut + A[Q * 2]) +
         Solve(Q * 2 + 1, D + 1, P + ToPut + A[Q * 2 + 1]);
}
int main() {
  scanf("%d", &N);
  for (int i = 2; i < (1 << N + 1); i++) scanf("%d", &A[i]);
  MaxP = GetMax(1, 0);
  printf("%d\n", Solve(1, 0, 0));
}
