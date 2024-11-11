#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> A, B;
vector<long long> as, bs;
int main() {
  scanf("%d %d", &N, &M);
  A.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  B.resize(M);
  for (int i = 0; i < M; i++) {
    scanf("%d", &B[i]);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  as.resize(N);
  for (int i = 0; i < N; i++) {
    as[i] = A[i];
    if (i) as[i] += as[i - 1];
  }
  bs.resize(M);
  for (int i = 0; i < M; i++) {
    bs[i] = B[i];
    if (i) bs[i] += bs[i - 1];
  }
  long long ans = 1e18;
  for (int i = 0; i < N; i++) {
    if (bs.back() >= 1e18 / (N - i)) continue;
    ans = min(ans, (i == 0 ? 0 : as[i - 1]) + bs.back() * (N - i));
  }
  for (int i = 0; i < M; i++) {
    if (as.back() >= 1e18 / (N - i)) continue;
    ans = min(ans, (i == 0 ? 0 : bs[i - 1]) + as.back() * (M - i));
  }
  printf("%lld", ans);
}
