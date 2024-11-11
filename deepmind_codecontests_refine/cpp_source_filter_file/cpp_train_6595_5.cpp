#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2000005;
int N, R, MSol, Sol;
char Move[2] = {'T', 'B'}, String[MaxN];
int GCD(int X, int Y, int M) {
  if (X == 1 && Y == 0) return M == N ? 0 : N + 1;
  if (Y == 0) return N + 1;
  M += X / Y;
  return (X / Y - 1) - (Y == 1) + GCD(Y, X % Y, M);
}
void BuildS(int X, int Y, int M) {
  if (X == 1 && Y == 0) {
    return;
  }
  BuildS(Y, X % Y, M ^ 1);
  int i = 0;
  if (Y == 1) {
    String[N++] = Move[M ^ 1];
    ++i;
  }
  for (; i < X / Y; ++i) String[N++] = Move[M];
}
void Solve() {
  Sol = N + 1;
  if (R == 1 && N == 1) {
    String[0] = 'T';
    Sol = 0;
    return;
  }
  for (int M = 0; M <= R; ++M)
    if (GCD(R, M, 0) < Sol) Sol = GCD(R, M, 0), MSol = M;
  if (Sol > N) {
    Sol = -1;
    return;
  }
  N = 0;
  BuildS(R, MSol, 0);
  if (String[0] != 'T') {
    N = 0;
    BuildS(R, MSol, 1);
  }
}
void Read() { scanf("%d %d", &N, &R); }
void Print() {
  if (Sol == -1) {
    printf("IMPOSSIBLE\n");
    return;
  }
  printf("%d\n%s\n", Sol, String);
}
int main() {
  Read();
  Solve();
  Print();
  return 0;
}
