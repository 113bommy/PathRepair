#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
int N, M, W, a, b, I, J;
pair<int, int> A[(1 << 18)], B[(1 << 18)];
long long S, T, G;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first ^ b.first ? a.first > b.first : a.second < b.second;
}
int main(void) {
  scanf("%d%d%d", &N, &M, &W);
  for (int i(0); i < N; i++) scanf("%d%d", &a, &b), A[i] = {a, b};
  for (int i(0); i < M; i++) scanf("%d%d", &a, &b), B[i] = {a, b};
  sort(A, A + N, cmp), sort(B, B + M, cmp);
  while (I < N && T + A[I].second <= W) T += A[I++].second, G += A[I - 1].first;
  while (~--I) {
    while (J < M && T + B[J].second <= W)
      T += A[J++].second, G += B[J - 1].first;
    if (J) S = max(S, G);
    T -= A[I].second, G -= A[I].first;
  }
  printf("%lld\n", S);
  return 0;
}
