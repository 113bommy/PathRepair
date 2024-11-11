#include <bits/stdc++.h>
const long long Infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 100005;
int N, K;
long long A[MN], D[MN], Ans;
long long Z[MN];
int main() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
  for (int i = 1; i <= N; ++i) scanf("%lld", &D[i]);
  if (K == 0) {
    long long S = 0;
    for (int i = N; i >= 1; --i) S += A[i], Ans = std::max(Ans, S - D[i]);
  } else if (K >= 2) {
    Ans = std::max(Ans, A[N] - D[N]);
    Ans = std::max(Ans, std::accumulate(A + 1, A + N + 1, 0) -
                            *std::min_element(D + 1, D + N));
  } else {
    long long S = 0;
    for (int i = N; i >= 2; --i)
      S += A[i], Ans = std::max(Ans, S - D[i]), Z[i] = Ans;
    S += A[1];
    Ans = std::max(Ans, S - *std::min_element(A + 2, A + N + 1) - D[1]);
    Ans = std::max(Ans, S - D[1] - *std::min_element(D + 2, D + N + 1));
    S = 0;
    long long Mn = Infll;
    for (int i = 1; i < N; ++i)
      Mn = std::min(Mn, D[i]), S += A[i],
      Ans = std::max(Ans, S - Mn + Z[i + 1]);
    S += A[N];
    std::sort(D + 1, D + N + 1);
    Ans = std::max(Ans, S - D[1] - D[2]);
  }
  printf("%lld\n", Ans);
  return 0;
}
