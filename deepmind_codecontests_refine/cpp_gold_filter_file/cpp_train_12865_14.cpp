#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
int N, M, B[(100005)], b, e, d;
vector<int> A[(100005)], L[(100005)];
int main(void) {
  scanf("%d%d", &N, &M);
  for (int i(0); i < N; i++) L[i] = A[i] = vector<int>(M, 0);
  for (int i(0); i < N; i++)
    for (int j(0); j < M; j++) scanf("%d", &A[i][j]);
  for (int i = N - 1; ~i; --i)
    for (int j(0); j < M; j++)
      B[i] = max(B[i], L[i][j] = i + 1 == N               ? 1
                                 : A[i][j] <= A[i + 1][j] ? L[i + 1][j] + 1
                                                          : 1);
  int _;
  scanf("%d", &_);
  for (int i(0); i < _; i++)
    scanf("%d%d", &b, &e), d = e - --b, puts(B[b] >= d ? "Yes" : "No");
  return 0;
}
