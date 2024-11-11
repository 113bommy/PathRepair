#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
bool ip(int x, int y, int X, int Y) {
  printf("? %d %d %d %d\n", x + 1, y + 1, X + 1, Y + 1), fflush(stdout);
  assert(x <= X && y <= Y && x + y + 2 <= X + Y);
  int _;
  scanf("%d", &_);
  return _;
}
int N, A[51][51];
void sp(int x, int y, int X, int Y) {
  if (~A[X][Y]) return;
  A[X][Y] = A[x][y] ^ !ip(x, y, X, Y);
}
void iv() {
  for (int i(0); i < N; i++)
    for (int j(0); j < N; j++)
      if ((i + j) & 1) A[i][j] ^= 1;
}
bool pa(int x, int y) {
  return (A[x][y] == A[x + 1][y + 2]) &&
         (A[x][y + 1] != A[x + 1][y] || A[x][y + 1] == A[x][y + 2] ||
          A[x][y + 2] != A[x + 1][y + 1]);
}
bool pb(int x, int y) {
  return (A[x][y] == A[x + 2][y + 1]) &&
         (A[x + 1][y] != A[x][y + 1] || A[x + 1][y] == A[x + 2][y] ||
          A[x + 2][y] != A[x + 1][y + 1]);
}
bool ia(int x, int y) {
  iv();
  bool z = pa(x, y);
  iv();
  return z;
}
bool ib(int x, int y) {
  iv();
  bool z = pb(x, y);
  iv();
  return z;
}
int main(void) {
  (memset(A, -1, sizeof(A))), **A = 1, scanf("%d", &N), A[N - 1][N - 1] = 0;
  sp(0, 0, 0, 2), sp(0, 0, 1, 1), sp(0, 0, 2, 0), sp(1, 1, 2, 2);
  A[0][1] = 1;
  A[1][2] = ip(0, 1, 1, 2);
  A[1][0] = A[1][2] ^ !ip(1, 0, 1, 2);
  A[2][1] = ip(0, 1, 2, 1);
  for (int i(0); i < N; i++)
    for (int j(0); j < N; j++)
      if (i > 1)
        sp(i - 2, j, i, j);
      else if (j > 1)
        sp(i, j - 2, i, j);
  for (int i(0); i < N - 1; i++)
    for (int j(0); j < N - 2; j++)
      if (pa(i, j) ^ ia(i, j)) {
        if (pa(i, j) ^ ip(i, j, i + 1, j + 2)) iv();
        goto GOW;
      }
  for (int i(0); i < N - 2; i++)
    for (int j(0); j < N - 1; j++)
      if (pb(i, j) ^ ib(i, j)) {
        if (pb(i, j) ^ ip(i, j, i + 2, j + 1)) iv();
        goto GOW;
      }
  assert(0);
GOW:
  puts("!");
  for (int i(0); i < N; i++) {
    for (int j(0); j < N; j++) printf("%d", A[i][j]);
    puts("");
  }
  fflush(stdout);
  return 0;
}
