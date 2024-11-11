#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
vector<int> A[2];
int N, M, T, C[(101)][(101)], x;
int gt(vector<int> &A) {
  if (A.empty()) return 0;
  int a = A.back();
  A.pop_back();
  return a;
}
int main(void) {
  scanf("%d%d%d", &T, &N, &M);
  for (int k(1); k < T + 1; k++) A[k & 1].push_back(k);
  for (int i(0); i < N; i++) {
    x ^= 1;
    for (int j(0); j < M; j++) C[i][j] = gt(A[x ^ (j & 1)]);
  }
  if (!A->empty() || !A[1].empty()) return puts("-1"), 0;
  for (int i(0); i < N; i++)
    for (int j(0); j < M; j++) printf("%d%c", C[i][j], j + 1 == M ? 10 : 32);
  return 0;
}
