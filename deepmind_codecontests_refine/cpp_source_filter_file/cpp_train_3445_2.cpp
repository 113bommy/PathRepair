#include <bits/stdc++.h>
using namespace std;
int N, M;
long long T[105][105], A[105], B[105];
long long AA, BB;
int main() {
  int i, j;
  scanf("%d %d", &N, &M);
  for (i = 1; i <= N; i++) scanf("%I64d", A + i), AA ^= A[i];
  for (i = 1; i <= M; i++) scanf("%I64d", B + i), BB ^= B[i];
  if (AA != BB) {
    puts("NO");
    return 0;
  }
  for (i = 1; i < N; i++)
    for (j = 1; j < M; j++) T[i][j] = 1;
  for (i = 1; i < N; i++) T[i][M] = A[i];
  for (i = 1; i < M; i++) T[N][i] = B[i];
  AA = 0;
  for (i = 1; i < N; i++) AA ^= A[i];
  T[N][M] = AA ^ B[M];
  puts("YES");
  for (i = 1; i <= N; i++, puts(""))
    for (j = 1; j <= M; j++) printf("%I64d ", T[i][j]);
  return 0;
}
