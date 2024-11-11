#include <bits/stdc++.h>
using namespace std;
const int infinity = 1e9;
int N, M;
int A[509][509];
int P[509][509];
int squaresum(int cx, int cy, int k) {
  int ax = cx - k / 2;
  int ay = cy - k / 2;
  int bx = cx + k / 2;
  int by = cy + k / 2;
  return P[bx][by] - P[ax - 1][by] - P[bx][ay - 1] + P[ax - 1][ay - 1];
}
bool goodk(int i, int j, int k) {
  k /= 2;
  return ((i - k >= 1) && (i + k <= N) && (j - k >= 1) && (j + k <= M));
}
int main() {
  scanf("%d %d ", &N, &M);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + A[i][j];
  int ans = -infinity;
  for (int i = 2; i <= N - 1; i++)
    for (int j = 2; j <= M - 1; j++) {
      int spiral = A[i][j];
      for (int k = 3; goodk(i, j, k); k += 2) {
        spiral = squaresum(i, j, k) - spiral - A[i - k / 2 + 1][j - k / 2];
        ans = max(ans, spiral);
      }
    }
  printf("%d\n", ans);
  return 0;
}
